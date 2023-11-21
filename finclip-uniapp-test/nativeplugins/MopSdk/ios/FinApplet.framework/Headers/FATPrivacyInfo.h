//
//  FATPrivacyInfo.h
//  FinApplet
//
//  Created by 滔 on 2023/7/18.
//  Copyright © 2023 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FATPrivacyInfo : NSObject
//默认隐私协议名
@property (nonatomic, copy) NSString *defaultPrivacyName;
//默认隐私协议内容
@property (nonatomic, copy) NSString *defaultPrivacyContent;

//自定义隐私协议名
@property (nonatomic, copy) NSString *customPrivacyName;
//自定义隐私协议链接
@property (nonatomic, copy) NSString *customPrivacyUrl;


@end

NS_ASSUME_NONNULL_END
