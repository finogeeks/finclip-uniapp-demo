//
//  FATAuthModel.h
//  FinApplet
//
//  Created by 滔 on 2023/3/29.
//  Copyright © 2023 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FATConstant.h"

NS_ASSUME_NONNULL_BEGIN

@interface FATAuthModel : NSObject
@property (nonatomic, assign) FATAuthorizationType authType;
@property (nonatomic, assign) NSInteger authValue;
@property (nonatomic, copy) NSString *authName;
@property (nonatomic, copy) FATScopeName scopeName;

@end

@interface FATPrivacyAlertInfo : NSObject
@property (nonatomic, copy) NSString *alertTitle;  //标题
@property (nonatomic, copy) NSString *alertContent; //内容
@end

NS_ASSUME_NONNULL_END
