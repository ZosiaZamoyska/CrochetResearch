#include <stdio.h>

#include "edge-impulse-sdk/classifier/ei_run_classifier.h"

// Callback function declaration
static int get_signal_data(size_t offset, size_t length, float *out_ptr);

// Raw features copied from test sample
static const float features[] = {
    // Copy raw features here (e.g. from the 'Model testing' page)
    -0.4503, -0.9606, 0.3102, -0.5601, -0.9124, 0.2309, -0.6881, -0.8656, 0.1381, -0.8286, -0.8251, 0.0344, -0.9747, -0.7959, -0.0773, -1.1192, -0.7829, -0.1936, -1.2551, -0.7903, -0.3111, -1.3762, -0.8213, -0.4264, -1.4777, -0.8781, -0.5364, -1.5564, -0.9615, -0.6386, -1.6111, -1.0707, -0.7305, -1.6422, -1.2182, -0.7963, -1.6532, -1.3882, -0.8467, -1.6485, -1.5740, -0.8827, -1.6339, -1.7674, -0.9063, -1.6159, -1.9588, -0.9203, -1.6012, -2.1383, -0.9277, -1.5959, -2.2959, -0.9317, -1.6052, -2.4224, -0.9354, -1.6330, -2.5098, -0.9411, -1.6811, -2.5517, -0.9506, -1.7493, -2.5577, -0.9518, -1.8366, -2.5140, -0.9564, -1.9397, -2.4185, -0.9661, -2.0544, -2.2706, -0.9832, -2.1759, -2.0707, -1.0106, -2.2994, -1.8199, -1.0518, -2.4207, -1.5203, -1.1115, -2.5371, -1.1740, -1.1951, -2.6472, -0.7832, -1.3092, -2.7518, -0.3502, -1.4610, -2.8535, 0.1099, -1.6461, -2.9572, 0.6070, -1.8832, -3.0693, 1.1420, -2.1821, -3.1968, 1.7170, -2.5526, -3.3471, 2.3348, -3.0037, -3.5269, 2.9985, -3.5433, -3.7415, 3.7113, -4.1773, -3.9943, 4.4757, -4.9091, -4.2857, 5.2933, -5.7391, -4.6131, 6.1641, -6.6645, -4.9695, 7.0736, -7.6671, -5.3467, 8.0292, -8.7478, -5.7324, 9.0275, -9.8962, -6.1122, 10.0639, -11.0999, -6.4702, 11.1326, -12.3456, -6.7900, 12.2270, -13.6195, -7.0555, 13.3397, -14.9076, -7.2522, 14.4632, -16.1968, -7.3683, 15.5896, -17.4752, -7.3949, 16.7112, -18.7325, -7.3267, 17.8080, -19.9494, -7.1633, 18.8842, -21.1291, -6.9082, 19.9358, -22.2690, -6.5686, 20.9603, -23.3692, -6.1548, 21.9570, -24.4314, -5.6802, 22.9259, -25.4592, -5.1593, 23.8685, -26.4567, -4.6077, 24.7867, -27.4285, -4.0407, 25.6824, -28.3785, -3.4723, 26.5578, -29.3096, -2.9144, 27.4029, -30.2138, -2.3769, 28.2277, -31.0988, -1.8666, 29.0333, -31.9640, -1.3872, 29.8204, -32.8071, -0.9395, 30.5887, -33.6252, -0.5218, 31.3374, -34.4143, -0.1303, 32.0648, -35.1700, 0.2400, 32.7686, -35.8880, 0.5950, 33.4457, -36.5640, 0.9406, 34.0928, -37.1949, 1.2815, 34.7009, -37.7723, 1.6218, 35.2708, -38.3004, 1.9640, 35.7998, -38.7804, 2.3085, 36.2859, -39.2150, 2.6541, 36.7279, -39.6088, 2.9977, 37.1258, -39.9670, 3.3346, 37.4804, -40.2959, 3.6588, 37.7933, -40.6018, 3.9639, 38.0673, -40.8906, 4.2428, 38.3056, -41.1675, 4.4880, 38.5127, -41.4335, 4.6943, 38.6918, -41.6928, 4.8568, 38.8468, -41.9458, 4.9724, 38.9816, -42.1908, 5.0394, 39.0992, -42.4242, 5.0577, 39.2022, -42.6405, 5.0287, 39.2921, -42.8326, 4.9555, 39.3698, -42.9923, 4.8420, 39.4349, -43.1107, 4.6931, 39.4864, -43.1789, 4.5111, 39.5305, -43.1886, 4.3039, 39.5577, -43.1321, 4.0774, 39.5644, -43.0036, 3.8372, 39.5464, -42.7994, 3.5881, 39.5000, -42.5183, 3.3346, 39.4217, -42.1617, 3.0801, 39.3094, -41.7340, 2.8270, 39.1619, -41.2423, 2.5772, 38.9800, -40.6960
};

int main(int argc, char **argv) {

    signal_t signal;            // Wrapper for raw input buffer
    ei_impulse_result_t result; // Used to store inference output
    EI_IMPULSE_ERROR res;       // Return code from inference

    // Calculate the length of the buffer
    size_t buf_len = sizeof(features) / sizeof(features[0]);

    // Make sure that the length of the buffer matches expected input length
    if (buf_len != EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE) {
        ei_printf("ERROR: The size of the input buffer is not correct.\r\n");
        ei_printf("Expected %d items, but got %d\r\n",
                EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE,
                (int)buf_len);
        return 1;
    }

    // Assign callback function to fill buffer used for preprocessing/inference
    signal.total_length = EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE;
    signal.get_data = &get_signal_data;

    // Perform DSP pre-processing and inference
    res = run_classifier(&signal, &result, false);

    // Print return code and how long it took to perform inference
    ei_printf("run_classifier returned: %d\r\n", res);
    ei_printf("Timing: DSP %d ms, inference %d ms, anomaly %d ms\r\n",
            result.timing.dsp,
            result.timing.classification,
            result.timing.anomaly);

    // Print the prediction results (object detection)
#if EI_CLASSIFIER_OBJECT_DETECTION == 1
    ei_printf("Object detection bounding boxes:\r\n");
    for (uint32_t i = 0; i < result.bounding_boxes_count; i++) {
        ei_impulse_result_bounding_box_t bb = result.bounding_boxes[i];
        if (bb.value == 0) {
            continue;
        }
        ei_printf("  %s (%f) [ x: %u, y: %u, width: %u, height: %u ]\r\n",
                bb.label,
                bb.value,
                bb.x,
                bb.y,
                bb.width,
                bb.height);
    }

    // Print the prediction results (classification)
#else
    ei_printf("Predictions:\r\n");
    for (uint16_t i = 0; i < EI_CLASSIFIER_LABEL_COUNT; i++) {
        ei_printf("  %s: ", ei_classifier_inferencing_categories[i]);
        ei_printf("%.5f\r\n", result.classification[i].value);
    }
#endif

    // Print anomaly result (if it exists)
#if EI_CLASSIFIER_HAS_ANOMALY
    ei_printf("Anomaly prediction: %.3f\r\n", result.anomaly);
#endif

#if EI_CLASSIFIER_HAS_VISUAL_ANOMALY
    ei_printf("Visual anomalies:\r\n");
    for (uint32_t i = 0; i < result.visual_ad_count; i++) {
        ei_impulse_result_bounding_box_t bb = result.visual_ad_grid_cells[i];
        if (bb.value == 0) {
            continue;
        }
        ei_printf("  %s (%f) [ x: %u, y: %u, width: %u, height: %u ]\r\n",
                bb.label,
                bb.value,
                bb.x,
                bb.y,
                bb.width,
                bb.height);
    }
    ei_printf("Visual anomaly values: Mean : %.3f Max : %.3f\r\n",
    result.visual_ad_result.mean_value, result.visual_ad_result.max_value);
#endif

    return 0;
}

// Callback: fill a section of the out_ptr buffer when requested
static int get_signal_data(size_t offset, size_t length, float *out_ptr) {
    for (size_t i = 0; i < length; i++) {
        out_ptr[i] = (features + offset)[i];
    }

    return EIDSP_OK;
}
