//
//  FATAppletInfo.h
//  FinApplet
//
//  Created by Haley on 2019/3/27.
//  Copyright © 2019 finogeeks. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FATConstant.h"

@interface FATAppletSimpleInfo : NSObject
/// 小程序id
@property (nonatomic, copy) NSString *appId;

@end

@interface FATAppletInfo : NSObject

/// 小程序id
@property (nonatomic, copy) NSString *appId;

/// 小程序开发者userId
@property (nonatomic, copy) NSString *userId;

/// 小程序的机构id
@property (nonatomic, copy) NSString *groupId;

/// 小程序图标的地址
@property (nonatomic, copy) NSString *appAvatar;

/// 小程序标签
@property (nonatomic, copy) NSArray *appTag;

/// 小程序名称
@property (nonatomic, copy) NSString *appTitle;

/// 小程序简介
@property (nonatomic, copy) NSString *coreDescription;

/// 小程序详细描述
@property (nonatomic, copy) NSString *appDescription;

/// 小程序版本号
@property (nonatomic, copy) NSString *appVersion;

/// 小程序封面图
@property (nonatomic, copy) NSString *appThumbnail;

/// 小程序版本信息
@property (nonatomic, copy) NSString *versionDescription;

/// 小程序主体信息（机构名称）
@property (nonatomic, copy) NSString *groupName;

/// 小程序是否正在灰度
@property (nonatomic, assign) BOOL isGrayRelease;

/// 小程序版本索引
@property (nonatomic, strong) NSNumber *sequence;

/// 服务器地址
@property (nonatomic, copy) NSString *apiServer;

/**
 小程序关联的微信信息
 示例：
 {
     phoneUrl = "pages/phone/index";//获取用户手机时的授权页面
     profileUrl = "pages/profile/index";//获取用户信息时的授权页面
     wechatOriginId = "gh_13538b2951a0";//关联的微信id
 }
 需要先到小程序管理->我的小程序->详情->第三方管理填写关联的微信信息
 */
@property (nonatomic, copy) NSDictionary *wechatLoginInfo;

/**
 小程序对象的扩展信息
 */
@property (nonatomic, strong) NSDictionary *extInfo;

/**
 小程序的自定义菜单
 */
@property (nonatomic, copy) NSArray *menuInfoList;

/**
 小程序自定义的api
 */
@property (nonatomic, copy) NSArray *apiInfo;

/**
 项目类型
 */
@property (nonatomic, assign) FATProjectType projectType;

/// 小程序文件包MD5
@property (nonatomic, copy) NSString *fileMd5;

/// 分包信息数组
@property (nonatomic, copy) NSArray *packages;

#pragma mark - helper properties

/// 离线小程序(本地小程序)设置的图标
@property (nonatomic, strong) UIImage *logoImage;

/**
 * 小程序类型（线上版、体验版、临时版、审核版、开发版）
 */
@property (nonatomic, assign) FATAppletVersionType appletVersionType;

/**
 自定义的scheme数组
 */
@property (nonatomic, strong) NSArray<NSString *> *schemes;

/**
 小程序启动时的启动参数
 */
@property (nonatomic, copy) NSDictionary *startParams;

/// 当前用户id，小程序缓存信息会存储在以userId命名的不同目录下。
@property (nonatomic, copy) NSString *currentUserId;

/**
 小程序启动后，对应的appJson信息。未运行起来时为nil
 */
@property (nonatomic, strong) NSDictionary *appJsonInfo;

/**
 小程序启动时使用的加密串
 注意：使用加密串打开的方式打开小程序才有，否则为nil
 */
@property (nonatomic, copy) NSString *cryptInfo;

/**
 二维码打开小程序时，二维码内对应的链接内容
 注意：只有使用FATAppletQrCodeRequest打开时才会有，否则为nil
 */
@property (nonatomic, copy) NSString *qrCode;

/// 小程序是否已安装 （其实类似收藏）
@property (nonatomic, assign) BOOL installed;


/**

 非小程序页面的屏幕方向
 */
@property (nonatomic, assign) FATInterfaceOrientation commonUIOrientation;

/**

 小程序页面的屏幕方向
 */
@property (nonatomic, assign) FATInterfaceOrientation appletPageOrientation;

@end

@interface FATFetchAppletInfo : NSObject

/// 小程序id
@property (nonatomic, copy) NSString *appId;

/// 小程序描述
@property (nonatomic, copy) NSString *appDescription;

/// 小程序封面图
@property (nonatomic, copy) NSString *appThumbnail;

/// 小程序版本号
@property (nonatomic, copy) NSString *appVersion;

/// 小程序版本信息
@property (nonatomic, copy) NSString *versionDescription;

/// 小程序主体信息（机构名称）
@property (nonatomic, copy) NSString *groupName;

/// 小程序是否正在灰度
@property (nonatomic, assign) BOOL isGrayRelease;

/// 小程序图标地址
@property (nonatomic, copy) NSString *logo;

/// 小程序名称
@property (nonatomic, copy) NSString *appName;

/// 小程序包md5
@property (nonatomic, copy) NSString *fileMd5;

/// 分包信息
@property (nonatomic, copy) NSArray *packages;

/// 服务器地址
@property (nonatomic, copy) NSString *apiServer;

/**
 小程序关联的微信信息
 示例：
 {
     phoneUrl = "pages/phone/index";//获取用户手机时的授权页面
     profileUrl = "pages/profile/index";//获取用户信息时的授权页面
     wechatOriginId = "gh_13538b2951a0";//关联的微信id
 }
 需要先到小程序管理->我的小程序->详情->第三方管理填写关联的微信信息
 */
@property (nonatomic, copy) NSDictionary *wechatLoginInfo;

/**
 小程序对象的扩展信息
 */
@property (nonatomic, strong) NSDictionary *extInfo;

/// 域名白名单列表,NSArray<NSString *>
@property (nonatomic, copy) NSArray *whiteListDomains;

/// 域名黑名单列表,NSArray<NSString *>
@property (nonatomic, copy) NSArray *blackListDomains;

/// 自定义菜单列表，NSArray<NSDictionary *>
@property (nonatomic, copy) NSArray *menuInfo;

/// 自定义api列表，NSArray<NSDictionary *>
@property (nonatomic, copy) NSArray *apiInfo;

/// 小程序标签
@property (nonatomic, copy) NSArray *appTag;

/**
 判断是否开启了按需注入  packageConfig:{isLazyLoading:boolean,entryPath:string}
 */
@property (nonatomic, copy) NSDictionary *packageConfig;

/**
 项目类型
 */
@property (nonatomic, assign) FATProjectType projectType;

///**
// 小程序信息的原数据
// */
//@property (nonatomic, copy) NSDictionary *originalInfo;

- (FATAppletInfo *)convertToAppletInfo;

+ (FATFetchAppletInfo *)convertToFetchAppletInfo:(FATAppletInfo *)appletInfo;

- (NSDictionary *)convertToDictionary:(FATAppletVersionType)appletVersionType;

@end

@interface FATFetchLibraryInfo : NSObject

/// 基础库版本号
@property (nonatomic, copy) NSString *version;

/// 基础库MD5（文件校验时使用）
@property (nonatomic, copy) NSString *downloadMd5;

/// 基础库下载链接
@property (nonatomic, copy) NSString *downloadUrl;

- (NSDictionary *)convertToDictionary;

///**
// 基础库信息的原数据
// */
//@property (nonatomic, copy) NSDictionary *originData;

@end
