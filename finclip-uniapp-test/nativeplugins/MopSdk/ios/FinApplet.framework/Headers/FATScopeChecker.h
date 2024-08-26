//
//  FATScopeChecker.h
//  FinApplet
//
//  Created by 王兆耀 on 2023/8/8.
//

#import <Foundation/Foundation.h>
#import "FATAppletScope.h"
#import <UIKit/UIKit.h>

@interface FATScopeChecker : NSObject

/**
 * 检查并展示授权界面。
 *
 * 此方法用于展示一个自定义授权界面，它会基于当前小程序的授权需求进行显示。
 *
 * @param view 用于显示在授权弹窗中的自定义视图。
 */
- (void)checkScopeWithView:(UIView *)view;

/**
 * 隐藏授权界面并处理授权范围。
 *
 * 此方法用于处理特定的授权范围，并在完成后隐藏授权界面。
 * 它会检查传入的授权范围数组，并将非默认范围的授权保存到设置中。
 *
 * @param scopeArray 包含授权范围的数组，这些范围用于更新小程序的授权设置。
 */
- (void)dismissViewWithScopeList:(NSArray <FATAppletScope *>*)scopeArray;


@end

