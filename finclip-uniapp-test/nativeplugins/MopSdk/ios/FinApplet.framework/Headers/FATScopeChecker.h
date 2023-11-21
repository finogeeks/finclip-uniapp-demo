//
//  FATScopeChecker.h
//  FinApplet
//
//  Created by 王兆耀 on 2023/8/8.
//

#import <Foundation/Foundation.h>
#import "FATAppletScope.h"
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface FATScopeChecker : NSObject


- (void)checkScopeWithView:(UIView *)view;

// 需要隐藏这个view，并且更新对象数组的值。
- (void)dismissViewWithScopeList:(NSArray <FATAppletScope *>*)scopeArray;


@end

NS_ASSUME_NONNULL_END
