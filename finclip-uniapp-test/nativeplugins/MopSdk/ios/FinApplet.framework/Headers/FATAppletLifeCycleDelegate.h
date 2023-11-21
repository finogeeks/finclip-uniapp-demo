//
//  FATAppletLifeCycleDelegate.h
//  FinApplet
//
//  Created by 王兆耀 on 2022/9/1.
//

#import <Foundation/Foundation.h>

@protocol FATAppletLifeCycleDelegate <NSObject>

@optional

#pragma mark - lifeCycleDelegate methods

/**
 小程序打开完成的事件
 @param appletId 小程序id
 @param error 错误对象
 */
- (void)applet:(NSString *)appletId didOpenCompletion:(NSError *)error FATDeprecated("该api(自2.36.11起)废弃，请使用appletInfo:didOpenCompletion:");

/**
 小程序关闭完成的事件
 @param appletId 小程序id
 @param error 错误对象
 */
- (void)applet:(NSString *)appletId didCloseCompletion:(NSError *)error FATDeprecated("该api(自2.36.11起)废弃，请使用appletInfo:didCloseCompletion:");

/**
 小程序初始化完成，首页加载出来的事件
 @param appletId 小程序id
 @param error 错误对象
 */
- (void)applet:(NSString *)appletId initCompletion:(NSError *)error FATDeprecated("该api(自2.36.11起)废弃，请使用appletInfo:initCompletion:");

/**
 小程序进入活跃状态的事件
 @param appletId 小程序id
 @param error 错误对象
 */
- (void)applet:(NSString *)appletId didActive:(NSError *)error FATDeprecated("该api(自2.36.11起)废弃，请使用appletInfo:didActive:");

/**
 小程序进入非活跃状态的事件
 @param appletId 小程序id
 @param error 错误对象
 */
- (void)applet:(NSString *)appletId resignActive:(NSError *)error FATDeprecated("该api(自2.36.11起)废弃，请使用appletInfo:resignActive:");

/**
 小程序出错的事件
 @param appletId 小程序id
 @param error 错误对象
 */
- (void)applet:(NSString *)appletId didFail:(NSError *)error FATDeprecated("该api(自2.36.11起)废弃，请使用appletInfo:didFail:");

/**
 小程序被销毁的事件
 @param appletId 小程序id
 @param error 错误对象
 */
- (void)applet:(NSString *)appletId dealloc:(NSError *)error FATDeprecated("该api(自2.36.11起)废弃，请使用appletInfo:dealloc:");

/**
 小程序打开完成的事件
 @param appletInfo 小程序info
 @param error 错误对象
 */
- (void)appletInfo:(FATAppletInfo *)appletInfo didOpenCompletion:(NSError *)error;

/**
 小程序关闭完成的事件
 @param appletInfo 小程序info
 @param error 错误对象
 */
- (void)appletInfo:(FATAppletInfo *)appletInfo didCloseCompletion:(NSError *)error;

/**
 小程序初始化完成，冷启动时首页显示出来的事件
 @param appletInfo 小程序info
 @param error 错误对象
 */
- (void)appletInfo:(FATAppletInfo *)appletInfo initCompletion:(NSError *)error;

/**
 小程序进入活跃状态的事件
 @param appletInfo 小程序info
 @param error 错误对象
 */
- (void)appletInfo:(FATAppletInfo *)appletInfo didActive:(NSError *)error;

/**
 小程序进入非活跃状态的事件
 @param appletInfo 小程序info
 @param error 错误对象
 */
- (void)appletInfo:(FATAppletInfo *)appletInfo resignActive:(NSError *)error;

/**
 小程序出错的事件
 @param appletInfo 小程序info
 @param error 错误对象
 */
- (void)appletInfo:(FATAppletInfo *)appletInfo didFail:(NSError *)error;

/**
 小程序被销毁的事件
 @param appletInfo 小程序info
 @param error 错误对象
 */
- (void)appletInfo:(FATAppletInfo *)appletInfo dealloc:(NSError *)error;

@end
