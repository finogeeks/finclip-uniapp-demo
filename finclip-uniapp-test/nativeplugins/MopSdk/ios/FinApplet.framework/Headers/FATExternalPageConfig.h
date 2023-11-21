//
//  FATExternalPageConfig.h
//  FinApplet
//
//  Created by 滔 on 2023/7/20.
//  Copyright © 2023 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "FATConstant.h"

NS_ASSUME_NONNULL_BEGIN

@interface FATExternalPageConfig : NSObject
@property (nonatomic, strong) UIImage *backBtnImage;
@property (nonatomic, assign) FATPageTitleAlignment titleAlignment;
@end

NS_ASSUME_NONNULL_END
