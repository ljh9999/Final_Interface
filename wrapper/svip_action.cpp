//
// Created by ljh on 2020/10/4.
//

#include "svip_action.h"
svip_action::svip_action(char *model, int length) {
#define code 0x1d61b20
#define mask 0x1d0
    long a = code;
    long b = mask;
}

int SVIP_AI_Action_Initialize()
{
    return SVIP_AI_OK;
}
int SVIP_AI_ShelfFront_Uninitialize()
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

svip_action::~svip_action() {
    ;
}


