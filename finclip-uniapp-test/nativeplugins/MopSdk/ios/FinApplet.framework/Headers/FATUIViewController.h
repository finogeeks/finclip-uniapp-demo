//
//  FATUIViewController.h
//  FinApplet
//
//  Created by Haley on 2022/12/28.
//  Copyright © 2022 finogeeks. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FATConstant.h"

@interface FATUIViewController : UIViewController

//计算状态栏的高度，需在viewWillLayoutSubviews中调用才会返回准确值
- (CGFloat)calculateStatusBarHeight;

//计算安全区域底部的高度，需在viewWillLayoutSubviews中调用才会返回准确值
- (CGFloat)calculateSafeAreaBottom;

//页面支持的设备方向，子类重写
- (UIInterfaceOrientationMask)fat_pageSupportedInterfaceOrientations;
/// //转换方向
/// - Parameter orientation: 凡泰定义的方向值，FATInterfaceOrientationNone会转换成UIInterfaceOrientationMaskAll
-(UIInterfaceOrientationMask)convertInterfaceOrientation:(FATInterfaceOrientation)orientation;

//检查页面支持的方向和设备方向是否一致，如果不一致，则改变设备方向
-(void)changeDeviceOrientaitonIfNeeded;


@end

