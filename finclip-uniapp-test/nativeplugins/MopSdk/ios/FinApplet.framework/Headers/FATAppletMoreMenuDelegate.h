//
//  FATAppletMoreMenuDelegate.h
//  FinApplet
//
//  Created by 王兆耀 on 2022/9/1.
//  Copyright © 2022 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FATAppletMenuProtocol.h"
#import "FATConstant.h"
#import "FATAppletInfo.h"
#import "FATAppletConfig.h"
#import "FATAppletRequest.h"

NS_ASSUME_NONNULL_BEGIN

@protocol FATAppletMoreMenuDelegate <NSObject>

@optional

/**
 右上角胶囊中 【...】的点击事件，可在该事件中弹出自己设计的更多视图。
 因此实现了该代理事件，就不会触发下面两个自定义菜单的事件
 @param appletInfo 小程序信息
 @path 小程序页面路径，示例：pages/index/index
 */
- (void)applet:(FATAppletInfo *)appletInfo didClickMoreBtnAtPath:(NSString *)path FATDeprecated("该api(自2.37.1起)废弃，请使用appletInfo:didClickMoreBtnAtPath:");

#pragma mark - more menu
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
 @param completion 分享回调（小程序分享回调：1.【code】回调状态码；2.【result】回传给小程序的回调信息）
 */
- (void)clickCustomItemMenuWithInfo:(NSDictionary *)contentInfo inApplet:(FATAppletInfo *)appletInfo completion:(void (^)(FATExtensionCode code, NSDictionary *result))completion;

@end

NS_ASSUME_NONNULL_END
