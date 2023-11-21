//
//  FATAppletDelegate.h
//  FinApplet
//
//  Created by Haley on 2019/11/4.
//  Copyright © 2019 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FATAppletMenuProtocol.h"
#import "FATConstant.h"
#import "FATAppletInfo.h"
#import "FATAppletConfig.h"
#import "FATAppletRequest.h"

@protocol FATAppletDelegate <NSObject>

@optional

#pragma mark - lifeCycleDelegate methods

/**
 小程序打开完成的事件
 @param appletId 小程序id
 @param error 错误对象
 */
- (void)applet:(NSString *)appletId didOpenCompletion:(NSError *)error FATDeprecated("该api(自2.36.11起)废弃，请使用appletInfo:didOpenCompletion:");

/**
 小程序关闭完成的事件
 @param appletId 小程序id
 @param error 错误对象
 */
- (void)applet:(NSString *)appletId didCloseCompletion:(NSError *)error FATDeprecated("该api(自2.36.11起)废弃，请使用appletInfo:didCloseCompletion:");

/**
 小程序初始化完成，首页加载出来的事件
 @param appletId 小程序id
 @param error 错误对象
 */
- (void)applet:(NSString *)appletId initCompletion:(NSError *)error FATDeprecated("该api(自2.36.11起)废弃，请使用appletInfo:initCompletion:");

/**
 小程序进入活跃状态的事件
 @param appletId 小程序id
 @param error 错误对象
 */
- (void)applet:(NSString *)appletId didActive:(NSError *)error FATDeprecated("该api(自2.36.11起)废弃，请使用appletInfo:didActive:");

/**
 小程序进入非活跃状态的事件
 @param appletId 小程序id
 @param error 错误对象
 */
- (void)applet:(NSString *)appletId resignActive:(NSError *)error FATDeprecated("该api(自2.36.11起)废弃，请使用appletInfo:resignActive:");

/**
 小程序出错的事件
 @param appletId 小程序id
 @param error 错误对象
 */
- (void)applet:(NSString *)appletId didFail:(NSError *)error FATDeprecated("该api(自2.36.11起)废弃，请使用appletInfo:didFail:");

/**
 小程序被销毁的事件
 @param appletId 小程序id
 @param error 错误对象
 */
- (void)applet:(NSString *)appletId dealloc:(NSError *)error FATDeprecated("该api(自2.36.11起)废弃，请使用appletInfo:dealloc:");

/**
 小程序打开完成的事件
 @param appletInfo 小程序info
 @param error 错误对象
 */
- (void)appletInfo:(FATAppletInfo *)appletInfo didOpenCompletion:(NSError *)error;

/**
 小程序关闭完成的事件
 @param appletInfo 小程序info
 @param error 错误对象
 */
- (void)appletInfo:(FATAppletInfo *)appletInfo didCloseCompletion:(NSError *)error;

/**
 小程序初始化完成，冷启动时首页显示出来的事件
 @param appletInfo 小程序info
 @param error 错误对象
 */
- (void)appletInfo:(FATAppletInfo *)appletInfo initCompletion:(NSError *)error;

/**
 小程序进入活跃状态的事件
 @param appletInfo 小程序info
 @param error 错误对象
 */
- (void)appletInfo:(FATAppletInfo *)appletInfo didActive:(NSError *)error;

/**
 小程序进入非活跃状态的事件
 @param appletInfo 小程序info
 @param error 错误对象
 */
- (void)appletInfo:(FATAppletInfo *)appletInfo resignActive:(NSError *)error;

/**
 小程序出错的事件
 @param appletInfo 小程序info
 @param error 错误对象
 */
- (void)appletInfo:(FATAppletInfo *)appletInfo didFail:(NSError *)error;

/**
 小程序被销毁的事件
 @param appletInfo 小程序info
 @param error 错误对象
 */
- (void)appletInfo:(FATAppletInfo *)appletInfo dealloc:(NSError *)error;

#pragma mark - button open-type

/** 转发事件
 当你点击小程序右上角更多里的转发菜单，或者 点击open-type属性为share的Button时，会触发小程序里shareAppMessage方法，然后回调到原生该方法
 @param contentInfo 小程序相关信息，里面包含小程序id、小程序名称、小程序图标、小程序截图（5：4）等。
 {
    appAvatar = "小程序图标地址";
    logoImage=UIImage对象，只有本地小程序且设置了该参数时，才包含。
    appDescription = "小程序的描述信息";
    appId = "小程序id";
    appInfo =  {}; // 客户可在appInfo中自定义字段，appInfo内容会透传
    appStartParams =     {
        path = "点击转发时的小程序页面路径";
    };
    appThumbnail = "小程序封面图的路径，可能是网络路径或者本地路径，宽高比是5:4";
    appTitle = "小程序名称";
    userId = "小程序开发者id";
}
 @param completion 执行完后的回调，如果你转发操作执行完后，希望告知小程序端转发结果，就需要调用该block。
 参考链接：https://www.finclip.com/mop/document/develop/component/form.html#button
 */
- (void)forwardAppletWithInfo:(NSDictionary *)contentInfo completion:(void (^)(FATExtensionCode code, NSDictionary *result))completion;

/**
 调用获取用户信息API（getUserInfo） 或者 点击open-type属性为getUserInfo的Button时触发
 @param appletInfo 小程序信息
 result参考格式如下（可由宿主App自定义）：
 {
    nickName = "昵称"
    avatarUrl = “头像地址”
    gender = "性别"
    province = "省份"
    city = "城市"
    country = "国家"
    userId = "值为[FATClient sharedClient].config.currentUserId" // sdk默认添加
    baseUrl = "值为appletInfo.apiServer" //// sdk默认添加
 }
 参考链接：https://www.finclip.com/mop/document/develop/component/form.html#button
*/
- (NSDictionary *)getUserInfoWithAppletInfo:(FATAppletInfo *)appletInfo
    FATDeprecated("该api(自2.38.0起)废弃，请使用getUserInfoWithAppletInfo:bindGetUserInfo:");

/**
 调用获取用户信息API（getUserInfo） 或者 点击open-type属性为getUserInfo的Button时触发
 @param appletInfo 小程序信息
 @param bindGetUserInfo 获取用户信息回调
 result参考格式如下（可由宿主App自定义）：
 {
    nickName = "昵称"
    avatarUrl = “头像地址”
    gender = "性别"
    province = "省份"
    city = "城市"
    country = "国家"
    userId = "值为[FATClient sharedClient].config.currentUserId" // sdk默认添加
    baseUrl = "值为appletInfo.apiServer" //// sdk默认添加
 }
 参考链接：https://www.finclip.com/mop/document/develop/component/form.html#button
*/
- (void)getUserInfoWithAppletInfo:(FATAppletInfo *)appletInfo bindGetUserInfo:(void (^)(NSDictionary *result))bindGetUserInfo;

/**
 Button open-type属性为contact，打开客服会话。
 @param appletInfo 小程序信息
 @param sessionFrom 会话来源
 @param sendMessageTitle 会话内消息卡片标题
 @param sendMessagePath 会话内消息卡片点击跳转小程序路径
 @param sendMessageImg 会话内消息卡片图片
 @param showMessageCard 小程序信息
 参考链接：https://www.finclip.com/mop/document/develop/component/form.html#button
 */
- (void)contactWithAppletInfo:(FATAppletInfo *)appletInfo sessionFrom:(NSString *)sessionFrom sendMessageTitle:(NSString *)sendMessageTitle sendMessagePath:(NSString *)sendMessagePath sendMessageImg:(NSString *)sendMessageImg showMessageCard:(BOOL)showMessageCard;

/**
 Button open-type属性为getPhoneNumber，获取用户手机号。
 @param appletInfo 小程序信息
 @param bindGetPhoneNumber 获取用户手机号回调
 result参考格式如下（可由宿主App自定义）：
 {
    detail = {
        code = ""换取用户手机号的动态令牌" // 这里参考微信小程序的数据格式，如果宿主app不支持动态令牌功能，可以自定义格式
    }
 }
 参考链接：https://www.finclip.com/mop/document/develop/component/form.html#button
*/
- (void)getPhoneNumberWithAppletInfo:(FATAppletInfo *)appletInfo bindGetPhoneNumber:(void (^)(NSDictionary *result))bindGetPhoneNumber;

/**
 Button open-type属性为launchApp，打开APP。
 @param appletInfo 小程序信息
 @param appParameter 打开 APP 时，向 APP 传递的参数
 @param bindError 打开 APP 发生错误的回调
 result参考格式如下（可由宿主App自定义）：
 {
    detail = {
        errMsg = "错误描述"
    }
 }
 @param bindLaunchApp 打开 APP 成功的回调
 参考链接：https://www.finclip.com/mop/document/develop/component/form.html#button
 */
- (void)launchAppWithAppletInfo:(FATAppletInfo *)appletInfo appParameter:(NSString *)appParameter bindError:(void (^)(NSDictionary *result))bindError bindLaunchApp:(void (^)(NSDictionary *result))bindLaunchApp;

/// Button open-type属性为feedback，打开“意见反馈”页面。（APP 未实现时，则打开菜单栏里面的反馈）
/// @param appletInfo 小程序信息
/// 参考链接：https://www.finclip.com/mop/document/develop/component/form.html#button
- (void)feedbackWithAppletInfo:(FATAppletInfo *)appletInfo;

/**
 Button open-type属性为chooseAvatar，获取用户头像。
 @param appletInfo 小程序信息
 @param bindChooseAvatar 获取用户头像回调
 result参考格式如下（可由宿主App自定义）：
 {
    detail = {
        avatalUrl = "头像地址"
    }
 }
 参考链接：https://www.finclip.com/mop/document/develop/component/form.html#button
 */
- (void)chooseAvatarWithAppletInfo:(FATAppletInfo *)appletInfo bindChooseAvatar:(void (^)(NSDictionary *result))bindChooseAvatar;


#pragma mark - more menu

/**
 右上角胶囊中 【...】的点击事件，可在该事件中弹出自己设计的更多视图。
 因此实现了该代理事件，就不会触发下面两个自定义菜单的事件
 @param appletInfo 小程序信息
 @path 小程序页面路径，示例：pages/index/index
 */
- (void)applet:(FATAppletInfo *)appletInfo didClickMoreBtnAtPath:(NSString *)path FATDeprecated("该api(自2.37.1起)废弃，请使用appletInfo:didClickMoreBtnAtPath:");

/**
 右上角胶囊中 【...】的点击事件，如果返回YES，代表需要自定义菜单视图。
 您需要再该方法内弹出菜单视图。当自定义菜单视图，就不会触发下面两个自定义菜单的事件了
 @param appletInfo 小程序信息
 @param path 小程序页面路径，示例：pages/index/index
 */
- (BOOL)appletInfo:(FATAppletInfo *)appletInfo didClickMoreBtnAtPath:(NSString *)path;

/**
 更多按钮中自定义的菜单，会在页面弹出菜单时调用该api
 @param appletInfo 小程序信息
 @param path 页面路径
 */
- (NSArray<id<FATAppletMenuProtocol>> *)customMenusInApplet:(FATAppletInfo *)appletInfo atPath:(NSString *)path;

/**
 点击自定义菜单时，会触发的事件（新版）
 只有实现了该代理方法，才会触发【-clickCustomItemMenuWithInfo:completion:】
 @param contentInfo 分享信息
 @param appletInfo 小程序信息
 @param completion 分享回调（预留，暂时无用）
 */
- (void)clickCustomItemMenuWithInfo:(NSDictionary *)contentInfo inApplet:(FATAppletInfo *)appletInfo completion:(void (^)(FATExtensionCode code, NSDictionary *result))completion;

#pragma mark - Local Applet
/**
 触发打开其他本地小程序的请求事件
 该事件只有离线小程序才会触发。
 @param appletInfo 小程序对象
 @param request 小程序request对象，应该直接使用该request对象，不要创建新的对象。
 @param currentVC 当前小程序的顶层视图控制器
 @param completion 打开小程序完毕的回调
 */
- (void)applet:(FATAppletInfo *)appletInfo
    navigateToMiniProgram:(FATLocalAppletRequest *)request
                currentVC:(UIViewController *)currentVC
               completion:(void (^)(FATExtensionCode code, NSDictionary *result))completion;

/**
 本地小程序从宿主App获取zip分包路径（适用于小程序分包加载，小程序分包加载必须实现）
 如果有多个小程序的分包放在app包中，为了避免zip分包同名，可以将不同小程序的分包放在不同文件夹中，
 并通过create folder references方式引入，代码中通过 文件夹名称/分包名.zip 方式获取分包
 @param appletInfo 小程序信息
 @param packDict 分包信息
 @param zipPathCallback zip分包路径回调，路径获取失败调用 zipPathCallback(nil)
 */
- (void)localApplet:(FATAppletInfo *)appletInfo packDict:(NSDictionary *)packDict zipPathCallback:(void (^)(NSString *zipPath))zipPathCallback FATDeprecated("该api(自2.40.3起)废弃，请使用  FATLocalAppletDelegate 中的localApplet:loadPackage:zipFileCallback");

/// 获取本地小程序账号信息
/// @brief 获取本地小程序账号信息，返回的信息结构:
/// @{
///     @"miniProgram": @{
///         @"appId": ##小程序appId##,
///         @"envVersion": ##小程序版本##,
///         @"version": ##线上小程序版本号##
///     },
///     @"plugin": @{
///         @"appId": ##插件appId##,
///         @"version": ##插件版本号##
///     }
/// }
/// @param appletInfo 小程序信息
/// @return 小程序账号信息
- (NSDictionary *)localAppletAccountInfo:(FATAppletInfo *)appletInfo FATDeprecated("该api(自2.42.3起)废弃");

#pragma mark-- 小程序配置

/// 设置小程序的Cookie
/// @param appletId 小程序id
- (NSDictionary *)getCookieWithAppletInfo:(NSString *)appletId;

/// 给小程序设置配置项,使用场景：需要给某个特定小程序设置特殊配置项
/// @param appletInfo 小程序信息
- (FATAppletConfig *)getConfigWithAppletInfo:(FATAppletInfo *)appletInfo;

/// 小程序灰度扩展参数
/// @param appletId 小程序id
- (NSDictionary *)grayExtensionWithAppletId:(NSString *)appletId;

#pragma mark - JS SDK
/// 验证 js-sdk config信息 (未实现该代理方法则默认为验证通过)
/// @param  appletInfo   小程序信息
/// @param  config  验证信息
/// @param  completion  执行完后的回调，验证通过则code返回FATExtensionCodeSuccess，失败返回FATExtensionCodeFailure
- (void)applet:(FATAppletInfo *)appletInfo
 onJSSDKConfig:(NSDictionary *)config
    completion:(void (^)(FATExtensionCode code, NSDictionary *result))completion;

#pragma mark - H5 hook events
/**
 小程序H5中发出的request包含body时会触发该事件
 requestInfo 中会包含
 bodyType: body内容的类型
 requestHref: request做在页面的链接
 requestId：请求id，每次请求都会构造，后续拦截请求时，可在query参数中通过FinClipHookBridge-RequestId匹配
 requestUrl：发起request时，请求的地址。
 value: request的body内容。
 示例
 {
     bodyType = String;
     requestHref = "http://aaronly.gitee.io/aymj";
     requestId = 16499170263357297;
     requestUrl = "https://www.finclip.com/api/v1/mop/mop-fast-trial-manager/web/visits/statistics";
     value = "{\"type\":\"download_click\"}";
 };
 */
- (void)applet:(FATAppletInfo *)appletInfo hookRequestInfo:(NSDictionary *)requestInfo;

#pragma mark - screen capture
/// 录屏事件回调
/// @param appletInfo  录屏事件时，当前正在运行的小程序
/// @param isCapture  是否在录制屏幕
/// @param pagePath  录屏事件时，小程序当前的页面路径
- (void)applet:(FATAppletInfo *)appletInfo screenCaptureStatusChanged:(BOOL)isCapture atPagePath:(NSString *)pagePath;

/// 截屏事件回调
/// @param appletInfo 截屏时，当前正在运行的小程序
/// @param pagePath  截屏时，小程序当前的页面路径
- (void)appletDidTakeScreenshot:(FATAppletInfo *)appletInfo atPagePath:(NSString *)pagePath;

#pragma mark - watermask

/// 自定义添加水印
/// @param appletInfo 小程序信息
/// @param watermaskView 水印容器视图，可在这个视图添加文字或图片等水印内容
- (void)applet:(FATAppletInfo *)appletInfo customizeWatermarkView:(UIView *)watermaskView;

@end
