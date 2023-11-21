//
//  UIDevice+FATPublic.h
//  FinApplet
//
//  Created by Haley on 2022/12/1.
//  Copyright © 2022 finogeeks. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIDevice (FATPublic)

/// 设备的分辨率。屏幕宽高 x scale
- (CGSize)fat_actualSize;

/// 设备(转换过的)mode，也就是机型。例如iPhone 11 Pro Max
- (NSString *)fat_deviceMode;

/// 设备的mode，例如iPhone12,5
- (NSString *)fat_mode;

/// 是否是横屏，判断屏幕宽是否大于高
- (BOOL)fat_landscape;

/// 是否是竖屏，判断屏幕高是否大于宽
- (BOOL)fat_portrait;

/**
 判断是否为刘海屏手机
 先判断mode是否为手机，再判断底部安全区域是否大于0
 
 iPhone X Safe Area
 - Top:     +24.0pt
 - Bottom:  +34.0pt
 
 */
- (BOOL)fat_isX;

/// 获取安全区域的顶部和底部的距离
+ (UIEdgeInsets)fat_safeAreaInsets;

@end

