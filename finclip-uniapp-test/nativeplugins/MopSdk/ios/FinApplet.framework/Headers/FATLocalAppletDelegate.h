//
//  FATLocalAppletDelegate.h
//  FinApplet
//
//  Created by 王兆耀 on 2022/9/3.
//  Copyright © 2022 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FATAppletMenuProtocol.h"
#import "FATConstant.h"
#import "FATAppletInfo.h"
#import "FATAppletConfig.h"
#import "FATAppletRequest.h"

NS_ASSUME_NONNULL_BEGIN

@protocol FATLocalAppletDelegate <NSObject>

@optional

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
- (void)localApplet:(FATAppletInfo *)appletInfo packDict:(NSDictionary *)packDict zipPathCallback:(void (^)(NSString *zipPath))zipPathCallback;

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
- (NSDictionary *)localAppletAccountInfo:(FATAppletInfo *)appletInfo;

@end

NS_ASSUME_NONNULL_END
