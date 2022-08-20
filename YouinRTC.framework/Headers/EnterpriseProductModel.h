//
//  EnterpriseProductModel.h
//  YouinRTC
//
//  Created by 潘欣 on 2022/8/16.
//

#import <Foundation/Foundation.h>
#import "GoodsListModel.h"
NS_ASSUME_NONNULL_BEGIN

@interface EnterpriseProductModel : NSObject
@property(nonatomic,strong) NSString *previous;
@property(nonatomic,strong) NSString *next;
@property(nonatomic,strong) NSString *msg;
@property(nonatomic,assign) int counts;
@property(nonatomic,assign) int code;
@property(nonatomic,strong) NSArray<GoodsProductModel *> *result;
@property(nonatomic,assign) int order_no;
@end

NS_ASSUME_NONNULL_END
