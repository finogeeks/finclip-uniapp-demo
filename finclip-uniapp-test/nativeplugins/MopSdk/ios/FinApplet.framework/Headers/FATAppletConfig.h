//
//  FATAppletConfig.h
//  FinApplet
//
//  Created by tao on 2022/4/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, FATAppletConfigStatus) {
    FATAppletConfigNone,     //没有设置，空值
    FATAppletConfigPositive, //true值
    FATAppletConfigNegative  //false值
};

@interface FATAppletConfig : NSObject

/// 水印配置
@property (nonatomic, assign) FATAppletConfigStatus watermarkStatus;
/// 隐藏导航栏的返回首页按钮配置
@property (nonatomic, assign) FATAppletConfigStatus hideBackToHomeStatus;

/// 网络请求的header
@property (nonatomic, strong) NSDictionary *header;

@end

NS_ASSUME_NONNULL_END
