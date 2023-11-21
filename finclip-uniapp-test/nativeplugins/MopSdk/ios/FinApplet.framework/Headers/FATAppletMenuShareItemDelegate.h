//
//  FATAppletMenuShareItemDelegate.h
//  FinApplet
//
//  Created by 王兆耀 on 2022/9/3.
//  Copyright © 2022 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol FATAppletMenuShareItemDelegate <NSObject>

@optional

#pragma mark - share item
/**
 点击菜单栏的分享按钮会触发的代理的方法
 @param appletInfo 小程序信息
 @param shareDict 小程序分享所需要的参数
 dic 内容示例
 {
     @"screenshotUrl" : @"当前页面截图的url，需自行处理，不可用",
     @"miniAppName" :  @"小程序名称",
     @"miniAppLogo" :  @"小程序图标的地址",
     @"miniAppId" :  @"小程序id",
     @"miniAppDesc" :  @"小程序详细描述信息",
     @"miniAppLink" :  @"通过链接打开小程序的参数，仅用于finclip，其他App不可用",
     @"wechatAppId" :  @"关联的微信id",
     @"miniAppPath" :  @"当前所在小程序页面路径",
     @"miniAppQuery" :  @"小程序页面打开时的query",
     @"apiServer" : @"服务器地址"
 };
 */
- (void)applet:(FATAppletInfo *)appletInfo didClickShareItem:(NSDictionary *)shareDict;

@end

NS_ASSUME_NONNULL_END
