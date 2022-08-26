//
//  RTCInvitesListModel.h
//  YouinRTC
//
//  Created by 潘欣 on 2022/8/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@interface RTCInvitesResult : NSObject
@property (nonatomic,strong)NSString *image;
@property (nonatomic,assign)int invite_count;
@property (nonatomic,strong)NSString *nickname;
@property (nonatomic,strong)NSString *shareUserId;
@property (nonatomic,strong)NSString *third_user_id;
@end

@interface RTCInvitesListModel : NSObject
@property (nonatomic,assign)int code;
@property (nonatomic,assign)int counts;
@property (nonatomic,strong)NSString *msg;
@property (nonatomic,strong)NSString *next;
@property (nonatomic,assign)int pages;
@property (nonatomic,strong)NSString *previous;
@property (nonatomic,strong)NSArray<RTCInvitesResult *> *result;
@end

NS_ASSUME_NONNULL_END
