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

typedef NS_ENUM(NSUInteger, FATApiCryptType) {
    FATApiCryptTypeMD5, // MD5
    FATApiCryptTypeSM,  // 国密MD5
};

typedef NS_ENUM(NSUInteger, FATMoreViewStyle) {
    FATMoreViewStyleDefault,
    FATMoreViewStyleNormal
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
    FATProjectTypeHTML5 = 3,             // HTML5类型
};
typedef NS_ENUM(NSInteger, FATPageTitleAlignment) {
    FATPageTitleAlignmentCenter    = 0,    // 标题居中
    FATPageTitleAlignmentLeft      = 1,    // 标题居左
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
    FATAuthorizationTypeCalendar = 9
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

// 小程序进入前台 ViewController和View可以监听 userInfo:@{@"appletId":appId}
FOUNDATION_EXTERN NSString *const FATAppletForegroundNotification;


/// 小程序被销毁的通知    userInfo:@{@"appletId":appId}
FOUNDATION_EXTERN NSString *const FATAppletDestroyNotification;

/// 小程序页面消失的事件  userInfo:@{@"appletId":appId,@"pageId":@(pageId)}
FOUNDATION_EXTERN NSString *const kFATPageDidDisappearNotification;

#endif /* FATConstant_h */
