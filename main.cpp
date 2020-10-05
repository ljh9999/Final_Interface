#include <iostream>
#include "Extract.h"
#include "LogisticRegression.h"
#include "wrapper/svip_action.h"
#include "wrapper/svipAISDK_V3.h"
#include "md5.h"

using namespace std;

int callback(ApplicationType application_type,CameraType camera_type, void *ai_handle, void *ai_result, int ai_result_size, void *user)
{
    auto img = cv::imread("0.jpg");
    int cols = img.cols;
    int rows = img.rows;
    auto actionAIResult = (ActionAIResult*)ai_result;
    cout << actionAIResult->assist_action << endl;
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
    // 初始化 返回ok
    SVIP_AI_Action_Initialize();
    auto param = new ActionAIParam;
    param->Threshold = 0.9;
    param->motivation = 30;
    fstream file;
    file.open("model.txt", ios::binary | ios::in);
    if (file.is_open())
    {
        file.seekg(0, ios::end);
        uint length = file.tellg();
        file.seekg(0, ios::beg);
        auto data = new char[length];
        file.read(data, length);
        file.close();
        param->ai_module_data = data;
        param->ai_module_data_size = length;
    } else{
        cerr << "model file can't open" << endl;
        return -1;
    }

    SVIP_AI_Action_Start(APPLICATION_ACTION, CAMERA_SHELF_FRONT, param, 0, callback, nullptr, &ai_handle);
    FrameInfo frameInfo;
    auto filename = "000.jpg";
    auto img_ori = cv::imread(filename);

    cv::Mat yuv;
    cv::cvtColor(img_ori,yuv,cv::COLOR_BGR2YUV_I420);

    frameInfo.data = (unsigned char *)yuv.data;
    frameInfo.data_size = img_ori.cols * img_ori.rows  * 3 / 2;
    frameInfo.height = img_ori.rows;
    frameInfo.width = img_ori.cols;
    frameInfo.pixel_fmt = PIXEL_FMT_IYUV;

    char encrypt[50] = {};
    char decrypt[50] = {};
    sprintf(encrypt, "bandsoft_%d_%d_%ld", APPLICATION_ACTION, CAMERA_SHELF_FRONT, frameInfo.timestamp);
    MD5Init(&_md5);
    MD5Update(&_md5, reinterpret_cast<unsigned char *>(encrypt), strlen(encrypt));
    MD5Final(&_md5, reinterpret_cast<unsigned char *>(decrypt));
    char md5_out[33] = {0};
    int i;
    for (i = 0; i < 16; i++) {
        sprintf(md5_out + i + i, "%02x", decrypt[i]);
    }

//todo
// 1, 修改这个start的接口。。。
// 2,


    auto extractor = new Extract(im, tfliteModel);
    LogisticRegression lr;

    lr.load_weights("model.txt");
    res = lr.predict(extractor->_res);
    cout << res <<endl;
    return 0;
}

