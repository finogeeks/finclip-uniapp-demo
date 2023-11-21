//
//  FATAppletButtonOpenTypeDelegate.h
//  FinApplet
//
//  Created by 王兆耀 on 2022/8/31.
//

#import <Foundation/Foundation.h>
#import "FATAppletMenuProtocol.h"
#import "FATConstant.h"
#import "FATAppletInfo.h"
#import "FATAppletConfig.h"
#import "FATAppletRequest.h"

NS_ASSUME_NONNULL_BEGIN

@protocol FATAppletButtonOpenTypeDelegate <NSObject>

@optional

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
- (BOOL)forwardAppletWithInfo:(NSDictionary *)contentInfo completion:(void (^)(FATExtensionCode code, NSDictionary *result))completion;

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
- (BOOL)getUserInfoWithAppletInfo:(FATAppletInfo *)appletInfo bindGetUserInfo:(void (^)(NSDictionary *result))bindGetUserInfo;

/**
 调用获取用户信息API（getUserProfile）
 @param appletInfo 小程序信息
 @param bindGetUserProfile 获取用户信息回调
 result参考格式如下（可由宿主App自定义）：
{
    code = 0c19xo000DiCWP1qgw2000xlSi49xo0u;
    userInfo =  {
         nickName = "昵称"
         avatarUrl = “头像地址”
         gender = "性别"
         province = "省份"
         city = "城市"
         country = "国家"
         is_demote = 1
         language = ""
        }
}
 参考链接：https://www.finclip.com/mop/document/develop/component/form.html#button
*/
- (BOOL)getUserProfileWithAppletInfo:(FATAppletInfo *)appletInfo bindGetUserProfile:(void (^)(NSDictionary *result))bindGetUserProfile;

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
- (BOOL)contactWithAppletInfo:(FATAppletInfo *)appletInfo sessionFrom:(NSString *)sessionFrom sendMessageTitle:(NSString *)sendMessageTitle sendMessagePath:(NSString *)sendMessagePath sendMessageImg:(NSString *)sendMessageImg showMessageCard:(BOOL)showMessageCard;

/**
 Button open-type属性为getPhoneNumber，获取用户手机号。
 @param appletInfo 小程序信息
 @param bindGetPhoneNumber 获取用户手机号回调
 result参考格式如下（可由宿主App自定义）：
 {
    detail = {
        code = ""换取用户手机号的动态令牌" // 这里参考微信小程序的数据格式，如果宿主app不支持动态令牌功能，可以自定义格式
    }
    errMsg = "如果想触发失败，则需要添加 errMsg 字段"
 }
 参考链接：https://www.finclip.com/mop/document/develop/component/form.html#button
*/
- (BOOL)getPhoneNumberWithAppletInfo:(FATAppletInfo *)appletInfo bindGetPhoneNumber:(void (^)(NSDictionary *result))bindGetPhoneNumber;

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
- (BOOL)launchAppWithAppletInfo:(FATAppletInfo *)appletInfo appParameter:(NSString *)appParameter bindError:(void (^)(NSDictionary *result))bindError bindLaunchApp:(void (^)(NSDictionary *result))bindLaunchApp;

/// Button open-type属性为feedback，打开“意见反馈”页面。（APP 未实现时，则打开菜单栏里面的反馈）
/// @param appletInfo 小程序信息
/// 参考链接：https://www.finclip.com/mop/document/develop/component/form.html#button
- (BOOL)feedbackWithAppletInfo:(FATAppletInfo *)appletInfo;

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
- (BOOL)chooseAvatarWithAppletInfo:(FATAppletInfo *)appletInfo bindChooseAvatar:(void (^)(NSDictionary *result))bindChooseAvatar;

@end

NS_ASSUME_NONNULL_END
