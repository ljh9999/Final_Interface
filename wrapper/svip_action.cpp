//
// Created by ljh on 2020/10/4.
//
#include <Extract.h>

#include <memory>
#include "svip_action.h"
#include "fstream"
#include "svipAISDK_V3.h"

svip_action::svip_action(char *model, int length) {
    // 这个函数的作用是对模型进行加密以及加载模型进行逻辑回归推理的地方
//    #define code 0x1d61b20
//    #define mask 0x1d0
//    long a = code;
//    long b = mask;
//
//    char* decrypt =&model[256] ;
//    for(int i = 0; i < 128; i++)
//    {
//        decrypt[i + a] ^= decrypt[i + b];
//    }
    fstream file;
    file.open(".model_temp",ios::out);
    if(file.is_open())
    {
        file.write(model,length);
        file.close();
    }
    lr = std::make_unique<LogisticRegression>();

    // 疑问，为什么这儿还是用的txt来进行的读取呢？
    lr->load_weights(".model_temp");

    remove(".model_temp");
}

int SVIP_AI_Action_Initialize()
{
    return SVIP_AI_OK;
}
int SVIP_AI_Action_Uninitialize()
{
    return SVIP_AI_OK;
}
int SVIP_AI_Action_Stop(void *ai_handle)
{
    delete (svip_action*) ai_handle;
    return SVIP_AI_OK;
}
int SVIP_AI_Action_Start(ApplicationType application_type, CameraType camera_type, void *ai_params, int ai_params_size, svip_ai_result_cb cb, void *user, void **ai_handle)
{
    auto param = (ActionAIParam*) ai_params;
    auto action_Ins = new svip_action(param->ai_module_data, param->ai_module_data_size);
    action_Ins -> _applicationType = application_type;
    action_Ins -> _cameraType = camera_type;
    action_Ins -> _cb = cb;
    action_Ins -> _conf = param->Threshold;
    action_Ins -> _motivation = param->motivation;
    *ai_handle = action_Ins;

    return SVIP_AI_OK;
}

int SVIP_AI_Action_InputFrame(void *ai_handle, const char *md5, void *ai_frame) {
    auto action_Ins = (svip_action*)ai_handle;
    auto actionAiFrame = (ActionAIFrame*)ai_frame;
    auto frame_info = actionAiFrame->frame_info;

    if(frame_info->pixel_fmt != PIXEL_FMT_IYUV) return SVIP_AI_ERR_PARAMETER;
    unsigned long long t = frame_info->timestamp;
    cv::Mat img;
    if(frame_info->data == nullptr)
    {
        cerr << "Input image is empty." << endl;
        return SVIP_AI_ERR_PARAMETER;
    }
    auto yuv = cv::Mat(frame_info->height * 3 / 2, frame_info->width, CV_8UC1, frame_info->data);

    cv::cvtColor(yuv, img, cv::COLOR_YUV2BGR_I420);
    int result;
    action_Ins->deal_frame(img, result);
    ActionAIResult actionAiResult;
    actionAiResult.assist_action = reinterpret_cast<AssistAction *>(result);

    cout << actionAiResult.assist_action << endl;

    return 0;
}

int SVIP_AI_Action_SetFrame(void *ai_handle, void *ai_frame) {
    return SVIP_AI_OK;
}

svip_action::~svip_action() {
    ;
}

int svip_action::deal_frame(cv::Mat img, int &result) {
    char* tfliteModel;
    tfliteModel = "pose.tflite";
    auto extractor = new Extract(img, tfliteModel);
    result = lr->predict(extractor->_res);

    return 0;
}


