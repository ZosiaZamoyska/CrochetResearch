import pickle
import numpy as np
from dtaidistance import dtw
import serial
import time
from scipy.interpolate import interp1d
from scipy.spatial.distance import euclidean
from fastdtw import fastdtw

# Load the DTW templates
with open('dtw_templates.pkl', 'rb') as f:
    dtw_templates = pickle.load(f)

# Serial setup (example, replace with your actual setup)
ser = serial.Serial('/dev/cu.usbserial-110', baudrate=115200, timeout=1)

buffer_size = 20
data_buffer = []


def calculate_dtw(x, y):
    distance, path = fastdtw(x, y, dist=euclidean)
    return distance

def preprocess_data(line):
    """Convert received line to numpy array of yaw, pitch, roll."""
    yaw, pitch, roll = map(float, line.split(','))
    return np.array([yaw, pitch, roll])

def interpolate_data(data, target_length):
    """Interpolate the data to the target length."""
    x = np.linspace(0, 1, len(data))
    f_yaw = interp1d(x, data[:, 0], kind='linear')
    f_pitch = interp1d(x, data[:, 1], kind='linear')
    f_roll = interp1d(x, data[:, 2], kind='linear')
    
    x_new = np.linspace(0, 1, target_length)
    interpolated_data = np.array([
        f_yaw(x_new),
        f_pitch(x_new),
        f_roll(x_new)
    ]).T  # Transpose to get the shape (target_length, 3)
    
    return interpolated_data

def normalize(data):
    data_mean = np.mean(data, axis=0)
    data_std = np.std(data, axis=0)
    
    # Avoid division by zero
    data_std[data_std == 0] = 1
    normalized_data = (data - data_mean) / data_std
    
    return normalized_data


def detect_movement(buffer):
    """Detect movement based on the buffered data."""
    # Convert buffer to a 2D array for DTW
    incoming_data = np.array(buffer)

    # Set target_length based on your DTW templates
    target_length = next(iter(dtw_templates.values())).shape[0]  # Assumes all templates are the same length
    interpolated_data = interpolate_data(incoming_data, target_length)

    # Normalize the incoming data and templates
    interpolated_data = normalize(interpolated_data)

    min_distance = float('inf')
    predicted_stitch = None

    for stitch_type, template in dtw_templates.items():
        template = np.array(template)
        template = normalize(template)

        #print(f"Interpolated data shape: {interpolated_data.shape}")
        #print(f"Template shape for {stitch_type}: {template.shape}")

        # Check if shapes are compatible
        if interpolated_data.shape[1] != template.shape[1]:
            print(f"Shape mismatch: incoming {interpolated_data.shape} vs template {template.shape}")
            continue

        # Check for NaN values
        if np.any(np.isnan(interpolated_data)) or np.any(np.isnan(template)):
            print(f"NaN detected in data or template.")
            continue
        
        try:
            # Ensure both arrays are of type float64
            distance = calculate_dtw(interpolated_data.astype(np.float64), template.astype(np.float64))
            #print(f"Distance to {stitch_type}: {distance}")

            if distance < min_distance:
                min_distance = distance
                predicted_stitch = stitch_type
        except ValueError as e:
            print(f"ValueError calculating distance for {stitch_type}: {e}")
        except Exception as e:
            print(f"Unexpected error calculating distance for {stitch_type}: {e}")

    print(f"Detected stitch type: {predicted_stitch} with distance: {min_distance}")

def read_from_arduino():
    line_count = 0
    while True:
        if ser.in_waiting > 0:
            line = ser.readline().decode('utf-8').strip()
            #print(f"Received from Arduino: {line}")
            line_count += 1
            
            data_buffer.append(preprocess_data(line))
            
            if line_count % buffer_size == 0:
                detect_movement(data_buffer)
                data_buffer.clear()  # Clear the buffer for the next set of readings
        time.sleep(0.1)

# Start reading from Arduino
read_from_arduino()
