//
//  FATAppletLogDelegate.h
//  FinApplet
//
//  Created by luojian on 2022/12/12.
//  Copyright © 2022 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FATAppletInfo.h"
#import "FATPerformanceModel.h"

NS_ASSUME_NONNULL_BEGIN

@protocol FATAppletLogDelegate <NSObject>

@optional

#pragma mark - 日志输出
/// 日志输出回调（当实现了这个代理方法，日志不写入到 xlog 中）
- (void)logMessage:(NSString *)message;

#pragma mark - 性能统计输出
/// 输出性能数据记录回调
/// @param appletInfo 小程序信息
/// @param records 性能统计数据数组
- (void)applet:(FATAppletInfo *)appletInfo receivePerformanceRecords:(NSArray<FATPerformanceModel *> *)records;

@end

NS_ASSUME_NONNULL_END
