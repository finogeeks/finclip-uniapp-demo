//
//  FATAppletLoadingPageLifeCycleDelegate.h
//  FinApplet
//
//  Created by 滔 on 2023/8/8.
//  Copyright © 2023 finogeeks. All rights reserved.
//

#ifndef FATAppletLoadingPageLifeCycleDelegate_h
#define FATAppletLoadingPageLifeCycleDelegate_h

#import <Foundation/Foundation.h>
#import "FATAppletInfo.h"
#import "FATBaseLoadingView.h"

@protocol FATAppletLoadingPageLifeCycleDelegate <NSObject>

@optional

/// 是否要在加载小程序的loading页展示自定义内容
/// @param appletInfo 小程序
/// @return 是否要显示自定义的内容(比如第三方内容跳转提醒) 返回NO，代表不需要自定义内容；返回YES，代表需要自定义内容，会阻断loading页逻辑。需要(-appletInfo:showCustomContentInLoadingView:completion:)的completionHandler) 的completionHandler里回调里选择退出还是继续执行。
- (BOOL)appletInfoShouldShowCustomContent:(FATAppletInfo *)appletInfo;
 
/// loadingView显示自定义的内容
/// @param appletInfo 小程序对象
/// @param loadingView loadingView (自定义的内容可以添加到这个视图)
/// @param completionHandler 自定义内容视图显示完毕的回调。resume返回YES，会继续加载小程序；resume返回NO，则退出小程序。
- (void)appletInfo:(FATAppletInfo *)appletInfo showCustomContentInLoadingView:(FATBaseLoadingView *)loadingView completionHandler:(void(^)(BOOL resume))completionHandler;

@end

#endif /* FATAppletLoadingPageLifeCycleDelegate_h */
