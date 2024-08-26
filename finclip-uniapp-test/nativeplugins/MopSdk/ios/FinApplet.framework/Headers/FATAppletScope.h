//
//  FATAppletScope.h
//  FinApplet
//
//  Created by 王兆耀 on 2023/8/3.
//

#import <Foundation/Foundation.h>
#import "FATConstant.h"

@interface FATAppletScope : NSObject<NSCoding>

/**
 对应的scope，唯一值 scope.camera
 */
@property (nonatomic, copy) NSString *scope;

/**
 对应scope申请弹窗的标题
 */
@property (nonatomic, copy) NSString *title;

/**
 对应scope申请弹窗的描述
 */
@property (nonatomic, copy) NSString *desc;

/**
 对应scope展示出来的名称，对应设置页面的 名称
 */
@property (nonatomic, copy) NSString *scopeName;

/**
 对应scope的授权结果
 */
@property (nonatomic, assign) FATAuthorizationStatus scopeStatus;


@end

