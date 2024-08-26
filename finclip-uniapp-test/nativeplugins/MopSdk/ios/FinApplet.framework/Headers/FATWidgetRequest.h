//
//  FATWidgetRequest.h
//  FinApplet
//
//  Created by 滔 on 2023/6/8.
//  Copyright © 2023 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FATConstant.h"
#import "FATAppletRequest.h"

NS_ASSUME_NONNULL_BEGIN

@interface FATWidgetRequest : NSObject

/**
 服务器地址，客户部署的后台地址，必填
 * 例：https://mp.finogeeks.com
 */
@property (nonatomic, copy) NSString *widgetServer;

#pragma mark - 小组件 info

/**
 组件id，必填
*/
@property (nonatomic, copy) NSString *widgetId;

/**
组件的启动参数，非必填。
支持的key，请参考FATStartParamKey
*/
@property (nonatomic, copy) NSDictionary<FATStartParamKey, NSString *> *startParams;

/**
 小组件codeId（非必填）
 开发版、体验版通过codeId是否一致判断是否热启动
*/
@property (nonatomic, copy) NSString *codeId;

/**
 小组件的索引。
 每提交一次小组件，都会生成一个索引，所以想打开指定版本小组件，就必须传该值
*/
@property (nonatomic, strong) NSNumber *sequence;

/**
 离线小组件压缩包路径
 */
@property (nonatomic, copy) NSString *offlineMiniprogramZipPath;

/**
 离线基础库压缩包路径
 */
@property (nonatomic, copy) NSString *offlineFrameworkZipPath;

/// 体验版小组件会带小组件信息
@property (nonatomic, copy) NSDictionary *trialInfo;

//组件大小，非必填，组件加载成功后可以再设置
@property (nonatomic, assign) CGSize widgetSize;

@end


/**
 运行本地小组件
 */
@interface FATLocalWidgetRequest : FATWidgetRequest

/**
 小组件可访问的域名白名单列表，非必填
 如果domainList 为空，即nil 或[]，则不校验域名
 */
@property (nonatomic, copy) NSArray *domainList;

/**
 小组件分包信息，必填。
 */
@property (nonatomic, copy) NSArray *packages;
/**
 小组件分包配置。示例如下：
 {
    "compatibleMode":@(YES),   //小游戏是否使用webView渲染：YES:WebView；NO:JSCore
    "isLazyLoading":@(YES),   //是否开启按需注入
    "entryPagePath":"pages/index/inede"    //小组件首页路径
 }
 */
@property (nonatomic, copy) NSDictionary *packageConfig;

/**
 小组件压缩包密码，必填
 */
@property (nonatomic, copy) NSString *zipPassword;


/**
 是否使用基础库缓存，非必填
 如果设置为YES，则会使用的基础库缓存。
 否则，则每次打开小组件都会使用传入的基础库
 */
@property (nonatomic, assign) BOOL useFrameworkCache;

#pragma mark - 小组件分包加载
/**
 可以是小组件版本号，也可以是小组件版本的唯一标识比如md5（适用于小组件分包加载，小组件分包加载必填）
 小组件会根据version来缓存小组件，小组件需要加载分包时优先查找缓存中相同version的小组件，没找到则会触发代理方法，由宿主app提供
 小组件分包路径通过[FATClient sharedClient].delegate的代理方法localApplet:packDict:zipPathCallback:设置
 */
@property (nonatomic, copy) NSString *version;

/**版本描述*/
@property (nonatomic, copy) NSString *versionDescription;


/**
 是否使用本地小组件缓存，默认值为NO（适用于加载整个小组件，加载整个小组件非必填）
 如果设置为YES，则会使用的小组件缓存。
 否则，则每次打开小组件都会使用传入的小组件离线包
 */
@property (nonatomic, assign) BOOL useAppletCache;

/**
 小组件的离线包地址（适用于加载整个小组件，加载整个小组件必填）
 */
@property (nonatomic, copy) NSString *offlineMiniprogramZipPath;

/**
小组件版本类型：线上版、体验版、临时版、审核版、开发版
 */
@property (nonatomic, assign) FATAppletVersionType appletVersionType;

/**
 小组件的自定义API白名单列表（非必填）
 */
@property (nonatomic, strong) NSArray<NSString *> *extApiWhiteList;


@end

@interface FATLocalInterfaceWidgetRequest : FATWidgetRequest
/**
小程序版本类型
 */
@property (nonatomic, assign) FATAppletVersionType appletVersionType;


/**
 拓展信息（在代理方法中透传使用）
 */
@property (nonatomic, copy) NSDictionary *extraData;

/**
 强制更新
 */
@property (nonatomic, assign) BOOL forceUpdate;

@end

@interface FATWidgetQRCodeRequest : NSObject

/**
 二维码内容
*/
@property (nonatomic, strong) NSString *qrCode;
@end

@interface FATWidgetDecryptRequest : NSObject
/**
 加密信息
*/
@property (nonatomic, copy) NSString *info;

//体验版，info加密信息中没有带widget字段
@property (nonatomic, copy) NSString *widgetId;

/**
是否由管理小组件打开
*/
@property (nonatomic, assign) BOOL isManage;

/**
 二维码打开小组件时，对应的二维码链接内容
 */
@property (nonatomic, copy) NSString *qrCode;

@end

NS_ASSUME_NONNULL_END
