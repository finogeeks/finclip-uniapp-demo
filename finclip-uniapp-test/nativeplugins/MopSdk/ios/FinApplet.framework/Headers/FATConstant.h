//
//  FATConstant.h
//  FinApplet
//
//  Created by Haley on 2019/3/29.
//  Copyright © 2019 finogeeks. All rights reserved.
//

#ifndef FATConstant_h
#define FATConstant_h

// 过期提醒
#define FATDeprecated(DESCRIPTION) __attribute__((deprecated(DESCRIPTION)))

typedef NS_ENUM(NSInteger, FATExtensionCode) {
    FATExtensionCodeCancel = -1, //取消，(该枚举值(自2.40.5)废弃，因作用与Failure一致，请使用Failure)
    FATExtensionCodeSuccess = 0, //成功
    FATExtensionCodeFailure = 1, //失败
};

typedef NS_ENUM(NSUInteger, FATTranstionStyle) {
    FATTranstionStyleUp,   // 页面从下往上弹出，类似present效果
    FATTranstionStylePush, // 页面从右往左弹出，类似push效果
};

//小程序热启动时的reLaunch模式.
//小程序热启动时，有的情况下会触发reLaunch，即清空小程序页面栈，创建新的页面入栈。
//例如：小程序已经打开了3个页面，此时点击右上角关闭，再次打开小程序时，传入了不同的path和query。
//此时会清空页面栈，再把目标页面入栈，此时页面栈内只有1个页面。
typedef NS_ENUM(NSUInteger, FATReLaunchMode) {
    FATReLaunchModeParamsExist,  //只要有启动参数(即包含path 或query)，就执行reLaunch.
    FATReLaunchModeOnlyParamsDiff, //有启动参数，且启动参数与上一次的启动参数不同时，才执行reLaunch.
    FATReLaunchModeAlways, //忽略启动参数，每次热启动均执行reLaunch
    FATReLaunchModeNever   //每次热启动均不执行reLaunch，即热启动永远复用页面栈
};


typedef NS_ENUM(NSUInteger, FATApiCryptType) {
    FATApiCryptTypeMD5, // MD5
    FATApiCryptTypeSM,  // 国密MD5
};

typedef NS_ENUM(NSUInteger, FATMoreViewStyle) {
    FATMoreViewStyleDefault,
    FATMoreViewStyleNormal,
    FATMoreViewStylePage  //分页显示菜单，2.43.9添加
};

typedef NS_ENUM(NSUInteger, FATAppletMenuStyle) {
    FATAppletMenuStyleCommon = 0,
    FATAppletMenuStyleOnMiniProgram
};

typedef NS_ENUM(NSUInteger, FATInterfaceOrientation) {
    FATInterfaceOrientationPortrait = 0, //竖屏
    FATInterfaceOrientationLandscape,    //横屏
    FATInterfaceOrientationAllButUpsideDown, //横竖屏都支持
    FATInterfaceOrientationNone = 10 //空值，未设置
};

typedef NS_ENUM(NSInteger, FATConfigPriority) {
    FATConfigGlobalPriority = 0, //全局配置优先
    FATConfigSpecifiedPriority,  // 单个配置优先
    FATConfigAppletFilePriority, // 小程序配置文件优先，小程序app.ext.json文件中配置
};

typedef NS_ENUM(NSUInteger, FATCrashProtectionType) {
    FATCrashProtectionTypeNone = 0,
    FATCrashProtectionTypeUnrecognizedSelector = 1 << 1,
    FATCrashProtectionTypeKVOCrash = 1 << 2,
    FATCrashProtectionTypeTimerCrash = 1 << 3,
    FATCrashProtectionTypeNotificationCrash = 1 << 4,
    FATCrashProtectionTypeContainerCrash = 1 << 5,
    FATCrashProtectionTypeStringCrash = 1 << 6,
    FATCrashProtectionTypeJSONSerializationCrash = 1 << 7,

    FATCrashProtectionTypeAll = FATCrashProtectionTypeUnrecognizedSelector | FATCrashProtectionTypeKVOCrash | FATCrashProtectionTypeTimerCrash | FATCrashProtectionTypeNotificationCrash | FATCrashProtectionTypeContainerCrash | FATCrashProtectionTypeStringCrash | FATCrashProtectionTypeJSONSerializationCrash
};

typedef NS_ENUM(NSUInteger, FATAppletVersionType) {
    FATAppletVersionTypeRelease,     // 正式版，默认值
    FATAppletVersionTypeTrial,       // 体验版
    FATAppletVersionTypeTemporary,   // 临时版，IDE预览版
    FATAppletVersionTypeRemoteDebug, // 远程调试版
    FATAppletVersionTypeReview,      // 审核版
    FATAppletVersionTypeDevelopment, // 开发版
    FATAppletVersionTypeUnknown = 999// 未知版本
};

typedef NS_ENUM(NSUInteger, FATAppletLifeCycle) {
    FATAppletLifeCycleUnknow,     // 未知阶段
    FATAppletLifeCycleLaunch,     // 启动阶段
    FATAppletLifeCycleActive,     // 运行阶段
    FATAppletLifeCycleBackground, // 后台阶段
};

typedef NS_ENUM(NSUInteger, FATLogLevel) {
    FATLogLevelError,   // 设置为该等级，将会记录ERROR级别的日志
    FATLogLevelWarning, // 设置为该等级，将会记录ERROR和WARNING级别的日志
    FATLogLevelInfo,    // 设置为该等级，将会记录ERROR、WARNING和INFO级别的日志
    FATLogLevelDebug,   // 设置为该等级，将会记录ERROR、WARING、INFO和DEBUG级别的日志
    FATLogLevelVerbose  // 设置为该等级，将会记录ERROR、WARING、INFO、DEBUG和VERBOSE级别的日志
};

typedef NS_ENUM(NSUInteger, FATConsoleLevel) {
    FATConsoleLevelLog,     // vConsole日志级别为Log
    FATConsoleLevelWarn,    // vConsole日志级别为Warn
    FATConsoleLevelError,   // vConsole日志级别为Error
    FATConsoleLevelInfo     // vConsole日志级别为Info
};

typedef NS_ENUM(NSUInteger, FATBOOLState) {
    FATBOOLStateUndefined, // 未设置
    FATBOOLStateTrue,      // 所有版本强制开启vconsole，且不可调api关闭
    FATBOOLStateFalse,     // 正式版更多面板不展示打开、关闭调试菜单；所有版本均可调setEnableDebug开启vconsole。
    FATBOOLStateForbidden, // 所有版本强制关闭vconsole，且不可调api开启
};

typedef NS_ENUM(NSUInteger, FATAppletDebugMode) {
    FATAppletDebugModeDefault,       // 默认情况的设置，跟微信效果一样
    FATAppletDebugModeEnable,       // 所有版本强制开启vconsole，且不可关闭(方便调试，应该只在开发阶段使用该类型)
    FATAppletDebugModeForbidden,    // 所有版本强制关闭vconsole，且不可开启
    FATAppletDebugModeForbiddenRelease,  // 正式版本小程序强制关闭vconsole，且不可开启，其他版本小程序可自行开启关闭
};

typedef NS_ENUM(NSUInteger, FATProjectType) {
    FATProjectTypeMiniprogram = 0,  // 小程序类型
    FATProjectTypeMinigame,         // 小游戏类型
    FATProjectTypeWidget,           //小组件类型
    FATProjectTypeHTML5 = 3,             // HTML5类型
};
typedef NS_ENUM(NSInteger, FATPageTitleAlignment) {
    FATPageTitleAlignmentCenter    = 0,    // 标题居中
    FATPageTitleAlignmentLeft      = 1,    // 标题居左
};


typedef NS_ENUM(NSInteger, FATUserInterfaceStyle) {
    FATUserInterfaceLight   = 0,    // 浅色模式
    FATUserInterfaceDark    = 1,    // 深色模式
    FATUserInterfaceAuto    = 2,    // 主题模式跟随系统
};

typedef NS_ENUM(NSInteger, FATFinFilePathType) {
    FATFinFilePathTmp    = 0,    // tmp目录
    FATFinFilePathStore    = 1,    // store目录
    FATFinFilePathUsr    = 2,    // usr目录
};


typedef NS_ENUM(NSInteger, FATAuthDescStrategy) {
    FATAuthDescStrategyNone   = 0,    // 默认方式，小程序有配置权限说明，显示配置的，没配置则不显示
    FATAuthDescStrategyShowDefault    = 1,    // 小程序有配置权限说明，显示配置的，没配置显示内置的权限信息
    FATAuthDescStrategyForbidden     = 2,    //没有设置，不允许申请权限；申请权限会优先判断是否有配置权限描述，没有配置则不允许申请权限，即使设置了自动授权，同时权限申请前置代理方法也不会触发
};


/**
 扩展API处理后的回调
 
 @param code 处理结果码
 @param result 处理结果数据
 */
typedef void (^FATExtensionApiCallback)(FATExtensionCode code, NSDictionary<NSString *, id> *result);

#pragma mark - 启动小程序时的启动参数
typedef NSString *FATStartParamKey NS_REFINED_FOR_SWIFT;

FOUNDATION_EXTERN FATStartParamKey const FATStartParamPath;
FOUNDATION_EXTERN FATStartParamKey const FATStartParamQuery;
FOUNDATION_EXTERN FATStartParamKey const FATStartParamScene;

typedef NSString *FATShareMediaType NS_REFINED_FOR_SWIFT;

FOUNDATION_EXTERN FATShareMediaType const FATShareMediaTypeText;
FOUNDATION_EXTERN FATShareMediaType const FATShareMediaTypeImage;
FOUNDATION_EXTERN FATShareMediaType const FATShareMediaTypeMusic;
FOUNDATION_EXTERN FATShareMediaType const FATShareMediaTypeVideo;
FOUNDATION_EXTERN FATShareMediaType const FATShareMediaTypeWebPage;
FOUNDATION_EXTERN FATShareMediaType const FATShareMediaTypeMiniProgram;


#pragma mark - 小程序网络请求进度回调

typedef NSString *FATNetworkProcessKey NS_REFINED_FOR_SWIFT;

FOUNDATION_EXTERN FATNetworkProcessKey const FATTotalBytesWritten;
FOUNDATION_EXTERN FATNetworkProcessKey const FATTotalBytesExpectedToWrite;
FOUNDATION_EXTERN FATNetworkProcessKey const FATTotalBytesSent;
FOUNDATION_EXTERN FATNetworkProcessKey const FATTotalBytesExpectedToSend;
FOUNDATION_EXTERN FATNetworkProcessKey const FATProgress;
FOUNDATION_EXTERN FATNetworkProcessKey const FATHeader;
FOUNDATION_EXTERN FATNetworkProcessKey const FATTaskId;


//权限类型
typedef NS_ENUM(NSInteger, FATAuthorizationType) {
    FATAuthorizationTypePhoto = 0,
    FATAuthorizationTypeCamera = 1,
    FATAuthorizationTypeMicrophone = 2,
    FATAuthorizationTypeLocation = 3,
    FATAuthorizationTypeBluetooth = 4,
    FATAuthorizationTypeAddressBook = 5,
    FATAuthorizationTypeUserProfile = 6,
    FATAuthorizationTypePhoneNumber = 7,
    FATAuthorizationTypeLocationBackground = 8,
    FATAuthorizationTypeCalendar = 9,
    FATAuthorizationTypeCustom = 10
};

//权限申请结果
typedef NS_ENUM(NSInteger, FATAuthorizationStatus) {
    FATAuthorizationStatusAuthorized = 0,  //允许
    FATAuthorizationStatusDenied = 1,      //拒绝
    FATAuthorizationStatusAppDenied = 2,   //app拒绝
    FATAuthorizationStatusAuthorizedBackgroud = 3, // 允许后台定位
};

//权限类型
typedef NSString *FATScopeName NS_REFINED_FOR_SWIFT;
FOUNDATION_EXTERN FATScopeName const FATScopeNamePhoto;         //相册
FOUNDATION_EXTERN FATScopeName const FATScopeNameCamera;        //相机
FOUNDATION_EXTERN FATScopeName const FATScopeNameMicrophone;    //麦克风
FOUNDATION_EXTERN FATScopeName const FATScopeNameLocation;      //位置
FOUNDATION_EXTERN FATScopeName const FATScopeNameBackgroundLoaction; //后台定位
FOUNDATION_EXTERN FATScopeName const FATScopeNameBluetooth;     //蓝牙
FOUNDATION_EXTERN FATScopeName const FATScopeNameAddressBook;   //通讯录
FOUNDATION_EXTERN FATScopeName const FATScopeNameUserProfile;   //用户信息
FOUNDATION_EXTERN FATScopeName const FATScopeNamePhoneNumber;   //手机号
FOUNDATION_EXTERN FATScopeName const FATScopeNameCalendar;   //日历





// SDK支持的语言
typedef NSString *FATPreferredLanguage NS_REFINED_FOR_SWIFT;

FOUNDATION_EXTERN FATPreferredLanguage const FATPreferredLanguageSimplifiedChinese; // 简体中文
FOUNDATION_EXTERN FATPreferredLanguage const FATPreferredLanguageEnglish;       // 英文

/// 本地缓存的最近使用的小程序列表变更
FOUNDATION_EXTERN NSString *const kRecentUsedAppletListDidChangeNotification;

#pragma mark - 小程序生命周期事件通知

/// 小程序关闭通知，ViewController和View可以监听 userInfo:@{@"appletId":appId}
FOUNDATION_EXTERN NSString *const FATAppletCloseNotification;

/// 小程序重启的通知  userInfo:@{@"appletId":appId}
FOUNDATION_EXTERN NSString *const FATAppletResetNotification;

/// 小程序进入后台 ViewController和View可以监听 userInfo:@{@"appletId":appId}
FOUNDATION_EXTERN NSString *const FATAppletEnterBackgroundNotification;

/// 小程序进入前台 ViewController和View可以监听 userInfo:@{@"appletId":appId}
FOUNDATION_EXTERN NSString *const FATAppletForegroundNotification;

/// 小程序热启动触发relaunch的通知(只有小程序)    userInfo:@{@"appletId":appId}
FOUNDATION_EXTERN NSString *const FATAppletRelaunchNotification;

/// 小程序被销毁的通知    userInfo:@{@"appletId":appId}
FOUNDATION_EXTERN NSString *const FATAppletDestroyNotification;

/// 小程序页面消失的事件  userInfo:@{@"appletId":appId,@"pageId":@(pageId)}
FOUNDATION_EXTERN NSString *const kFATPageDidDisappearNotification;

// 小程序页面WKWebview进程被中止的通知
FOUNDATION_EXTERN NSString *const kFATPageWebviewProcessTerminateNotification;

#endif /* FATConstant_h */
