//
// Created by ljh on 2020/10/4.
//

#ifndef FINAL_EXTRACT_EXTRACT_H
#define FINAL_EXTRACT_EXTRACT_H

#include "opencv2/opencv.hpp"
// 加载tflite模型所需要的包
#include <tensorflow/lite/interpreter.h>
#include <tensorflow/lite/kernels/register.h>
#include <tensorflow/lite/model.h>
#include <iostream>

using namespace std;
using namespace tflite;
using namespace cv;

class Extract {
public:
    Extract(Mat im_input,const char* filename);
//    ~Extract();
    vector<float> _res;
};


#endif //FINAL_EXTRACT_EXTRACT_H
