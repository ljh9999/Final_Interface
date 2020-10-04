//
// Created by ljh on 2020/10/4.
//

#include "Extract.h"

Extract::Extract(Mat im_input, const char *filename) {
    Mat im_resize;
    //const char* filename = "/home/ljh/Documents/action_detect/demo/model/pose.tflite";
    std::unique_ptr<tflite::FlatBufferModel> model = tflite::FlatBufferModel::BuildFromFile(filename);
    // Build the interpreter
    if (model != nullptr)
    {
        cout << "load model success.." << endl;
    }
    tflite::ops::builtin::BuiltinOpResolver resolver;
    std::unique_ptr<Interpreter> interpreter;
    InterpreterBuilder(*model, resolver)(&interpreter);
    //im_input = imread(in);
    cv::resize(im_input, im_resize, Size(192,192), 3);

    float im_ex[1][192][192][3];
    for(int i = 0; i < 192; ++i)
        for(int j = 0; j < 192; ++j)
            for(int k = 0; k < 3; ++k)
                im_ex[0][i][j][k] = im_resize.at<Vec3b>(i,j)[k];

    // Resize input tensors, if desired.
    interpreter->AllocateTensors();

    int input_tensor_idx = 0;
    int input = interpreter->inputs()[input_tensor_idx];
    float* input_data_ptr = interpreter->typed_tensor<float>(input);
    for(int i = 0; i < 192; ++i)
        for(int j = 0; j < 192; ++j)
            for(int k = 0; k < 3; ++k)
            {
                *(input_data_ptr) = (float)im_resize.at<Vec3b>(i,j)[k];
                input_data_ptr++;
            }
    interpreter->Invoke();

    int output_tensor_idx = 0;
    int output = interpreter->outputs()[output_tensor_idx];
    float* output_data_ptr = interpreter->typed_tensor<float>(output);

    float output_resize[1][96*96][14];
    for(int i = 0; i < 96*96; i++)
        for (int j = 0; j < 14; j++) {
            output_resize[0][i][j] = *output_data_ptr;
            output_data_ptr++;
        }
    float max = 0;
    long max_index[14];
    for(int i = 0; i < 14; i++) {
        for (int j = 0; j < 96 * 96; j++) {
            if (output_resize[0][j][i] > max){
                max_index[i] = j;
                max = output_resize[0][j][i];
            }
        }
        max = 0;
    }
//    int** res = new int*[28];
//    for (int i = 0; i < 28; i++){
//        res[i] = new int [1];
//    }
//    for (int i = 0; i < 14; i++){
//        res[i*2][0] = int(max_index[i]/96);
//        res[2*i+1][0] = max_index[i] % 96;
//    }
    for (int i = 0; i < 14; i++){
        _res.push_back(int(max_index[i]/96));
        _res.push_back(max_index[i] % 96);
    }
    for ( auto i : _res)
    {
        cout << i << endl;
    }

}
