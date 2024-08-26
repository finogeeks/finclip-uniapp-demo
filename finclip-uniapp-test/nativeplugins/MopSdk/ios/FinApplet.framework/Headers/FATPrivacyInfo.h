//
//  FATPrivacyInfo.h
//  FinApplet
//
//  Created by 滔 on 2023/7/18.
//  Copyright © 2023 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface FATPrivacyInfo : NSObject
//默认隐私协议名
@property (nonatomic, copy) NSString *defaultPrivacyName;
//默认隐私协议内容
@property (nonatomic, copy) NSString *defaultPrivacyContent;

//自定义隐私协议名,管理后台配置的
@property (nonatomic, copy) NSString *customPrivacyName;
//自定义隐私协议链接，管理后台配置的
@property (nonatomic, copy) NSString *customPrivacyUrl;

//协议更新时间
@property (nonatomic, assign) long long updateTime;

@end

@interface FATPrivacyContentInfo : NSObject
//自定义隐私协议名，APP配置，优先级高于管理后台配置的隐私协议名称
@property (nonatomic, copy) NSString *docName;
//自定义隐私协议链接，APP配置，优先级高于管理后台配置的隐私协议链接
@property (nonatomic, copy) NSString *docUrl;

@end

@interface FATPrivacyCustomInfo : FATPrivacyContentInfo

@end

