import os
import numpy as np
import pandas as pd
from dtaidistance import dtw
from collections import defaultdict
from tensorflow.keras.preprocessing.sequence import pad_sequences
import pickle

def load_data(data_folder):
    data_dict = defaultdict(list)
    
    for filename in os.listdir(data_folder):
        if filename.endswith(".csv"):
            filepath = os.path.join(data_folder, filename)
            data = pd.read_csv(filepath)
            
            if {'yaw', 'pitch', 'roll'}.issubset(data.columns):
                stitch_type = filename.split('_')[1]  # Get the part after '_'
                stitch_type = ''.join(filter(lambda x: not x.isdigit(), stitch_type))  # Remove digits
            
                data_dict[stitch_type].append(data[['yaw', 'pitch', 'roll']].values)
            else:
                print(f"Warning: Skipping {filename}, missing required columns.")
    
    return data_dict

def create_dtw_templates(data_dict, target_length=20):
    templates = {}
    for stitch_type, sequences in data_dict.items():
        padded_sequences = []
        
        for seq in sequences:
            seq = np.array(seq)
            if len(seq) < target_length:
                seq = np.pad(seq, ((0, target_length - len(seq)), (0, 0)), mode='constant')
            else:
                seq = seq[:target_length]
                
            padded_sequences.append(seq)
        
        padded_sequences = np.array(padded_sequences)

        avg_sequence = np.mean(padded_sequences, axis=0)
        
        templates[stitch_type] = avg_sequence
    
    return templates

# Load data and create templates
data_folder = "data"
data_dict = load_data(data_folder)
templates = create_dtw_templates(data_dict)
with open('dtw_templates.pkl', 'wb') as f:
    pickle.dump(templates, f)