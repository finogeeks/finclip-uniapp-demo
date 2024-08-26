//
//  FATWidgetInfo.h
//  FinApplet
//
//  Created by 滔 on 2023/12/19.
//  Copyright © 2023 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FATWidgetInfo : NSObject

@property (nonatomic, copy) NSString *widgetId;

/// 小组件的机构id
@property (nonatomic, copy) NSString *groupId;


/// 小组件名称
@property (nonatomic, copy) NSString *title;

/// 小组件简介
@property (nonatomic, copy) NSString *coreDescription;

/// 小组件详细描述
@property (nonatomic, copy) NSString *widgetDescription;

/// 小组件版本号
@property (nonatomic, copy) NSString *version;
@end

NS_ASSUME_NONNULL_END
