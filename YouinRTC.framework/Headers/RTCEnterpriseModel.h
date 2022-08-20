//
//  RTCEnterpriseModel.h
//  YouinRTC
//
//  Created by 潘欣 on 2022/8/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@interface RTCGiftModel : NSObject

/// 礼物id
@property (nonatomic,strong) NSString *ID;

/// 礼物名称
@property (nonatomic,strong) NSString *name;

/// 礼物图片
@property (nonatomic,strong) NSString *image;

/// 礼物价格
@property (nonatomic,assign) double price;

/// 礼物排序
@property (nonatomic,assign) int sort_no;

@end

@interface RTCEnterpriseModel : NSObject

/// 企业id
@property (nonatomic,strong) NSString *ID;

/// 微信平台二维码
@property (nonatomic,strong) NSString *qrcode_url;

/// 企业联系电话
@property (nonatomic,strong) NSString *phone;

/// 企业全称
@property (nonatomic,strong) NSString *org_name;

/// 企业介绍
@property (nonatomic,strong) NSString *org_intro;

/// 企业宣传语
@property (nonatomic,strong) NSString *tag_line;

/// 企业简称
@property (nonatomic,strong) NSString *short_name;

/// 后台logo地址
@property (nonatomic,strong) NSString *backend_logo;

/// 直播间logo地址
@property (nonatomic,strong) NSString *frontend_logo;

/// 企业二维码
@property (nonatomic,strong) NSString *QR_code;

/// 是否是本地企业
@property (nonatomic,assign) BOOL is_local;

/// 创建时间
@property (nonatomic,strong) NSString *create_time;

/// 账号类型 1-主账号, 2-子账号
@property (nonatomic,assign) int type;

/// 是否删除
@property (nonatomic,assign) BOOL is_active;

@property (nonatomic,assign) int card_type;

/// 企业id
@property (nonatomic,strong) NSString *enterprise_id;

/// 企业leancloud房间
@property (nonatomic,strong) NSString *leancloud_room_id;

/// 微信公众号appid
@property (nonatomic,strong) NSString *wechat_appid;

/// 微信公众号模版id
@property (nonatomic,strong) NSString *wechat_template;

/// 备注
@property (nonatomic,strong) NSString *remark;

/// 来源
@property (nonatomic,strong) NSString *source;

/// 水印logo
@property (nonatomic,strong) NSString *water_image;

/// 是否绑定公众号
@property (nonatomic,assign) BOOL oauth_status;

/// 官网注册时ip
@property (nonatomic,strong) NSString *ip;

/// 官网注册时i区域
@property (nonatomic,strong) NSString *region;

/// 企业管理员id
@property (nonatomic,assign) int owner_user;

/// 关联员工名片
@property (nonatomic,strong) NSString *belong_manager;

/// 版本
@property (nonatomic,assign) int version;

/// 是否开启英文观看
@property (nonatomic,assign) BOOL English;

/// 底部技术支持
@property (nonatomic,strong) NSString *bottom_tech_support;

/// 邀请榜
@property (nonatomic,assign) BOOL InviteAdvertisement;

/// 技术支持广告
@property (nonatomic,assign) BOOL TechnicalSupportAdvertisement;

/// 弹幕
@property (nonatomic,assign) BOOL barrage;

/// 企业礼物
@property (nonatomic,strong) NSArray<RTCGiftModel*> *gift;

/// 是否过期或用量已用完
@property (nonatomic,assign) BOOL is_can_use;

/// 页面描述
@property (nonatomic,assign) int description;

@end

NS_ASSUME_NONNULL_END
