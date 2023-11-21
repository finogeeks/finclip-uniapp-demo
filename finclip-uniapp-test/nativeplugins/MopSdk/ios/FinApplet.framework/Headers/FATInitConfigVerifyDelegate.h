//
//  FATInitConfigVerifyDelegate.h
//  FinApplet
//
//  Created by beetle_92 on 2023/4/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class FATStoreConfig;

@protocol FATInitConfigVerifyDelegate <NSObject>

@required

- (NSDictionary *)verifyWithNonce:(NSString *)nonce storeConfig:(FATStoreConfig *)storeConfig;

@end

NS_ASSUME_NONNULL_END
