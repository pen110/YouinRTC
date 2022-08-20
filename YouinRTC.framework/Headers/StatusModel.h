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

/// 观看人数
@property (nonatomic,assign) int pv_count;

@end

NS_ASSUME_NONNULL_END
