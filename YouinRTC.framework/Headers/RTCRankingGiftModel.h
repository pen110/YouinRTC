//
//  RTCRankingGiftModel.h
//  YouinRTC
//
//  Created by 潘欣 on 2022/8/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTCUserInfo : NSObject
@property (nonatomic,strong)NSString *address;
@property (nonatomic,strong)NSString *city;
@property (nonatomic,strong)NSString *company;
@property (nonatomic,strong)NSString *department;
@property (nonatomic,strong)NSString *email;
@property (nonatomic,strong)NSString *headImageUrl;
@property (nonatomic,strong)NSString *intro;
@property (nonatomic,strong)NSString *job_num;
@property (nonatomic,strong)NSString *name;
@property (nonatomic,strong)NSString *nickname;
@property (nonatomic,strong)NSString *owner_id;
@property (nonatomic,strong)NSString *phone;
@property (nonatomic,strong)NSString *position;
@property (nonatomic,strong)NSString *third_user_id;
@property (nonatomic,assign)int type;
@end

@interface RTCRankResultModel : NSObject
@property (nonatomic,strong)NSString *total_price_count;
@property (nonatomic,strong)RTCUserInfo *user_info;
@end

@interface RTCRankingGiftModel : NSObject
@property (nonatomic,assign)int code;
@property (nonatomic,assign)int counts;
@property (nonatomic,strong)NSString *msg;
@property (nonatomic,strong)NSString *next;
@property (nonatomic,assign)int pages;
@property (nonatomic,strong)NSString *previous;
@property (nonatomic,strong)NSArray<RTCRankResultModel *> *result;
@end

NS_ASSUME_NONNULL_END
