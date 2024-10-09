import websocket
import serial
import time

def read_from_file():
    '''
    line_count = 0
    while True:
        if ser.in_waiting > 0:
            line = ser.readline().decode('utf-8').strip()  
            print(f"Received from Arduino: {line}")
            line_count += 1
            if line_count % 20 == 0:
                detect_movement(line)
        time.sleep(0.1)
    '''

def detect_movement(gyro_data):
    #print(f"Analyzing: {gyro_data}")
    movement_type = "ch" 
    send_to_parser(movement_type)

def send_to_parser(movement_type):
    try:
        ws = websocket.create_connection("ws://localhost:8080")
        ws.send(movement_type)
        ws.close()
    except Exception as e:
        print(f"WebSocket error: {e}")

if __name__ == "__main__":
    read_from_file()
