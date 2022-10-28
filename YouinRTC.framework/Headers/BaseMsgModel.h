//
//  BaseMsgModel.h
//  YouinRTC
//
//  Created by 潘欣 on 2022/8/19.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MessagesModel.h"
NS_ASSUME_NONNULL_BEGIN



@interface BaseMsgModel : NSObject
@property(nonatomic,strong) NSString* nickName;
@property(nonatomic,strong) NSString* userId;
@property(nonatomic,strong) NSString* avatar;
@property(nonatomic,strong) NSString* messageId;
@property(nonatomic,strong) NSString* conversationId;
@property(nonatomic,assign) int messageType;
@property(nonatomic,strong) NSString* text;
@property(nonatomic,assign) BOOL isGift;
@property(nonatomic,strong) NSString* giftName;
@property(nonatomic,strong) NSString* giftUrl;
@property(nonatomic,assign) int giftCount;
@property(nonatomic,strong) NSString* imageUrl;
@property(nonatomic,strong) UIImage* image;
@property(nonatomic,assign) int64_t sendTime;
@property(nonatomic,strong) NSString *third_user_id;
@property(nonatomic,strong)UIColor *color;


//引用
@property(nonatomic,strong) NSString* msg;
@property(nonatomic,strong) RTCReferenceInfo *referenceInfo;
@property(nonatomic,strong) NSString *type;
@end

NS_ASSUME_NONNULL_END
