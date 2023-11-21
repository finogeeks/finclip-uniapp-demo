//
//  FATPerformanceModelProtocol.h
//  FinApplet
//
//  Created by luojian on 2022/8/15.
//  Copyright © 2022 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol FATPerformanceModelProtocol <NSObject>

/// 指标类型
@property (nonatomic, copy) NSString *entryType;
/// 指标名称
@property (nonatomic, copy) NSString *name;
/// 指标标签，一般为空。用于区分entryType和name都相同的不同统计打点
@property (nonatomic, copy) NSString *tag;
/// 开始时间
@property (nonatomic, assign) unsigned long long startTime;
/// 持续时间
@property (nonatomic, assign) unsigned long long duration;

@end

NS_ASSUME_NONNULL_END
