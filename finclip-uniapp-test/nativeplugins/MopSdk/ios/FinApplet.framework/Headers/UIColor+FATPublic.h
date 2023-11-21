//
//  UIColor+FATPublic.h
//  FinApplet
//
//  Created by Haley on 2022/12/1.
//  Copyright © 2022 finogeeks. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIColor (FATPublic)

/// 将颜色字符串转换为UIColor对象(RRGGBB)，只截取前6位
/// - Parameters:
///   - hexColor: 颜色字符串，支持16进制颜色
///   - alpha: 颜色透明度(0~1)。大于1时，取1；小于0时取0
+ (UIColor *)fat_colorWithRGBHexString:(NSString *)hexString alpha:(CGFloat)alpha;

#pragma mark - rgba hex color
/// 将颜色字符串转换为UIColor对象(RRGGBBAA)
/// 注意：入参字符串需以#开头，颜色可以是6位颜色或8位颜色，无法转换出color对象时，返回nil；
/// 注意：如果是8位16进制颜色，会按照RRGGBBAA来解析r、g、b、a
/// - Parameter hexString: 16进制颜色字符串，支持6位颜色或8位颜色
+ (UIColor *)fat_colorWithRGBAHexString:(NSString *)hexString;

/// 将颜色字符串转换为UIColor对象(RRGGBBAA)
/// 注意：入参字符串需以#开头，颜色可以是6位颜色或8位颜色，无法转换出color对象时，返回nil；
/// 注意：如果是8位16进制颜色，会按照RRGGBBAA来解析r、g、b、a
/// - Parameters:
///   - hexString: 16进制颜色字符串，支持6位颜色或8位颜色
///   - defaultHexString: 默认的16进制颜色，当无法转换出color对象时，会返回defaultHexString转换出color对象
+ (UIColor *)fat_colorWithRGBAHexString:(NSString *)hexString defaultHexString:(NSString *)defaultHexString;

#pragma mark - argb hex color
/// 将颜色字符串转换为UIColor对象(AARRGGBB)。‼️目前input、textarea、video、cover-view、map组件用ARGB格式的16进制颜色
/// 注意：入参字符串需以#开头，颜色可以是6位颜色或8位颜色，无法转换出color对象时，返回nil；
/// 注意：如果是8位16进制颜色，会按照AARRGGBB来解析r、g、b、a
/// - Parameter hexColor: 16进制颜色字符串，支持6位颜色或8位颜色
+ (UIColor *)fat_colorWithARGBHexString:(NSString *)hexString;

/// 将颜色字符串转换为UIColor对象(AARRGGBB)。‼️目前input、textarea、video、cover-view、map组件用ARGB格式的16进制颜色
/// 注意：入参字符串需以#开头，颜色可以是6位颜色或8位颜色，无法转换出color对象时，返回nil；
/// 注意：如果是8位16进制颜色，会按照AARRGGBB来解析r、g、b、a
/// - Parameters:
///   - hexString: 16进制颜色字符串，支持6位颜色或8位颜色
///   - defaultHexString: 默认的16进制颜色，当无法转换出color对象时，会返回defaultHexString转换出color对象
+ (UIColor *)fat_colorWithARGBHexString:(NSString *)hexString defaultHexString:(NSString *)defaultHexString;

@end

