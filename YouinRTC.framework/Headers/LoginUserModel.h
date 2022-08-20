//
//  LoginUserModel.h
//  YouinLiveSDK
//
//  Created by super on 2021/9/3.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LoginUserModel : NSObject

/// token
@property (nonatomic,strong) NSString *tpzb_token;

/// 过期时间
@property (nonatomic,assign) int exprise_time;

@end

NS_ASSUME_NONNULL_END
