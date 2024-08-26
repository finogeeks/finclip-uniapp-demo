//
//  FATAppletAuthDelegate.h
//  FinApplet
//
//  Created by tao on 2023/3/27.
//  Copyright © 2023 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FATAppletInfo.h"
#import "FATAuthModel.h"
#import "FATAuthAlertContentViewDelegate.h"


NS_ASSUME_NONNULL_BEGIN

@protocol FATAppletAuthDelegate <NSObject>


/// 小程序申请权限
/// - Parameters:
///   - appletInfo: 小程序信息
///   - authType: 权限类型
///   - scopeScene: 是否是小程序维度的权限申请
///   - grantCompletion: 是否允许的回调
- (void)applet:(FATAppletInfo *)appletInfo
   requestAuth:(FATAuthorizationType)authType
    scopeScene:(BOOL)scopeScene
applyCompletion:(void(^)(BOOL allowApply))grantCompletion;


/// 小程序申请权限的结果
/// - Parameters:
///   - appletInfo: 小程序信息
///   - authType: 申请的权限类型
///   - status: 权限申请的结果
- (void)applet:(FATAppletInfo *)appletInfo didRequestAuth:(FATAuthorizationType)authType withResult:(FATAuthorizationStatus)status;


/// 是否自定义小程序的设置页面
/// - Parameter appletInfo: 小程序信息
- (BOOL)appletCustomizeSettingPage:(FATAppletInfo *)appletInfo;


/// 显示自定义的小程序设置页面
/// - Parameters:
///   - appletInfo: 小程序信息
///   - navigationController: 当前小程序的导航控制器
- (void)applet:(FATAppletInfo *)appletInfo openSettingPageWithNavigationController:(UINavigationController *)navigationController;


/// 小程序的隐私协议弹框文案配置
/// - Parameters:
///   - appletInfo: 小程序信息
///   - authType: 申请的权限类型
///   - completion: 文案信息回调
- (void)applet:(FATAppletInfo *)appletInfo getPrivacyAlertInfo:(FATAuthorizationType)authType completion:(void(^)(FATPrivacyAlertInfo *alertInfo))completion;

/// 小程序的隐私协议自定义配置
/// - Parameters:
///   - appletInfo: 小程序信息
///   - completion: 文案信息回调
- (void)applet:(FATAppletInfo *)appletInfo getCustomPrivacyInfoWithCompletion:(void(^)(FATPrivacyCustomInfo *privacyInfo))completion;

/// 是否自定义隐私协议点击事件
/// 注意：返回值很重要。返回值为true，表示你需要自己实现协议点击行为，不会跳转至SDK内的协议页面；返回值为false，表示走默认的协议点击行为，跳转至SDK内协议页面
/// - Parameters:
///   - appletInfo: 小程序信息
///   - privacyContentInfo: 隐私协议内容信息。docUrl为空时，表示默认的隐私协议。
- (BOOL)applet:(FATAppletInfo *)appletInfo shouldChangePrivacyClickAction:(FATPrivacyContentInfo *)privacyContentInfo;

/// 是否自定义权限申请的弹框内容
/// - Parameters:
///   - appletInfo: 小程序信息
///   - authType: 权限类型
- (BOOL)isAppletCustomizeAuthContentView:(FATAppletInfo *)appletInfo withAuthType:(FATAuthorizationType)authType;


///  获取自定义的权限弹框内容视图，需遵循FATAuthAlertContentViewDelegate协议
/// - Parameters:
///   - appletInfo: 小程序信息
///   - authType: 权限类型
- (UIView<FATAuthAlertContentViewDelegate> *)applet:(FATAppletInfo *)appletInfo getCustomizeAuthContentView:(FATAuthorizationType)authType;

/// 小程序权限变更的代理方法
/// - Parameters:
///   - appletInfo: 小程序信息
///   - authType: 权限类型
///   - status: 权限变更的结果
- (void)AppleAuthChange:(FATAppletInfo *)appletInfo withAuthType:(id)authType withResult:(FATAuthorizationStatus)status;

@end

NS_ASSUME_NONNULL_END
