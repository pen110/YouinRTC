//
//  LiveListModel.h
//  YouinRTC
//
//  Created by 潘欣 on 2022/8/15.
//

#import <Foundation/Foundation.h>
#import "CoursesModel.h"
NS_ASSUME_NONNULL_BEGIN

@interface VideoinfoExtend : NSObject
@property (nonatomic,strong) NSString *assistant_user;
@property (nonatomic,strong) NSString *assistant_user_name;
@property (nonatomic,strong) NSString *direct_user;
@property (nonatomic,strong) NSString *direct_user_name;
@property (nonatomic,strong) NSString *meeting_status;
@end

@interface liveStatusModel : NSObject
@property (nonatomic,strong) NSString *info;
//# 1-正在直播 2-未开始 3-主播不在 4-已结束
@property (nonatomic,assign)int status;
@end

@interface EnterModel : NSObject
@property (nonatomic,strong)NSString *QR_code;
@property (nonatomic,strong)NSString *back_url;
@property (nonatomic,strong)NSString *backend_logo;
@property (nonatomic,strong)NSString *belong_manager;
@property (nonatomic,assign)int card_type;
@property (nonatomic,strong)NSString *create_time;
@property (nonatomic,assign)int enterprise_id;
@property (nonatomic,strong)NSString *expire_date;
@property (nonatomic,strong)NSString *frontend_logo;
@property (nonatomic,strong)NSString *ID;
@property (nonatomic,strong)NSString *ip;
@property (nonatomic,assign)int is_active;
@property (nonatomic,assign)int is_empower;
@property (nonatomic,assign)int is_local;
@property (nonatomic,strong)NSString *leancloud_room_id;
@property (nonatomic,assign)int oauth_status;
@property (nonatomic,strong)NSString *org_intro;
@property (nonatomic,strong)NSString *org_name;
@property (nonatomic,assign)int owner_user;
@property (nonatomic,assign)int phone;
@property (nonatomic,strong)NSString *qrcode_url;
@property (nonatomic,strong)NSString *region;
@property (nonatomic,strong)NSString *remark;
@property (nonatomic,strong)NSString *short_name;
@property (nonatomic,strong)NSString *source;
@property (nonatomic,strong)NSString *tag_line;
@property (nonatomic,assign)int type;
@property (nonatomic,strong)NSString *version;
@property (nonatomic,strong)NSString *water_image;
@property (nonatomic,strong)NSString *wechat_appid;
@property (nonatomic,strong)NSString *wechat_template;
@end


@interface ResultModel :NSObject
@property (nonatomic,assign)int active;
@property (nonatomic,assign)int apply_form;
@property (nonatomic,assign)int audit;
@property (nonatomic,assign)int can_preview;
@property (nonatomic,assign)int chat_room_audit;
@property (nonatomic,strong)NSString *chat_room_id;
@property (nonatomic,strong)NSString *create_time;
@property (nonatomic,strong)NSString *descriptions;
@property (nonatomic,assign)int dummy_pv_count;
@property (nonatomic,strong)NSString *end_time;
@property (nonatomic,strong)EnterModel *enterprise;
@property (nonatomic,strong)NSString *enterprise_id;
@property (nonatomic,strong)NSString *foreign_video_info;
@property (nonatomic,strong)HeadVideoModel *headvideo;
@property (nonatomic,strong)NSString *ID;
@property (nonatomic,strong)NSString *image;
@property (nonatomic,assign)int isImageText;
@property (nonatomic,assign)int isNew;
@property (nonatomic,assign)int isOpen;
@property (nonatomic,assign)int isPreview;
@property (nonatomic,strong)NSArray *labels;
@property (nonatomic,strong)liveStatusModel *live_status;
@property (nonatomic,assign)int max_dummy_pv;
@property (nonatomic,strong)NSString *meetingId;
@property (nonatomic,assign)int min_dummy_pv;
@property (nonatomic,strong)NSString *nickname;
@property (nonatomic,assign)int play_mode;
@property (nonatomic,strong)NSString * product_count;
@property (nonatomic,strong)NSArray *relation_user;
@property (nonatomic,strong)NSString *share_card;
@property (nonatomic,strong)NSString *start_time;
@property (nonatomic,assign)int stream_type;
@property (nonatomic,assign)int stream_url_type;
@property (nonatomic,strong)NSString *sub_account_name;
@property (nonatomic,strong)NSString *teacher_id;
@property (nonatomic,strong)NSString *teacher_name;
@property (nonatomic,strong)NSString *third_image;
@property (nonatomic,strong)NSString *title;
//# 1：直播，2：直播转录播 3：上传录播
@property (nonatomic,assign)int type;
@property (nonatomic,strong)NSString *user_id;
@property (nonatomic,strong)VideoinfoExtend *videoinfo_extend;
@end

@interface LiveListModel : NSObject
@property (nonatomic,assign)int code;
@property (nonatomic,assign)int counts;
@property (nonatomic,strong)NSString *msg;
@property (nonatomic,strong)NSString *next;
@property (nonatomic,assign)int pages;
@property (nonatomic,strong)NSString *previous;
@property (nonatomic,strong)NSArray<ResultModel *> *result;
@end

NS_ASSUME_NONNULL_END
