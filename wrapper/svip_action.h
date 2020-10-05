//
// Created by ljh on 2020/10/4.
//

#ifndef FINAL_INTERFACE_SVIP_ACTION_H
#define FINAL_INTERFACE_SVIP_ACTION_H
#include <opencv2/opencv.hpp>
#include "svipAISDK_V3.h"
#include <vector>
#include "md5.h"
#include "LogisticRegression.h"
using namespace std;
class svip_action {
public:
    svip_action(char* model, int length);
    ~svip_action();
//    int deal_frame(cv::Mat img, std::vector<float>& result);
    int deal_frame(cv::Mat img, int &result);
    ApplicationType _applicationType;
    CameraType _cameraType;
    svip_ai_result_cb _cb{};
    float _conf = 0.5;
    float _motivation = 30;
    int _set_w{},_set_h{};
    MD5_CTX _md5{};
    void* _user;
private:
    unique_ptr<LogisticRegression> lr;
};


#endif //FINAL_INTERFACE_SVIP_ACTION_H
