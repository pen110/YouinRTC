//
//  YouinRTCManager.h
//  YouinRTC
//
//  Created by lprison on 2021/9/12.
//

#import <Foundation/Foundation.h>
#import <QNRTCKit/QNRTCKit.h>
#import "BaseMsgModel.h"

#import <LeanCloudObjc/Foundation.h>
#import <LeanCloudObjc/LCIMConversation.h>
#import <LeanCloudObjc/LCIMClient.h>
#import <LeanCloudObjc/LCIMTextMessage.h>
#import <LeanCloudObjc/LCIMImageMessage.h>
#import <LeanCloudObjc/LCIMConversationQuery.h>


#import "RTCEnterpriseModel.h"
#import "CoursesModel.h"
#import "StatusModel.h"
#import "LoginUserModel.h"
#import "BaseMsgModel.h"
#import "YouinRTCDefine.h"
#import "MessagesModel.h"
#import "LiveListModel.h"
#import "RTCGoodsListModel.h"
#import "EnterpriseProductModel.h"
#import "RTCKickOutListModel.h"
#import "RTCRankingGiftModel.h"
#import "RTCInvitesListModel.h"
#import "RTCOnlineAudiModel.h"
NS_ASSUME_NONNULL_BEGIN
@class YouinRTCManager;
#pragma mark - delegate
typedef void ( ^successBloc) (id json);
// 请求失败
typedef void (^failure)(id error);
@protocol youinRTCChatDelegate <NSObject>

/// 企业信息回调
/// @param enterpriseModel 企业信息model
/// @param error 错误原因
-(void)enterpriseInfo:(nullable RTCEnterpriseModel *)enterpriseModel error:(nullable NSError *)error;

/// 直播间信息回调
/// @param courseInfoModel 直播间信息model
/// @param error 错误原因
-(void)courseInfo:(nullable CoursesModel *)courseInfoModel error:(nullable NSError *)error;

/// 直播状态回调
/// @param statusModel 直播状态model
/// @param error 错误原因
-(void)statusInfo:(nullable StatusModel *)statusModel error:(nullable NSError *)error;

/// 是否被禁言
/// @param isUserForbidden 是否被禁言
-(void)isUserForbidden:(BOOL )isUserForbidden;

/// 是否被踢出房间
/// @param isUserKickOut 是否被踢出房间
-(void)isUserKickOut:(BOOL )isUserKickOut;

/// 接收到新消息
/// @param messageModel 消息
-(void)onNewMessageRecive:(BaseMsgModel *)messageModel;

/// 房间用户列表
/// @param userList 用户列表
-(void)userList:(NSArray<RTCUserInfoModel *>*)userList;


@end


@protocol YouinRTCDelegate <NSObject>

@optional


/// 点赞回调
/// @param manager manager description
/// @param attModel attModel description
-(void)youinManager:(YouinRTCManager *)manager likeInfo:(nullable RTCAttModel *)attModel;


/*!
 * @abstract 信令回调
 *
 * @discussion 会议事件，详情请看YouinAction枚举值
 *   // 用户在线
 *   YouinActionUserOnline  = 0,
 *   // 用户加入房间
 *   YouinActionUserEnterRoom,
 *   // 嘉宾申请上麦
 *   YouinActionUserApplySpeak,
 *   // 主持人同意上麦
 *   YouinActionHostAgreeUserSpeak,
 *   // 主持人拒绝上麦
 *   YouinActionHostRefuseUserSpeak,
 *   // 主持人邀请嘉宾上麦
 *   YouinActionHostInviteUserSpeak,
 *   // 嘉宾回复主持人邀请 拒绝上麦
 *   YouinActionUserReplyRefuseSpeak,
 *   // 嘉宾回复主持人邀请 同意上麦
 *   YouinActionUserReplyAgreeSpeak,
 *   // 嘉宾回复主持人邀请 超时
 *   YouinActionUserReplyOvertime,
 *   // 主持人开启嘉宾麦克风
 *   YouinActionHostTurnOnMicrophone,
 *   // 主持人关闭嘉宾麦克风
 *   YouinActionHostTurnOffMicrophone,
 *   // 主持人开启嘉宾摄像头
 *   YouinActionHostTurnOnCamera,
 *   // 主持人关闭嘉宾摄像头
 *   YouinActionHostTurnOffCamera,
 *   // 嘉宾主动下麦
 *   YouinActionUserDidNotSpeak,
 *   // 嘉宾离开会议
 *   YouinActionUserLeave
 *
 */
-(void)YouinSignalAction:(YouinAction)signalAction;

/// 返回房间信息
/// 包括主持人信息、房间状态。
/// @param roomInfo 房间信息
-(void)YouinRoomInfo:(RTCRoomStatusModel*)roomInfo;

/// 房间用户列表
/// @param userList 用户列表
-(void)userList:(NSArray<RTCUserInfoModel *>*)userList;

/*!
 * @abstract SDK 运行过程中发生错误会通过该方法回调。
 *
 * @discussion 具体错误码的含义可以见 QNTypeDefines.h 文件。
 *
 * @since v2.0.0
 */
- (void)YouinRTC:(QNRTCEngine *)engine didFailWithError:(NSError *)error;

/*!
 * @abstract 房间状态变更的回调。
 *
 * @discussion 当状态变为 QNRoomStateReconnecting 时，SDK 会为您自动重连，如果希望退出，直接调用 leaveRoom 即可。
 * 重连成功后的状态为 QNRoomStateReconnected。
 *
 * @since v2.0.0
 */
- (void)YouinRTC:(QNRTCEngine *)engine roomStateDidChange:(QNRoomState)roomState;

/*!
 * @abstract 本地音/视频 Track 成功发布的回调。
 *
 * @since v2.0.0
 */
- (void)YouinRTC:(QNRTCEngine *)engine didPublishLocalTracks:(NSArray<QNTrackInfo *> *)tracks;

/*!
 * @abstract 远端用户加入房间的回调。
 *
 * @since v2.0.0
 */
- (void)YouinRTC:(QNRTCEngine *)engine didJoinOfRemoteUserId:(NSString *)userId userData:(NSString *)userData;

/*!
 * @abstract 远端用户离开房间的回调。
 *
 * @since v2.0.0
 */
- (void)YouinRTC:(QNRTCEngine *)engine didLeaveOfRemoteUserId:(NSString *)userId;

/*!
 * @abstract 订阅远端用户成功的回调。
 *
 * @since v2.0.0
 */
- (void)YouinRTC:(QNRTCEngine *)engine didSubscribeTracks:(NSArray<QNTrackInfo *> *)tracks ofRemoteUserId:(NSString *)userId;

/*!
 * @abstract 订阅远端用户 profile 发生改变的回调
 *
 * @since v2.5.0
 */
- (void)YouinRTC:(QNRTCEngine *)engine didSubscribeProfileChanged:(NSArray<QNTrackInfo *> *)tracks ofRemoteUserId:(NSString *)userId;

/*!
 * @abstract 远端用户发布音/视频的回调。
 *
 * @since v2.0.0
 */
- (void)YouinRTC:(QNRTCEngine *)engine didPublishTracks:(NSArray<QNTrackInfo *> *)tracks ofRemoteUserId:(NSString *)userId;

/*!
 * @abstract 远端用户取消发布音/视频的回调。
 *
 * @since v2.0.0
 */
- (void)YouinRTC:(QNRTCEngine *)engine didUnPublishTracks:(NSArray<QNTrackInfo *> *)tracks ofRemoteUserId:(NSString *)userId;

/*!
 * @abstract 被 userId 踢出的回调。
 *
 * @since v2.0.0
 */
- (void)YouinRTC:(QNRTCEngine *)engine didKickoutByUserId:(NSString *)userId;

/*!
 * @abstract 远端用户音频状态变更为 muted 的回调。
 *
 * @since v2.0.0
 */
- (void)YouinRTC:(QNRTCEngine *)engine didAudioMuted:(BOOL)muted ofTrackId:(NSString *)trackId byRemoteUserId:(NSString *)userId;

/*!
 * @abstract 远端用户视频状态变更为 muted 的回调。
 *
 * @since v2.0.0
 */
- (void)YouinRTC:(QNRTCEngine *)engine didVideoMuted:(BOOL)muted ofTrackId:(NSString *)trackId byRemoteUserId:(NSString *)userId;

/*!
 * @abstract 远端用户视频首帧解码后的回调。
 *
 * @discussion 如果需要渲染，则需要返回一个带 renderView 的 QNVideoRender 对象。
 *
 * @since v2.0.0
 */
- (QNVideoRender *)YouinRTC:(QNRTCEngine *)engine firstVideoDidDecodeOfTrackId:(NSString *)trackId remoteUserId:(NSString *)userId;

/*!
 * @abstract 远端用户视频取消渲染到 renderView 上的回调。
 *
 * @since v2.0.0
 */
- (void)YouinRTC:(QNRTCEngine *)engine didDetachRenderView:(UIView *)renderView ofTrackId:(NSString *)trackId remoteUserId:(NSString *)userId;

/*!
 * @abstract 远端用户视频数据的回调。
 *
 * @discussion 注意：回调远端用户视频数据会带来一定的性能消耗，如果没有相关需求，不要实现该回调。
 *
 * @since v2.0.0
 */
- (void)YouinRTC:(QNRTCEngine *)engine didGetPixelBuffer:(CVPixelBufferRef)pixelBuffer ofTrackId:(NSString *)trackId remoteUserId:(NSString *)userId;

/*!
 * @abstract 远端用户音频数据的回调。
 *
 * @discussion 注意：回调远端用户音频数据会带来一定的性能消耗，如果没有相关需求，请不要实现该回调。
 *
 * @since v2.0.0
 */
- (void)YouinRTC:(QNRTCEngine *)engine
didGetAudioBuffer:(AudioBuffer *)audioBuffer
   bitsPerSample:(NSUInteger)bitsPerSample
      sampleRate:(NSUInteger)sampleRate
       ofTrackId:(NSString *)trackId
    remoteUserId:(NSString *)userId;

/*!
 * @abstract 摄像头原数据时的回调。
 *
 * @discussion 便于开发者做滤镜等处理，需要注意的是这个回调在 camera 数据的输出线程，请不要做过于耗时的操作，否则可能会导致编码帧率下降。
 *
 * @since v2.0.0
 */
- (void)YouinRTC:(QNRTCEngine *)engine cameraSourceDidGetSampleBuffer:(CMSampleBufferRef)sampleBuffer;

/*!
 * @abstract 麦克风原数据时的回调。
 *
 * @discussion 需要注意的是这个回调在 AU Remote IO 线程，请不要做过于耗时的操作，否则可能阻塞该线程影响音频输出或其他未知问题。
 *
 * @since v2.0.0
 */
- (void)YouinRTC:(QNRTCEngine *)engine microphoneSourceDidGetAudioBuffer:(AudioBuffer *)audioBuffer;

/*!
 * @abstract 麦克风原数据时的回调。
 *
 * @discussion 需要注意的是这个回调在 AU Remote IO 线程，请不要做过于耗时的操作，否则可能阻塞该线程影响音频输出或其他未知问题。
 *
 * @warning 注意，当接入蓝牙耳机等外置设备时，采样率可能发生改变，具体值可从 asbd 中获取。
 *
 * @since v2.1.0
 */
- (void)YouinRTC:(QNRTCEngine *)engine microphoneSourceDidGetAudioBuffer:(AudioBuffer *)audioBuffer asbd:(const AudioStreamBasicDescription *)asbd;

/*!
 * @abstract 统计信息回调。
 *
 * @discussion 回调的时间间隔由 statisticInterval 参数决定，statisticInterval 默认为 0，即不回调统计信息。
 *
 * @see statisticInterval
 *
 * @since v2.0.0
 */
- (void)YouinRTC:(QNRTCEngine *)engine
 didGetStatistic:(NSDictionary *)statistic
       ofTrackId:(NSString *)trackId
          userId:(NSString *)userId;

/*!
 * @abstract 用户音量回调，包括本地和远端，volume 值在 [0, 1] 之间。
 *
 * @discussion 注意：回调用户音量会带来一定的性能消耗，如果没有相关需求，请不要实现该回调。
 *
 * @since v2.3.0
 */
- (void)YouinRTC:(QNRTCEngine *)engine volume:(float)volume ofTrackId:(NSString *)trackId userId:(NSString *)userId;

/*!
 * @abstract 成功创建合流任务的回调。
 *
 * @since v2.0.0
 */
- (void)YouinRTC:(QNRTCEngine *)engine didCreateMergeStreamWithJobId:(NSString *)jobId;

/*!
 * @abstract 音频输出设备变更的回调。主动调用的 `- (void)setSpeakerOn:(BOOL)speakerOn;` 不会有该回调。
 *
 * @since v2.1.0
 */
- (void)YouinRTC:(QNRTCEngine *)engine didChangeAudioOutputToDevice:(QNAudioDeviceType)deviceType;

/*!
 * @abstract 收到消息的回调。
 *
 * @since v2.3.0
 */
- (void)YouinRTC:(QNRTCEngine *)engine didReceiveMessage:(QNMessageInfo *)message;

/*!
 * @abstract 本地用户离开房间成功的回调。
 *
 * @discussion 调用 leaveRoom 离开房间成功的回调
 *
 * @since v2.4.0
 */
- (void)YouinRTC:(QNRTCEngine *)engine didLeaveOfLocalSuccess:(BOOL)success;

/*!
 * @abstract 成功创建单路转推任务的回调。
 *
 * @since v2.5.0
 */
- (void)YouinRTC:(QNRTCEngine *)engine didCreateForwardJobWithJobId:(NSString *)jobId;

/*!
 * @abstract 远端用户发生重连的回调。
 *
 * @since v3.0.0
 */
- (void)YouinRTC:(QNRTCEngine *)engine didReconnectingRemoteUserId:(NSString *)userId;

/*!
 * @abstract 远端用户重连成功的回调。
 *
 * @since v3.0.0
 */
- (void)YouinRTC:(QNRTCEngine *)engine didReconnectedRemoteUserId:(NSString *)userId;


@end

@interface YouinRTCManager : NSObject


/// 核心类(七牛RTC，可以通过此属性设置更多高级配置。更多高级配置请访问 https://doc.qnsdk.com/rtn );
@property (nonatomic, strong) QNRTCEngine *engine;

/// delegate 返回房间信息
@property (nonatomic,weak) id<YouinRTCDelegate>delegate;

/// 聊天回调
@property (nonatomic,weak) id<youinRTCChatDelegate>chatDelegate;

/// appid 从Youin后台获取
@property (nonatomic,strong) NSString *app_id;

/// app_secret 从Youin后台获取
@property (nonatomic,strong) NSString *app_secret;
/// 聊天client
@property(nonatomic,strong) LCIMClient * client;
/// 对话
@property (nonatomic,strong) LCIMConversation *conversation;

/// 账号密码登陆的token
@property (nonatomic,strong) NSString *phone_pass_login_token;

/// 用户是否被禁言
@property(nonatomic,assign) BOOL isUserForbidden;

/// 用户是否被踢出房间
@property(nonatomic,assign) BOOL isUserKickOut;

/// 是否在房间中
@property(nonatomic,assign) BOOL isInHome;

/// 是否上麦中
@property(nonatomic,assign) BOOL isPublish;

/// 是否全体静音
@property(nonatomic,assign) BOOL isMuteAll;

/// 是否举手模式
@property(nonatomic,assign) BOOL isHandsUp;

/// 是否是主持人或者助理
@property(nonatomic,assign) BOOL isDirectOrAssistant;

/// 主持人信息
@property (nonatomic,strong) RTCUserInfoModel *hostInfoModel;

/// 申请人信息
@property (nonatomic,strong) RTCUserInfoModel *applyUserInfoModel;

///房间成员列表
@property (nonatomic,strong) NSMutableArray <RTCUserInfoModel *> *userList;

///audioTrack
@property (nonatomic,strong) QNTrackInfo *audioTrack;

/// cameraTrack
@property (nonatomic,strong) QNTrackInfo *cameraTrack;

/// SDK模块功能：YouinModuleFuncMetting 会议默认，YouinModuleFuncLive：主播
@property (nonatomic,assign) YouinModuleFunc modouleFunc;


#pragma mark function

/// 管理SDK单例
+ (instancetype)shardManager;

/// 初始化SDK
-(void)initialize:(void (^)(BOOL  success, NSError * _Nullable error))callback;


/// 绑定用户
/// @param userId 用户ID
/// @param name 昵称
/// @param avatar 头像地址
/// @param callback 回调
-(void)bindUser:(NSString *)userId name:(NSString *)name avatar:(NSString *)avatar callback:(void (^)(BOOL  success, NSError * _Nullable error))callback;


/// 登陆到有因侧
/// @param name 用户名
/// @param password 密码
/// @param callback 回调
-(void)loginIn:(NSString *)name password:(NSString *)password callback:(void (^)(NSDictionary  *success, NSError * _Nullable error))callback;

/// 进入房间
/// @param roomID 房间ID
/// @param callback 回调
-(void)joinRoom:(NSString *)roomID callback:(void (^)(BOOL success, NSError * _Nullable error))callback;

/// 离开房间
-(void)leaveRoom;

-(NSArray<NSString *> *)getUserList;

/// 发送文字消息
/// @param text 文字
/// @param callback 回调
-(void)sendTextMessage:(NSString *)text callback:(void (^)(BOOL success, NSError * _Nullable error))callback;

/// 发送图片消息
/// @param image 图片
/// @param callback 回调
-(void)sendImageMessage:(UIImage *)image callback:(void (^)(BOOL, NSError * _Nullable))callback;

/// 获取历史信息
/// @param count 1-100
/// @param callback 回调
-(void)getHistoryMessage:(int )count callback:(void (^)(NSArray<BaseMsgModel*> *message, NSError * _Nullable error))callback;


/// 获取直播列表(所有状态都会返回)
/// @param page 分页
/// @param success success description
/// @param failure failure description
- (void)liveListCourse:(int)page success:(successBloc)success failure:(nullable void (^)(NSError * nullable))failure;

-(NSDictionary *)readNSUserDefaults;
-(void)removeToken;
-(void)saveNSUserDefaults:(NSDictionary *)dic;

/// 发送信令
/// @param action 信令枚举
/*// 用户在线
YouinActionUserOnline  = 0,
// 用户加入房间
YouinActionUserEnterRoom,
// 嘉宾申请上麦
YouinActionUserApplySpeak,
// 主持人同意上麦
YouinActionHostAgreeUserSpeak,
// 主持人拒绝上麦
YouinActionHostRefuseUserSpeak,
// 主持人邀请嘉宾上麦
YouinActionHostInviteUserSpeak,
// 嘉宾回复主持人邀请 拒绝上麦
YouinActionUserReplyRefuseSpeak,
// 嘉宾回复主持人邀请 同意上麦
YouinActionUserReplyAgreeSpeak,
// 嘉宾回复主持人邀请 超时
YouinActionUserReplyOvertime,
// 主持人开启嘉宾麦克风
YouinActionHostTurnOnMicrophone,
// 主持人关闭嘉宾麦克风
YouinActionHostTurnOffMicrophone,
// 主持人开启嘉宾摄像头
YouinActionHostTurnOnCamera,
// 主持人关闭嘉宾摄像头
YouinActionHostTurnOffCamera,
// 嘉宾主动下麦
YouinActionUserDidNotSpeak,
// 嘉宾离开会议
YouinActionUserLeave
 */
-(void)YouinAction:(YouinAction)action;



/// ****************** 基础方法 **********************

/// 摄像头开始采集
-(void)startCapture;

/// 关闭摄像头采集
-(void)stopCapture;

/// 发布音视频（上麦）
-(void)publish;

/// 取消发布音视频（下麦）
-(void)unPublish;

/// 切换摄像头(前置/后置)
-(void)changeCamera;

/// 是否关闭麦克风
/// @param isMute 是否关闭
-(void)muteMicrophone:(BOOL)isMute;

/// 是否关闭扬声器
/// @param isMute 是否关闭
-(void)muteSpeaker:(BOOL)isMute;

#pragma mark - 主持人专属功能

/// 禁言所有人 (连麦)
/// @param isMute 是否禁言所有人
-(void)muteAllSpeaker:(BOOL)isMute;

/// 打开关闭用户麦克风
/// @param isOpen true 打开麦克风  false 关闭麦克风
/// @param userId 用户id
-(void)openSpeakerMike:(BOOL)isOpen userId:(NSString *)userId;


/// 打开关闭用户摄像头
/// @param isOpen true 打开摄像头  false 关闭摄像头
/// @param userId 用户id
-(void)openSpeakerCamera:(BOOL)isOpen userId:(NSString *)userId;


/// 邀请用户上麦
/// @param userId 用户id
-(void)inviteUserPublish:(NSString *)userId;


/// 下麦用户
/// @param userId 用户id
-(void)unPublishUser:(NSString *)userId;


/// 审批用户上麦申请
/// @param isAgree true 同意用户上麦申请 false 不同意用户上麦申请
/// @param userId 用户id
-(void)agreeUserPublishApply:(BOOL)isAgree userId:(NSString *)userId;

/// 开始直播
-(void)beginLiveSuccess:(successBloc)success failure:(failure)failure;

/// 结束直播
/// @param isEndLive 是否结束直播间，否，仅退出房间结束合流；是，结束直播间
-(void)stopLive:(BOOL)isEndLive suc:(void (^)(bool suc))suc;

/// 获取历史公告
/// @param success 公告数组
/// @param failure 错误
-(void)getHistoyNotice:(void (^)(NSArray<RTCLiveNoticeModel *> *content))success failure:(void (^)(NSError *error))failure;

/// 发送历史公告
/// @param model 公告模型
/// @param success 成功
/// @param failure 失败
-(void)sendNotice:(RTCLiveNoticeModel *)model success:(void (^)(bool success))success failure:(void (^)(NSError *error))failure;



/// ****************** 高级配置 **********************


/// 预览图的填充模式
@property(readwrite, nonatomic) QNVideoFillModeType fillMode;

/// 配置前后摄像头。默认为前置摄像头 AVCaptureVideoOrientationPortrait。
@property (nonatomic, assign) AVCaptureDevicePosition   captureDevicePosition;

/// 配置摄像头旋转方向。默认为垂直方向 AVCaptureVideoOrientationPortrait。
@property (nonatomic, assign) AVCaptureVideoOrientation videoOrientation;


/// 采集视频的分辨率，默认为 480x640。
@property (nonatomic, copy) NSString *sessionPreset;

/// 采集视频帧率，默认为24。
@property (nonatomic, assign) NSUInteger videoFrameRate;


/// 是否开启美颜
/// @param beautifyModeOn 是否开启
-(void)setBeautifyModeOn:(BOOL)beautifyModeOn;

/// 设置美颜 Beauty 的程度值，范围从 0 ~ 1，0 为不美颜，默认为 0.5。
/// @param beautify 美颜程度
-(void)setBeautify:(CGFloat)beautify;

/// 设置美白 whiten 的程度值，范围从 0 ~ 1，0 为不美白，默认为 0.5。
/// @param whiten 美白程度
-(void)setWhiten:(CGFloat)whiten;

/// 设置红润 redden 的程度值，范围从 0 ~ 1，0 为不红润，默认为 0.5。
/// @param redden 红润值
-(void)setRedden:(CGFloat)redden;

/// 初始化授权进去直播间
/// @param userDic 
///  需要传user_id，
///  nickname，
///  headimg（可选）,
///  enterprise_id 企业id
///   和token=md5(企业secret+userid)
/// @param success success description
/// @param failure failure description
- (void)init:(NSDictionary *)userDic success:(successBloc)success failure:(nullable void (^)(NSError * nullable))failure;



/// 获取直播间商品列表
/// @param liveId 直播间ID
/// @param successBlock successBlock description
/// @param failure failure description
- (void)getProductWithLiveId:(NSString *)liveId successBloc:(successBloc)successBlock failure:(void (^)(NSError * _Nonnull error))failure;


/// 企业下的商品列表
/// @param liveId 直播间id
/// @param enterpriseId 企业id
/// @param successBlock successBlock description
/// @param failure failure description
- (void)getProductListLiveId:(NSString *)liveId withEnterpriseId:(NSString *)enterpriseId successBloc:(successBloc)successBlock failure:(void (^)(NSError * _Nonnull error))failure;


/// 添加商品
/// @param params 商品信息
/// @param successBlock successBlock description
/// @param failure failure description
- (void)getProductSet:(NSDictionary *)params withProducts:(NSMutableArray *)products successBloc:(successBloc)successBlock failure:(void (^)(NSError * _Nonnull error))failure;


/// 上下架商品（对已经添加到列表上的商品）
/// @param successBlock successBlock description
/// @param failure failure description
- (void)getProductReset:(NSDictionary *)params successBloc:(successBloc)successBlock failure:(void (^)(NSError * _Nonnull error))failure;

/// 创建直播间
/// @param successBlock successBlock description
/// @param failure failure description
- (void)getCreateCourse:(NSDictionary *)params successBlock:(successBloc)successBlock failure:(void (^)(NSError * _Nonnull error))failure;


/// 上传创建直播间封面
/// @param successBlock successBlock description
/// @param failure failure description
- (void)getUploadFile:(UIImage *)image successBlock:(successBloc)successBlock failure:(void (^)(NSError * _Nonnull error))failure;


/// 编辑已创建好的直播间
/// @param successBlock successBlock description
/// @param failure failure description
- (void)getModifyCourse:(NSDictionary *)params successBlock:(successBloc)successBlock failure:(void (^)(NSError * _Nonnull error))failure;


/// 点赞
/// @param count 连续点击多次
/// @param success success description
/// @param failure failure description
-(void)doLikeWithCount:(NSInteger)count Action:(successBloc)success failure:(void (^)(NSError * _Nonnull))failure;


/// 置顶商品
/// @param paramars 传入直播id，和商品id
/// @param successBlock successBlock description
/// @param failure failure description
- (void)getProductSetTop:(NSDictionary *)paramars successBloc:(successBloc)successBlock failure:(void (^)(NSError * _Nonnull error))failure;


/// 删除商品
/// @param paramars enterprise_id 企业id 和商品id
/// @param successBlock successBlock description
/// @param failure failure description
- (void)getDelProductSet:(NSDictionary *)paramars successBloc:(successBloc)successBlock failure:(void (^)(NSError * _Nonnull error))failure;

/// 移动商品
/// @param params course_id直播id，id 商品外侧id，product_id商品id，sort_no商品的位置，type: "sort"
/// @param successBlock successBlock description
/// @param failure failure description
- (void)getMoveProductReset:(NSDictionary *)params successBloc:(successBloc)successBlock failure:(void (^)(NSError * _Nonnull error))failure;
    

/// 禁言某人
/// @param params image,nickname,user_id,liveId
/// @param successBlock successBlock description
/// @param failure failure description
- (void)getAddForbidden:(NSDictionary *)params successBloc:(successBloc)successBlock failure:(void (^)(NSError * _Nonnull error))failure;

/// 踢出直播间
/// @param params course_id,直播间id，image头像，nickname昵称，user_id用户id
/// @param successBlock successBlock description
/// @param failure failure description
- (void)getAddKickOut:(NSDictionary *)params successBloc:(successBloc)successBlock failure:(void (^)(NSError * _Nonnull error))failure;

/// 主播禁言所有人
/// @param isMute isMute description
- (void)forbiddenAll:(BOOL)isMute;

/// 黑名单列表
/// @param params liveId直播间id
/// @param successBlock successBlock description
/// @param failure failure description
- (void)getListKickOut:(NSString *)params successBloc:(successBloc)successBlock failure:(void (^)(NSError * _Nonnull error))failure;

/// 移除黑名单
/// @param params 移除黑名单列表中的id
/// @param successBlock successBlock description
/// @param failure failure description
- (void)getDelKickOut:(NSString *)params successBloc:(successBloc)successBlock failure:(void (^)(NSError * _Nonnull error))failure;

/// 禁言列表
/// @param params 直播间id
/// @param successBlock successBlock description
/// @param failure failure description
- (void)getListForbiddenWords:(NSString *)params successBloc:(successBloc)successBlock failure:(void (^)(NSError * _Nonnull error))failure;


/// 解开禁言
/// @param params 禁言列表中的id
/// @param successBlock successBlock description
/// @param failure failure description
- (void)getDelForbiddenWords:(NSString *)params successBloc:(successBloc)successBlock failure:(void (^)(NSError * _Nonnull error))failure;


/// 送礼物排行榜
/// @param params liveId直播间Id
/// @param successBlock successBlock description
/// @param failure failure description
- (void)getRankingGift:(NSString *)params successBloc:(successBloc)successBlock failure:(void (^)(NSError * _Nonnull error))failure;

/// 邀请排行榜
/// @param params liveId直播间Id
/// @param successBlock successBlock description
/// @param failure failure description
- (void)getInvitesList:(NSString *)params withPage:(int)page successBloc:(successBloc)successBlock failure:(void (^)(NSError * _Nonnull))failure;


/// 在线观众列表
/// @param params liveId直播间Id
/// @param successBlock successBlock description
/// @param failure failure description
- (void)getOnLineAudienceList:(NSString *)params withPage:(int)page successBloc:(successBloc)successBlock failure:(void (^)(NSError * _Nonnull))failure;
@end

NS_ASSUME_NONNULL_END
