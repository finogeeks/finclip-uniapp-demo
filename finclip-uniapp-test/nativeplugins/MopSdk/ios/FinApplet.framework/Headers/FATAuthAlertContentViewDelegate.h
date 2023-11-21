//
//  FATAuthAlertContentViewDelegate.h
//  FinApplet
//
//  Created by 滔 on 2023/5/24.
//  Copyright © 2023 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol FATAuthAlertContentViewDelegate <NSObject>

@required
/// 返回自定义权限弹框内容的高度(横屏或竖屏)
/// - Parameter isPortrait: 是否是竖屏
- (CGFloat)contentHeight:(BOOL)isPortrait;


/// 自定义权限弹框内容的权限申请结果回调(允许/拒绝或其他按钮点击)  result : 0 拒绝 1: 允许(如果是后台定位权限，表示使用小程序时允许后台定位)，2: 后台定位权限时使用( 使用小程序时和离开后)
@property (nonatomic, copy) void(^authCompleteHandler)(NSInteger result);

@optional

//是否隐藏权限标题和描述
-(BOOL)hideAuthTitleAndDesc;

//是否隐藏权限弹框底部的允许和拒绝按钮
-(BOOL)hideBottomActionButton;

//是否隐藏后台定位的选项列表
- (BOOL)hideLocationSelectListView;

@end

NS_ASSUME_NONNULL_END
