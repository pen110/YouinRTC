//
//  MessagesModel.h
//  YouinRTC
//
//  Created by 潘欣 on 2022/8/19.
//

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN
//引用的消息体
@interface RTCReferenceInfo : NSObject
@property(nonatomic,strong) NSString *attribute;
@property(nonatomic,strong) NSString *avatar;
@property(nonatomic,strong) NSString *content;
@property(nonatomic,strong) NSString *ID;
@property(nonatomic,strong) NSString *timer;
@property(nonatomic,strong) NSString *type;
@property(nonatomic,strong) NSString *userId;
@property(nonatomic,strong) NSString *userName;
@end

@interface RTCUserInfoModel : NSObject
@property(nonatomic,strong) NSString *userId;
@property(nonatomic,strong) NSString *userName;
@property(nonatomic,strong) NSString *avatar;
@property(nonatomic,strong) NSString *youin_user_id;
@property(nonatomic,strong) NSString *qiniu_user_id;
//1－管理员, 2-子账号,(可以创建直播)
//3-讲师 （无权创建直播，但是可以开关直播）
//# 1－管理员, 2-子账号, 3-讲师, 4-直播助手 5-普通用户 6-匿名用户
@property(nonatomic,assign) int user_type;
//是否主播
@property(nonatomic,assign) BOOL isHost;
@property(nonatomic,assign) int exprise_time;
@property(nonatomic,assign) int timestamp;
// 子用户token
@property(nonatomic,strong) NSString *token;
@property(nonatomic,assign) BOOL  is_mic_mute;
@property(nonatomic,assign) BOOL  is_camera_mute;
@property(nonatomic,assign) BOOL  hands_up;
@property(nonatomic,assign) int hands_up_time;
@property(nonatomic,assign) int enter_time;
@property(nonatomic,assign) BOOL  is_invited;
@property(nonatomic,assign) int role;
@property(nonatomic,assign) BOOL  interactive;
@end

@interface RTCRoomStatusModel : NSObject

/// 主持人信息
@property(nonatomic,strong) RTCUserInfoModel *hostUserInfo;

/// 是否在房间中
@property(nonatomic,assign) BOOL  isUseInhome;

/// 是否上麦
@property(nonatomic,assign) BOOL  isUserPublish;

/// 是否是举手模式上麦(否则为自由上麦模式)
@property(nonatomic,assign) BOOL  isRoomHandsUp;

/// 是否全部静音
@property(nonatomic,assign) BOOL  isRoomMuteAll;
@end

@interface RTCAttModel : NSObject
@property(nonatomic,strong) NSString *avatar;
@property(nonatomic,assign) int userStatus;
@property(nonatomic,assign) int pv_count;
@property(nonatomic,assign) int like_count;
@property(nonatomic,strong) NSString *ws_type;
@property(nonatomic,strong) NSString *type;
@property(nonatomic,strong) NSString* userId;
@property(nonatomic,assign) BOOL status;
@property(nonatomic,strong) NSString *url_flv;
@property(nonatomic,strong) NSString *url_hls;
@property(nonatomic,strong) NSString *url_rtmp;
@end

@interface RTCProductModel : NSObject
@property(nonatomic,strong) NSString *app_id;
@property(nonatomic,strong) NSString *app_turn_url;
@property(nonatomic,strong) NSString *createDate;
@property(nonatomic,strong) NSString *goodsUrl;
@property(nonatomic,strong) NSString *ID;
@property(nonatomic,strong) NSString *image;
@property(nonatomic,strong) NSString *isShow;
@property(nonatomic,strong) NSString *jump_type;
@property(nonatomic,strong) NSString *name;
@property(nonatomic,strong) NSString *original_id;
@property(nonatomic,strong) NSString *page_path;
@property(nonatomic,strong) NSString *price;
@property(nonatomic,strong) NSString *price_end;
@property(nonatomic,strong) NSString *price_type;
@property(nonatomic,strong) NSString *product_label;
@property(nonatomic,strong) NSString *subtitle;
@property(nonatomic,strong) NSString *the_produce_id;
@property(nonatomic,strong) NSString *updateDate;
@end


@interface RTCTextModel : NSObject
@property(nonatomic,strong) NSString *text;
@property(nonatomic,strong) NSString *type;
@property(nonatomic,strong) RTCProductModel *product;
@property(nonatomic,strong) NSString*  userId;
@property(nonatomic,assign) BOOL  status;
@property(nonatomic,strong) NSString *timeStamp;
@property(nonatomic,strong) NSString *prizeId;
@property(nonatomic,strong) NSString *red_id;
@property(nonatomic,strong) NSString *nickname;
@property(nonatomic,strong) NSString *giftImg;
@property(nonatomic,strong) NSString *userName;
@property(nonatomic,assign) int giftCount;
@property(nonatomic,strong) NSString *giftName;
@property(nonatomic,strong) NSString *position;
@property(nonatomic,assign) int signaling_type;
@property(nonatomic,strong) NSString *user_id;
@property(nonatomic,assign) BOOL  is_allow;
@property(nonatomic,assign) BOOL  is_mic_mute;
@property(nonatomic,assign) BOOL  is_camera_mute;
@property(nonatomic,assign) BOOL  hands_up;
@property(nonatomic,assign) int hands_up_time;
@property(nonatomic,assign) int enter_time;
@property(nonatomic,assign) BOOL  is_invited;
@property(nonatomic,assign) int role;
@property(nonatomic,assign) BOOL  closed_wheat;
@property(nonatomic,assign) int  wheat_mode;
@property(nonatomic,assign) BOOL  interactive;
//引用发送的消息
@property(nonatomic,strong) NSString *msg;
@property(nonatomic,strong) RTCReferenceInfo *referenceInfo;
@end

@interface RTCFileModel : NSObject
@property(nonatomic,strong) NSString *objId;
@property(nonatomic,strong) NSString *url;
@end

@interface MessagesModel : NSObject
@property(nonatomic,strong) NSString *_lctype;
@property(nonatomic,strong) RTCTextModel *_lctext;
@property(nonatomic,strong) RTCAttModel *_lcattrs;
@property(nonatomic,strong) RTCFileModel *_lcfile;
@end


@interface RTCLiveNoticeModel : NSObject
@property(nonatomic,assign) int ID;
@property(nonatomic,strong) NSString *content;
@property(nonatomic,assign) int type;
@property(nonatomic,strong) NSString *createDate;
@end

NS_ASSUME_NONNULL_END
