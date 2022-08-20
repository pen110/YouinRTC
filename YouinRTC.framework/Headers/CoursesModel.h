//
//  CoursesModel.h
//  YouinRTC
//
//  Created by 潘欣 on 2022/8/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@interface RTCLiveMenusENModel : NSObject

/// 菜单ID
@property (nonatomic,strong) NSString *ID;

/// 菜单名称
@property (nonatomic,strong) NSString *name;

/// 菜单类型
@property (nonatomic,strong) NSString *type;

/// 是否开启
@property (nonatomic,assign) BOOL isShow;

/// 菜单内容
@property (nonatomic,strong) NSString *content;

/// 排序
@property (nonatomic,assign) int menuOrder;

/// 唯一标识
@property (nonatomic,strong) NSString *code;

@end




@interface RTCLiveMenusModel : NSObject

/// 菜单ID
@property (nonatomic,strong) NSString *ID;

/// 菜单名称
@property (nonatomic,strong) NSString *name;

/// 菜单类型
@property (nonatomic,strong) NSString *type;

/// 是否开启
@property (nonatomic,assign) BOOL isShow;

/// 菜单内容
@property (nonatomic,strong) NSString *content;

/// 排序
@property (nonatomic,assign) int menuOrder;

/// 唯一标识
@property (nonatomic,strong) NSString *code;

@end


@interface RTCHeadVideoModel : NSObject

/// 视频url
@property (nonatomic,strong) NSString *head_video_url;

/// 是否转码成功
@property (nonatomic,assign) BOOL isShow;

/// 是否开启
@property (nonatomic,assign) BOOL transcoding;

@end

@interface RTCForLanguageModel : NSObject

/// 是否开启
@property (nonatomic,assign) BOOL isShow;

/// 双线路拉流地址
@property (nonatomic,strong) NSString *url_hls;

/// 回放视频地址
@property (nonatomic,strong) NSString *m3u8_url;

/// 自定义回放视频地址
@property (nonatomic,strong) NSString *record_url;


@end

@interface CoursesModel : NSObject

/// 是否开启弹幕
@property (nonatomic,assign) BOOL barrage;

/// 更新时间
@property (nonatomic,strong) NSString *create_time;

/// 邀请卡图片
@property (nonatomic,strong) NSString *third_image;

/// 是否可以匿名登录
@property (nonatomic,assign) BOOL anonymous_login;

/// 英文菜单
@property (nonatomic,strong) NSArray<RTCLiveMenusENModel*> *live_menus_en;

/// 是否允许观看回放
@property (nonatomic,assign) BOOL record_access;

/// 直播id
@property (nonatomic,strong) NSString *ID;

/// 直播拉流地址
@property (nonatomic,strong) NSString *url_hls;

/// 是否开启英文观看
@property (nonatomic,assign) BOOL is_open_english;

/// 直播名称
@property (nonatomic,strong) NSString *title;

/// 直播开始时间
@property (nonatomic,strong) NSString *start_time;

/// 是否开启邀请卡
@property (nonatomic,strong) NSString *share_card;

/// 横屏竖屏 2 横屏  1竖屏
@property (nonatomic,assign) int play_mode;

/// 直播中文菜单
@property (nonatomic,strong) NSArray<RTCLiveMenusModel*> *live_menus;


// 课程简介
@property (nonatomic,strong) NSString *description;

/// 是否公开
@property (nonatomic,assign) BOOL isOpen;

// leancloudId
@property (nonatomic,strong) NSString *chat_room_id;

/// 数据美化
@property (nonatomic,assign) BOOL is_dummy_pv;

/// 暖场视频
@property (nonatomic,strong) RTCHeadVideoModel *head_video;

/// 是否开启了购物车
@property (nonatomic,assign) BOOL has_product;

/// 双线路推流
@property (nonatomic,strong) RTCForLanguageModel *foreign_language_watch;

/// 邀请卡图片
@property (nonatomic,strong) NSString *code;

/// 封面图
@property (nonatomic,strong) NSString *image;

// 白板roomToken（netless）
@property (nonatomic,strong) NSString *white_board_roomToken;

/// 直播类型 1=推流直播, 2=单人网页直播，3=连麦直播 4=定时推流视频
@property (nonatomic,assign) int stream_url_type;

/// 抽奖报名
@property (nonatomic,assign) BOOL apply_lottery;

/// 是否可以聊天
@property (nonatomic,assign) BOOL isProhibit;

/// 直播状态 1: 正在直播中 2：直播尚未开始 3:主播不在 4：直播已结束
@property (nonatomic,assign) int type;

/// 是否开启跑马灯
@property (nonatomic,assign) BOOL marquee;

/// 企业id
@property (nonatomic,strong) NSString *enterprise_id;

///
@property (nonatomic,assign) int stream_type;

/// 是否开启企业卡片
@property (nonatomic,assign) BOOL enterprise_card;

/// 回放地址
@property (nonatomic,strong) NSString *m3u8_url;

/// 付费观看 付费金额
@property (nonatomic,strong) NSString *amount;

/// 直播间状态
@property (nonatomic,assign) int active;

/// 是否有问卷、考试、投票
@property (nonatomic,assign) BOOL qev_exists;

// 是否开启水印
@property (nonatomic,assign) BOOL watermark;

/// 互动白板uuid
@property (nonatomic,strong) NSString *white_board_uuid;

/// 观看模式 whitelist（白名单） password（密码观看） paid（付费观看） none（公开观看）
@property (nonatomic,strong) NSString *limitType;

/// 是否开启了报名表单
@property (nonatomic,assign) BOOL apply_form;

// 来源
@property (nonatomic,strong) NSArray *menus;

/// 是否开启付费密码观看
@property (nonatomic,assign) BOOL codeStatus;

/// 结束时间
@property (nonatomic,strong) NSString *end_time;

/// 直播回放的截止日期
@property (nonatomic,strong) NSString *record_endDate;

@end

NS_ASSUME_NONNULL_END
