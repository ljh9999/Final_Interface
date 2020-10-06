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
    cout << "终于成功了" << endl;
}

int main()
{
    Mat im;
    int res;
    im = cv::imread("0.jpg");

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
    // 在这儿，将模型参数param传递到了SVIP_AI_Action_Start当中
    SVIP_AI_Action_Start(APPLICATION_ACTION, CAMERA_SHELF_FRONT, param, 0, callback, nullptr, &ai_handle);
//    int SVIP_AI_Action_Start(ApplicationType application_type, CameraType camera_type, void *ai_params, int ai_params_size, svip_ai_result_cb cb, void *user, void **ai_handle)
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

    ActionAIFrame actionAiFrame;
    // 将前面的frameInfo给弄过来
    actionAiFrame.frame_info = &frameInfo;

    SVIP_AI_Action_SetFrame(ai_handle, (void*)&actionAiFrame);

    SVIP_AI_Action_InputFrame(ai_handle,md5_out,(void*)&actionAiFrame);
    SVIP_AI_Action_Stop(ai_handle);
    SVIP_AI_Action_Uninitialize();

//    auto extractor = new Extract(im, tfliteModel);

//    LogisticRegression lr;

    // 逻辑回归接口，加载模型
    // load_weights加载模型
    // lr.load_weights("model.txt");

//    res = lr.predict(extractor->_res);
//    cout << res <<endl;
    return 0;
}

