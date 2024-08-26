//
//  IFATToolManager.h
//  FinApplet
//
//  Created by Haley on 2022/10/24.
//

#import <Foundation/Foundation.h>
#import "FATConstant.h"

@class FATError;

@protocol IFATToolManager <NSObject>

/// 生成token。
/// 根据原始字符串，加上特殊字符，使用国密生成token。
/// @param originText 原始字符串
- (NSString *)generateTokenWithOriginText:(NSString *)originText;

/// 获取token里的原始字符串
/// @param token 使用generateTokenWithOriginText:生成的token
- (NSString *)originTextWithToken:(NSString *)token;

/**
 国密SM3加密
 
 @param plainText  加密明文
 @return 加密密文
 */
- (NSString *)getSM3String:(NSString *)plainText;

/**
 国密SM2解密
 
 @param cipherText  加密串
 @param privateKey  私钥
 @return 解密后的结果
 */
- (NSString *)decodeSM2:(NSString *)cipherText privateKey:(NSString *)privateKey;

/**
 国密SM2生成公钥和私钥
 @return @{@"private_key": @"", @"public_key": @"" }
 */
- (NSDictionary *)SM2MakeKey;


- (BOOL)reportEventWithAppletId:(NSString *)appletId eventName:(NSString *)eventName data:(NSDictionary *)data;

/// 向小程序vConsole插入一条日志，单条日志长度最大为1024*4
/// @param logMsg 日志内容
/// @param consoleLevel 日志等级
/// @param appletId 小程序id
/// @param completion 调用结果回调：error code为FATErrorCodeAppletNotFound，未找到appletId指定小程序；error code为FATErrorCodeAppletConsoleNotReady，小程序控制台未准备好
- (void)addConsoleLog:(NSString *)logMsg
         consoleLevel:(FATConsoleLevel)consoleLevel
             appletId:(NSString *)appletId
           completion:(void (^)(BOOL success, FATError *error))completion;

/// 删除制定URL对应的cookie
/// @param URL 制定的URL
/// @param completionHandler  删除完毕的回调
- (void)deleteCookiesWithURL:(NSURL *)URL completionHandler:(void (^)(void))completionHandler;

/// 删除所有的cookies
/// @param completionHandler 删除完毕的回调
- (void)deleteAllCookiesWithCompletionHandler:(void (^)(void))completionHandler;


@end
