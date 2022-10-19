//
//  FATAppletWaterMaskAndScreenCaptureDelegate.h
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

@protocol FATAppletWaterMaskAndScreenCaptureDelegate <NSObject>

@optional

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

NS_ASSUME_NONNULL_END
