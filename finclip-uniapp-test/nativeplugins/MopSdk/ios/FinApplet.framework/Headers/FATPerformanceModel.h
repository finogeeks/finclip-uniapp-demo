//
//  FATPerformanceModel.h
//  FinApplet
//
//  Created by luojian on 2022/8/3.
//  Copyright © 2022 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FATPerformanceModelProtocol.h"

@interface FATPerformanceModel : NSObject <FATPerformanceModelProtocol>

/// 页面路径。仅 render 和 navigation 类型指标有效。
@property (nonatomic, copy) NSString *path;
/// 页面跳转来源页面路径。仅 route 指标有效。
@property (nonatomic, copy) NSString *referrerPath;
/// path 对应页面实例 Id（随机生成，不保证递增）。仅 render/navigation 指标有效。
@property (nonatomic, assign) unsigned long long pageId;
/// referrerPath对应页面实例 Id（随机生成，不保证递增）。仅 route 指标有效。
@property (nonatomic, assign) unsigned long long referrerPageId;
/// 路由真正响应开始时间。仅 navigation 类型指标有效。
@property (nonatomic, assign) long navigationStart;
/// 路由详细类型，与小程序路由方法对应。仅 navigation 类型指标有效。
@property (nonatomic, copy) NSString *navigationType;
/// 分包名，主包表示为 APP (2.21.2 开始)。仅 evaluateScript 指标有效。
@property (nonatomic, copy) NSString *moduleName;
/// 包大小。仅 downloadPackage 指标有效。
@property (nonatomic, assign) unsigned long long packageSize;
/// 包名称
@property (nonatomic, copy) NSString *packageName;
/// 基础库大小
@property (nonatomic, assign) unsigned long long frameworkSize;
/// 按需要注入的加载时间
@property (nonatomic, assign) unsigned long long lazyLoadTime;
/// 内存占用
@property (nonatomic, assign) double memoryUse;

/// 中文描述信息
- (NSString *)chineseSimpleDescription;

@end
