//
//  FATAppletAppJsonDelegate.h
//  FinApplet
//
//  Created by Haley on 2023/3/14.
//  Copyright © 2023 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FATAppletInfo.h"

@protocol FATAppletAppJsonDelegate <NSObject>

/// 收到小程序appJson的代理事件
/// - Parameters:
///   - appletInfo: 小程序对象
///   - appJson: 小程序app.json和page.json合并的字典
- (void)applet:(FATAppletInfo *)appletInfo didReceiveAppJson:(NSDictionary *)appJson;

@end

