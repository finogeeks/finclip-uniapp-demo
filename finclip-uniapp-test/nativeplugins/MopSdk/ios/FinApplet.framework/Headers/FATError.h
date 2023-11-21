//
//  FATError.h
//  FinApplet
//
//  Created by Haley on 2020/11/16.
//  Copyright © 2020 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>

// 每次新增需要在wiki上补充，并与安卓对齐
// wiki: https://wiki.finogeeks.club/pages/viewpage.action?pageId=227946218
typedef NS_ENUM(NSUInteger, FATErrorCode) {
#pragma mark - 9000+
    FATErrorCodeUnknown = 9000,                             // 未知错误
    // 9001安卓独占（操作已被取消）
    FATErrorCodeInvalidParam = 9002,                        // 参数不合法

#pragma mark - 10000+（通用场景-初始化）
    FATErrorCodeSDKInitFailed = 10000,                      // SDK初始化失败
    FATErrorCodeNetworkNotReach = 10001,                    // 网络未连接
    FATErrorCodeLicenseSDKConfigIsEmpty = 10002,            // SDK 配置信息为空
    FATErrorCodeLicenseUnsupportedDeviceType = 10003,       // 设备类型暂不支持
    FATErrorCodeLicenseUsableDeviceNumberLimit = 10004,     // 当前可用设备数量已达上限
    FATErrorCodeLicenseDomainCheckFailed = 10005,           // license域名校验失败
    // 10006安卓独占（当前使用的设备系统版本过低，暂时无法打开小程序）
    FATErrorCodeQRCodeFormatInvalid = 10007,                // 二维码格式不合法
    FATErrorCodeQRCodeServerNotMatch = 10008,               // 当前二维码所属环境与SDK初始化不匹配（新增）
    // 从10008之后新增
    FATErrorCodeServerNumberExceedsLicenseLimit = 10009,    // 初始化服务器个数超过限制
    
#pragma mark - 11000+（打开小程序场景——主要是一些打开小程序的参数校验、离线场景的问题都属于这里，打开在线小程序遇到的网络问题都归类到网络问题中）
    FATErrorCodeAppletIdIsInvalid = 11000,                  // appId 不合法
    FATErrorCodeSDKKeyIsNotAllowedToOpenOffline = 11001,    // SDK Key不支持打开离线
    FATErrorCodeAppletDomainNotInitialized = 11002,         // 当前##小程序##所属环境与SDK初始化环境不匹配
    FATErrorCodeAppletInformationIsEmpty = 11003,           // 二维码加密信息为空
    FATErrorCodeAppletInformationEncryptedIsEmpty = 11004,  // 二维码信息解密后为空
    FATErrorCodeAppletDataTypeError = 11005,                // 二维码中数据类型错误
    FATErrorCodeAppletTypeIsMissing = 11006,                // 二维码中类型缺失
    FATErrorCodeAppletUnkownType = 11007,                   // 二维码未知的小程序类型
    FATErrorCodeCodeIdIsInvalid = 11008,                    // CodeId不合法
    FATErrorCodeSameAppID = 11009,                          // 相同的小程序ID（同安卓防抖）
    // 11010安卓独占（预加载基础库文件不存在）
    // 11011安卓独占（预加载小程序包文件不存在）
    FATErrorCodeSDKNotInitialized = 11012,                  // SDK 未初始化（新增）
    // 从11012之后新增

#pragma mark - 12000+（和网络请求相关场景）
    FATErrorCodeNetworkRequestFailed = 12000,               // 服务器接口请求失败
    FATErrorCodeRequestFailed = 12001,                      // 服务异常，接口请求失败
    FATErrorCodeResponseDataInvalid = 12002,                // 服务器返回数据异常
    FATErrorCodeAppletRequestFailed = 12003,                // 服务异常，##小程序##详情接口请求失败
    FATErrorCodeLibraryRequestFailed = 12004,               // 服务异常，基础库详情接口请求失败
    FATErrorCodeBatchRequestFailed = 12005,                 // 批量查询##小程序##详情接口请求失败
    FATErrorCodeAppletResponseDecryptedError = 12006,       // 服务异常，##小程序##详情接口返回数据解密出错
    FATErrorCodeLibraryResponseDecryptedError = 12007,      // 服务异常，基础库详情接口返回数据解密出错
    FATErrorCodeResponseDecryptedError = 12008,             // 服务异常，接口返回数据解密出错
    FATErrorCodeAppletResponseError = 12009,                // 服务异常，##小程序##详情接口返回数据异常
    FATErrorCodeLibraryResponseError = 12010,               // 服务异常，基础库详情接口返回数据异常
    FATErrorCodeBatchResponseError = 12011,                 // 批量查询##小程序##详情接口，返回数据异常
    FATErrorCodeAppletDownloadAddressEmpty = 12012,         // ##小程序##下载地址异常，无法下载
    FATErrorCodeSubpackageDownloadAddressEmpty = 12013,     // ##小程序##分包下载地址为空（新增）
    // 12014安卓独占（小程序分包文件名无效）
    FATErrorCodeLibraryDownloadAddressError = 12015,        // 基础库下载地址异常，无法下载
    FATErrorCodeLibraryVersionEmpty = 12016,                // 基础库版本号为空（新增）
    // 12017安卓独占（小程序分包文件下载失败）
    FATErrorCodeAppletMD5Invalid = 12018,                   // 小程序整包文件MD5校验失败（拆分，新增）
    FATErrorCodeSubpackageMD5Invalid = 12019,               // 小程序分包文件MD5校验失败（拆分，新增）
    FATErrorCodeLibraryMD5Invalid = 12020,                  // 基础库MD5校验失败（拆分，新增）
    FATErrorCodeDownloadDirectoryError = 12021,             // 下载目录出错，无法下载
    FATErrorCodeDownloadFail = 12022,                       // 下载失败
    FATErrorCodeFrameworkResourceNotFound = 12023,          // 基础库下载失败（新增）
    FATErrorCodeMiniprogramResourceNotFound = 12024,        // 小程序下载失败（新增）
    FATErrorCodeAppletPackageCopyError = 12025,             // ##小程序##压缩包异常，拷贝失败（使用系统错误）
    // 从12025之后新增

#pragma mark - 13000+（其他场景——解压、复制文件 等）
    FATErrorCodeServiceNotFound = 13000,                    // service 文件未找到
    FATErrorCodePageNotFound = 13001,                       // 页面不存在
    FATErrorCodeAppletDomainNotRegistered = 13002,          // 非备案域名
    FATErrorCodeAppletDomainIsBlack = 13003,                // 黑名单域名
    // 13004安卓独占（小程序整包解压失败）
    // 13005安卓独占（解压小程序分包文件失败）
    FATErrorCodeLibraryUnzipError = 13006,                  // 基础库解压失败
    FATErrorCodeCopyFrameworkResourceFail = 13007,          // 拷贝基础库资源失败（使用系统错误）
    FATErrorCodeCopyMiniprogramResourceFail = 13008,        // 拷贝小程序资源失败（使用系统错误）
    // 13009安卓独占（基础库加载失败(在加载的那一刻做的判断，比较特殊的情况。一般不会出现)）
    FATErrorCodeServiceLoadTimeout = 13010,                 // 加载 service 超时
    FATErrorCodeAppletOfflinePackageEmpty = 13011,          // ##小程序##离线包不存在
    FATErrorCodeLibraryOfflineEmpty = 13012,                // 基础库离线包不存在
    FATErrorCodeLibraryOfflineUnzipError = 13013,           // 基础库离线包解压失败
    FATErrorCodeAppletPackageEmpty = 13014,                 // ##小程序##压缩包异常，文件缺失
    // 13015安卓独占（离线小程序路径为空）
    FATErrorCodeAppletPackageUnzipError = 13016,            // ##小程序##压缩包异常，解压失败
    // 13017安卓独占（离线小程序读取小程序分包配置文件package.json失败）
    // 13018安卓独占（获取分包失败--offlinePackageFactoryClass对象为空）
    // 13019安卓独占（ErrorCodeSubPackageNull）
    // 13020安卓独占（获取本地分包文件失败）
    // 13021安卓独占（localInterfaceAppletHandler对象为空）
    FATErrorCodeAppletNotFound = 13022,                     // 未找到appletId指定小程序
    FATErrorCodeForegroundAppletNotFound = 13023,           // 未找到前台运行的小程序
    FATErrorCodeAppletConsoleNotReady = 13024,              // 小程序控制台未准备好
    // 13025安卓独占（小程序信息为空）
    FATErrorCodeDocumentNameError = 13026,                  // 文件名称出错
    FATErrorCodeLibraryDirectoryError = 13027,              // 基础库文件目录异常（使用系统错误）
    FATErrorCodeStorageDirectoryError = 13028,              // 存储目录异常（使用系统错误）
    // 13029-13034为安卓独占（详情请查看相关wiki）
    FATErrorCodeExtractDirectoryEmpty = 13035,              // 解压目录不能为空
    // 从13035之后新增
    
#pragma mark - 20000+（后端错误码映射为本地错误码）
    FATErrorCodeAppIDNotFound = 20000,                  // 应用不存在
    FATErrorCodeServiceUnavaliable = 20001,             // 小程序已下架
    FATErrorCodeAppPayExprie = 20002,
    FATErrorCodeAppIsForbidden = 20003,                 // 小程序被禁用
    FATErrorCodeBindNotFound = 20004,                   // 应用不存在
    FATErrorCodeCooperationTerminated = 20005,
    FATErrorCodeAppNotASSBind = 20006,                  // 小程序未关联应用
    FATErrorCodeBindIsForbidden = 20007,
    FATErrorCodeBindPayExprire = 20008,
    FATErrorCodeOrganStatusInvalid = 20009,             // 机构被冻结
    FATErrorCodeLicenseInvalidErr = 20010,              // 非法license
    FATErrorCodeAppSequenceNotFound = 20011,
    FATErrorCodeDBErr = 20012,
    FATErrorCodeGetGroupFailed = 20013,
    FATErrorCodeInvalidSignErr = 20014,
    FATErrorCodeOverFRQLimit = 20015,
    FATErrorCodeAppSearchLimit = 20016,
    FATErrorCodeNotFound = 20017,
    FATErrorCodeQRCodeExpired = 20018,                  // ide临时版二维码已过期
    FATErrorCodeAppNoAuthErr = 20019,
    FATErrorCodePrivacyNotFound = 20020,
    FATErrorCodeParamMissErr = 20021,
    FATErrorCodeBindErr = 20022,
    FATErrorCodeServerErr = 20023,
    FATErrorCodeBasicPackBasicNotExist = 20024,         // 未配置基础库（旧：FATErrorCodeBasicNotExist）
    FATErrorCodeMopSDKFingerPrintCheckFail = 20025,
    FATErrorCodeBasicPackBindParamError = 20026,
    FATErrorCodeBasicPackSDKVerFormatErr = 20027,
    FATErrorCodeBasicPackDBErr = 20028,
    FATErrorCodeTrialUserIDNoMatch = 20029,             // 没有体验版本权限
    FATErrorCodeRuleTrailUserIDNoMatch = 20030,         // 没有体验版本权限
    FATErrorCodeNotTrialInfo = 20031,                   // 体验版已取消
    FATErrorCodeDevUserIdNoMatch = 20032,               // 没有开发版本权限
    FATErrorCodeAdminAuthErr = 20033,                   // 没有seq版本权限
    FATErrorCodeSignatureSDKKeyInvaild = 20034,
    FATErrorCodeSystemCall = 20035,
    FATErrorCodeGetDomainInfoError = 20036,
    FATErrorCodeNetdiskParamError = 20038,                  //网盘请求参数错误
    FATErrorCodeNetdiskUploadError = 20039,                 //文件上传失败
    FATErrorCodeNetdiskDbError = 20040,                     //网盘db异常
    FATErrorCodeNetdiskAccessError = 20041,                 //没有网盘文件的访问权限
    FATErrorCodeNetdiskGetResError = 20042,                 //网盘获取资源失败
    
    // 后端映射未配置时使用该状态码（防止后端新增但本地未映射的情况）
    FATErrorCodeServiceException = 29999
};

@interface FATError : NSError

- (instancetype)initWithCode:(FATErrorCode)code message:(NSString *)message;

+ (instancetype)errorWithCode:(FATErrorCode)code message:(NSString *)message;

+ (instancetype)errorWithNSError:(NSError *)error;

- (BOOL)is40x;

@end
