//
//  RTCGoodsListModel.h
//  YouinRTC
//
//  Created by 潘欣 on 2022/8/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@interface RTCGoodsProductModel : NSObject
@property(nonatomic,strong) NSString *app_id;
@property(nonatomic,strong) NSString *app_turn_url;
@property(nonatomic,strong) NSString *createDate;
@property(nonatomic,strong) NSString *goodsUrl;
@property(nonatomic,strong) NSString *ID;
@property(nonatomic,strong) NSString *image;
@property(nonatomic,assign) int jump_type;
@property(nonatomic,strong) NSString *name;
@property(nonatomic,strong) NSString *original_id;
@property(nonatomic,strong) NSString *page_path;
@property(nonatomic,strong) NSString *price;
@property(nonatomic,strong) NSString *price_end;
@property(nonatomic,strong) NSString *price_type;
@property(nonatomic,strong) NSString *subtitle;
@property(nonatomic,strong) NSString* product_label;
@property(nonatomic,strong) NSString* the_produce_id;
@property (nonatomic, assign) BOOL isSelect;
@property(nonatomic,strong)NSMutableArray *array;
@end

@interface RTCGoodsListModel : NSObject
@property(nonatomic,strong) NSString *ID;
@property(nonatomic,strong) NSString *createDate;
@property(nonatomic,strong) NSString *living_price;
@property(nonatomic,strong) RTCGoodsProductModel *product;
@property(nonatomic,assign) NSInteger order_no;
@property(nonatomic,assign) NSInteger sort_no;
@property(nonatomic,assign) BOOL isShow;
@end

NS_ASSUME_NONNULL_END
