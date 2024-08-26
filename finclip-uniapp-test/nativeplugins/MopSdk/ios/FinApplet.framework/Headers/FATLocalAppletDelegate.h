//
//  FATLocalAppletDelegate.h
//  FinApplet
//
//  Created by 王兆耀 on 2022/9/3.
//  Copyright © 2022 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FATAppletMenuProtocol.h"
#import "FATConstant.h"
#import "FATAppletInfo.h"
#import "FATAppletConfig.h"
#import "FATAppletRequest.h"

NS_ASSUME_NONNULL_BEGIN

@protocol FATLocalAppletDelegate <NSObject>

@optional

#pragma mark - Local Applet
/**
 触发打开其他本地小程序的请求事件
 该事件只有离线小程序才会触发。
 @param appletInfo 小程序对象
 @param request 小程序request对象，应该直接使用该request对象，不要创建新的对象。
 @param currentVC 当前小程序的顶层视图控制器
 @param completion 打开小程序完毕的回调
 */
- (void)applet:(FATAppletInfo *)appletInfo
    navigateToMiniProgram:(FATLocalAppletRequest *)request
                currentVC:(UIViewController *)currentVC
               completion:(void (^)(FATExtensionCode code, NSDictionary *result))completion;

/**
 本地小程序从宿主App获取zip分包路径（适用于小程序分包加载，小程序分包加载必须实现）
 如果有多个小程序的分包放在app包中，为了避免zip分包同名，可以将不同小程序的分包放在不同文件夹中，
 并通过create folder references方式引入，代码中通过 文件夹名称/分包名.zip 方式获取分包
 @param appletInfo 小程序信息
 @param packDict 分包信息
 @param zipPathCallback zip分包路径回调，路径获取失败调用 zipPathCallback(nil)
 */
- (void)localApplet:(FATAppletInfo *)appletInfo packDict:(NSDictionary *)packDict zipPathCallback:(void (^)(NSString *zipPath))zipPathCallback FATDeprecated("该api(自2.40.3起)废弃，请使用localApplet:loadPackage:zipFileCallback");

/**
 本地小程序从宿主app获取分包zip（适用于本地小程序分包加载，小程序分包加载时必须实现）
 @param appletInfo 小程序信息
 @param packageInfo 分包信息
 @param zipFileCallback 分包zip文件回调，路径获取失败调用 zipPathCallback(nil，error对象)。错误提示会展示error的code和localizedDescription
 */
- (void)localApplet:(FATAppletInfo *)appletInfo loadPackage:(NSDictionary *)packageInfo zipFileCallback:(void (^)(NSString * _Nullable zipFilePath, NSError * _Nullable failError))zipFileCallback;

/// 获取本地小程序账号信息
/// @brief 获取本地小程序账号信息，返回的信息结构:
/// @{
///     @"miniProgram": @{
///         @"appId": ##小程序appId##,
///         @"envVersion": ##小程序版本##,
///         @"version": ##线上小程序版本号##
///     },
///     @"plugin": @{
///         @"appId": ##插件appId##,
///         @"version": ##插件版本号##
///     }
/// }
/// @param appletInfo 小程序信息
/// @return 小程序账号信息
- (NSDictionary *)localAppletAccountInfo:(FATAppletInfo *)appletInfo FATDeprecated("该api(自2.42.3起)废弃");


/**
 获取最新的用户加密密钥。

 此方法根据提供的小程序信息对象 (FATAppletInfo) 来获取相应的用户加密密钥，推荐使用appid+userId的方式。返回的字典包含密钥本身以及其他相关的加密信息。

 @param appletInfo 小程序信息对象，用于确定需要获取密钥的特定用户和小程序。

 @return NSDictionary 返回一个字典，其中包含以下键值对：
   - iv : 加密算法所需的初始化向量 (NSString)。
   - version : 密钥版本号。
   - encryptKey : 用户的加密密钥 (NSString)，通常是经过 Base64 编码的字符串。
   - expireTime : 密钥的过期时间戳 (NSNumber)，表示为自 1970 年 1 月 1 日以来的毫秒数。

*/
- (NSDictionary *)getLatestUserKey:(FATAppletInfo *)appletInfo;

@end

@protocol FATLocalInterfaceAppletDelegate <FATLocalAppletDelegate>

@required

/// 获取小程序详情
/// - Parameters:
///   - request: 本地接口请求类
///   - completion: 完成回调，回调小程序信息对象和错误对象
- (void)localAppletFetchAppletInfo:(FATLocalInterfaceAppletRequest *)request
                        completion:(void (^)(FATFetchAppletInfo * _Nullable appletInfo, FATError * _Nullable error))completion;

/// 获取基础库详情
/// - Parameters:
///   - request: 本地接口请求类
///   - appletInfo: 小程序信息对象
///   - completion: 完成回调，回调基础库信息对象和错误对象
- (void)localAppletFetchBaseLibraryInfo:(FATLocalInterfaceAppletRequest *)request
                             appletInfo:(FATFetchAppletInfo *)appletInfo
                             completion:(void (^)(FATFetchLibraryInfo * _Nullable libraryInfo, FATError * _Nullable error))completion;

/// 下载基础库包
/// - Parameters:
///   - request: 本地接口请求类
///   - libraryInfo: 基础库信息对象
///   - completion: 完成回调，回调下载URL对象、解压密码和错误对象
///   completion回调中的password，文件为非加密的情况下，不使用该字段，当文件加密时，传入为空时使用默认密码
- (void)localAppletDownloadBaseLibrary:(FATLocalInterfaceAppletRequest *)request
                           libraryInfo:(FATFetchLibraryInfo *)libraryInfo
                            completion:(void (^)(NSURL * _Nullable location, NSString * _Nullable password, FATError * _Nullable error))completion;

/// 下载小程序包
/// - Parameters:
///   - appletInfo: 小程序信息对象
///   - package: 小程序包信息
///   - completion: 完成回调，回调下载URL对象、解压密码（为空时，使用默认密码）和错误对象
///   completion回调中的password，文件为非加密的情况下，不使用该字段，当文件加密时，传入为空时使用默认密码
- (void)localAppletDownloadApplet:(FATLocalInterfaceAppletRequest *)request
                       appletInfo:(FATFetchAppletInfo *)appletInfo
                      packageInfo:(NSDictionary *)packageInfo
                       completion:(void (^)(NSURL * _Nullable location, NSString * _Nullable password, FATError * _Nullable error))completion;

/**
 触发打开其他本地小程序的请求事件
 该事件只有离线小程序才会触发。
 @param appletInfo 小程序对象
 @param request 小程序request对象，应该直接使用该request对象，不要创建新的对象。
 @param currentVC 当前小程序的顶层视图控制器
 @param completion 打开小程序完毕的回调
 */
- (void)localApplet:(FATAppletInfo *)appletInfo navigateToMiniProgram:(FATLocalInterfaceAppletRequest *)request currentVC:(UIViewController *)currentVC completion:(void (^)(FATExtensionCode code, NSDictionary *result))completion;

@end

NS_ASSUME_NONNULL_END
