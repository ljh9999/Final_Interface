#include <iostream>
#include "Extract.h"
#include "LogisticRegression.h"
#include "svipAISDK_V3.h"
#include "md5.h"

using namespace std;

int callback(ApplicationType application_type,CameraType camera_type, void *ai_handle, void *ai_result, int ai_result_size, void *user)
{
    auto img = cv::imread("0.jpg");
    int cols = img.cols;
    int rows = img.rows;
    auto ActionAIResult = (ActionAIResult*) ai_result;

}

//todo
// 1, 不能一味的迎合修改，而是适合于我现在的代码，比如模型加载部分，也就是model.txt，要不要用一个类去封装，应该是不需要的。否则换来的还是折磨与重写
// 2，具体而言


int main()
{
    Mat im;
    char* tfliteModel;
    int res;
    im = cv::imread("0.jpg");
    tfliteModel = "pose.tflite";

    MD5_CTX _md5;
    void * ai_handle;
    SVIP_AI_Initialize();

    auto extractor = new Extract(im, tfliteModel);
    LogisticRegression lr;
    lr.load_weights("model.txt");
    res = lr.predict(extractor->_res);
    cout << res <<endl;
    return 0;
}

