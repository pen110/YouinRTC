//
//  StatusModel.h
//  YouinLiveSDK
//
//  Created by super on 2021/9/2.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface StatusModel : NSObject
/// 是否被禁言
@property (nonatomic,assign) BOOL is_forbidden;

/// 是否被踢出直播间
@property (nonatomic,assign) BOOL is_kickout;

/// 是否报过名
@property (nonatomic,assign) BOOL sign_course;

/// 点赞次数
@property (nonatomic,assign) int like_count;

/// 直播状态  4未开始1直播中2主播不在3直播已结束
@property (nonatomic,assign) int live_status;

/// 真实访问人次
@property (nonatomic,assign) int pv_count;

/// 美化后人数
@property (nonatomic,assign) int dummy_pv_count;

/// 美化后 点赞数
@property (nonatomic,assign) int dummy_like_count;

/// 当前在线人数
@property (nonatomic,assign) int current_watch_count;

/// 最高在线人数
@property (nonatomic,assign) int max_watch_count;

/// 真实访问人数
@property (nonatomic,assign) int uv_count;

///分享次数
@property (nonatomic,assign) int share_count;
@end

NS_ASSUME_NONNULL_END
