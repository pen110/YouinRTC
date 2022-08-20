//
//  YouinRTCDefine.h
//  YouinRTC
//
//  Created by super on 2021/9/14.
//

#ifndef YouinRTCDefine_h
#define YouinRTCDefine_h


#endif /* YouinRTCDefine_h */
// 会议信令枚举
typedef enum YouinAction {
    // 用户在线
    YouinActionUserOnline  = 0,
    // 主持人闭麦
    YouinActionHostMuteMic,
    // 主持人取消闭麦
    YouinActionHostUnMuteMic,
    // 主持人关闭摄像头
    YouinActionHostMuteCamera,
    // 主持人开启摄像头
    YouinActionHostUnMuteCamera,
    // 用户加入房间
    YouinActionUserEnterRoom,
    // 嘉宾申请上麦
    YouinActionUserApplySpeak,
    // 主持人同意上麦
    YouinActionHostAgreeUserSpeak,
    // 主持人拒绝上麦
    YouinActionHostRefuseUserSpeak,
    // 主持人邀请嘉宾上麦
    YouinActionHostInviteUserSpeak,
    // 嘉宾回复主持人邀请 拒绝上麦
    YouinActionUserReplyRefuseSpeak,
    // 嘉宾回复主持人邀请 同意上麦
    YouinActionUserReplyAgreeSpeak,
    // 嘉宾回复主持人邀请 超时
    YouinActionUserReplyOvertime,
    // 主持人开启嘉宾麦克风
    YouinActionHostTurnOnMicrophone,
    // 主持人关闭嘉宾麦克风
    YouinActionHostTurnOffMicrophone,
    // 主持人开启嘉宾摄像头
    YouinActionHostTurnOnCamera,
    // 主持人关闭嘉宾摄像头
    YouinActionHostTurnOffCamera,
    // 主持人下麦嘉宾
    YouinActionHostUnpublishUser,
    // 嘉宾主动下麦
    YouinActionUserDidNotSpeak,
    // 嘉宾离开会议
    YouinActionUserLeave,
    // 主持人设置主讲
    YouinActionHostSetMainSpeaker,
    // 主持人取消主讲
    YouinActionHostCancelMainSpeaker,
    // 主持人设置助理
    YouinActionHostSetAssistantuser,
    // 主持人取消助理
    YouinActionHostCancelAssistantuser
} YouinAction;


typedef enum YouinModuleFunc {
    YouinModuleFuncMetting = 0,
    YouinModuleFuncLive
}YouinModuleFunc;

