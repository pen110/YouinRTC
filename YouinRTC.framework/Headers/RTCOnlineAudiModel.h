//
//  RTCOnlineAudiModel.h
//  YouinRTC
//
//  Created by 潘欣 on 2022/8/25.
//

#import <Foundation/Foundation.h>
#import "RTCRankingGiftModel.h"
NS_ASSUME_NONNULL_BEGIN

@interface RTCOnlineAudiModel : NSObject
@property (nonatomic,assign)int code;
@property (nonatomic,assign)int counts;
@property (nonatomic,strong)NSString *msg;
@property (nonatomic,strong)NSString *next;
@property (nonatomic,assign)int pages;
@property (nonatomic,strong)NSString *previous;
@property (nonatomic,strong)NSArray<RTCUserInfo *> *result;
@end

NS_ASSUME_NONNULL_END
