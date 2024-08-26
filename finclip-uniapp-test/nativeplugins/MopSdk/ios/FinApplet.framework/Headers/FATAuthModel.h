//
//  FATAuthModel.h
//  FinApplet
//
//  Created by 滔 on 2023/3/29.
//  Copyright © 2023 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FATConstant.h"


/**
 表示授权相关的信息和类型。
 */
@interface FATAuthModel : NSObject

/**
 权限类型，例如位置、相机等。
 */
@property (nonatomic, assign) FATAuthorizationType authType;

/**
 权限授权结果：
 - 1: 授权允许。
 - 2: 授权拒绝。
 特定于后台定位：
 - 0: 未申请。
 - 1: 只允许前台定位。
 - 2: 拒绝定位。
 - 3: 允许后台定位。
 */
@property (nonatomic, assign) NSInteger authValue;

/**
 设置页展示的权限名称。
 */
@property (nonatomic, copy) NSString *authName;

/**
 权限类型的标识符，例如 'scope.camera'。
 */
@property (nonatomic, copy) FATScopeName scopeName;

@end

/**
 表示隐私权限弹窗的信息，包含标题和内容。
 */
@interface FATPrivacyAlertInfo : NSObject

/**
 弹窗的标题。
 */
@property (nonatomic, copy) NSString *alertTitle;

/**
 弹窗的内容。
 */
@property (nonatomic, copy) NSString *alertContent;

//自定义隐私协议名
@property (nonatomic, copy) NSString *docName;

//自定义隐私协议链接
@property (nonatomic, copy) NSString *docUrl;


@end


