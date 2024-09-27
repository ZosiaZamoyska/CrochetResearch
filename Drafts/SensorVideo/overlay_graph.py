import cv2
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import tempfile
import os

def create_plot_image(pitch, roll, frame_idx):
    plt.figure(figsize=(4, 3))
    plt.plot(pitch[max(0, frame_idx+1-50):frame_idx+1], label='Pitch')
    plt.plot(roll[max(0, frame_idx+1-50):frame_idx+1], label='Roll')
    plt.xlabel('Frame Index')
    plt.ylabel('Value')
    plt.legend()
    plt.tight_layout()
    
    temp_file = tempfile.NamedTemporaryFile(delete=False, suffix='.png')
    try:
        plt.savefig(temp_file.name)
        plt.close()
    
        plot_image = cv2.imread(temp_file.name)
    finally:
        temp_file.close()
        os.unlink(temp_file.name)
    
    return plot_image

def overlay_plot_on_video(video_path, csv_path, output_path):

    data = pd.read_csv(csv_path)
    pitch = data['pitch'].values
    roll = data['roll'].values

    cap = cv2.VideoCapture(video_path)
    frame_width = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
    frame_height = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
    fps = cap.get(cv2.CAP_PROP_FPS)
    
    data_interval = 0.111784585  # 100 ms X - I binary searched it by hand but it's still not perfect. 
    # I think arduino communication was not clear / perfect

    frames_per_data_point = int(fps * data_interval)

    fourcc = cv2.VideoWriter_fourcc(*'mp4v')
    out = cv2.VideoWriter(output_path, fourcc, fps, (frame_width, frame_height))

    frame_idx = 0# -100
    data_idx = 0
    frame_delay = 10
    while cap.isOpened():
        ret, frame = cap.read()
        print(frame_idx)
        if not ret:
            break

        if frame_idx>=0 and frame_idx % frames_per_data_point == 0 and data_idx < len(pitch):
            plot_image = create_plot_image(pitch, roll, data_idx)
            data_idx += 1
        elif frame_idx < 0:
            plot_image = create_plot_image(pitch, roll, data_idx)

        
        # Resize plot image to fit the frame
        plot_image_resized = cv2.resize(plot_image, (frame_width // 3, frame_height // 3))

        x_offset = frame_width - plot_image_resized.shape[1] - 10
        y_offset = frame_height - plot_image_resized.shape[0] - 10
        
        frame[y_offset:y_offset+plot_image_resized.shape[0], x_offset:x_offset+plot_image_resized.shape[1]] = plot_image_resized

        out.write(frame)
        frame_idx += 1

    cap.release()
    out.release()
    cv2.destroyAllWindows()

video_path = 'video_single.mp4'  # Video Path
csv_path = 'ypr_single.csv'  # CSV file
output_path = 'output_video_with_graph.mp4'  # Path to the output

overlay_plot_on_video(video_path, csv_path, output_path)
