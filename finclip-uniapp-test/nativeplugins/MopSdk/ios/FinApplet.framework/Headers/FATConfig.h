//
//  FATConfig.h
//  FinApplet
//
//  Created by 杨涛 on 2019/2/2.
//  Copyright © 2019 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FATStoreConfig.h"
#import "FATConstant.h"

NS_ASSUME_NONNULL_BEGIN

@interface FATConfig : NSObject

/**
 要初始化的服务器配置对象列表
 */
@property (nonatomic, copy, readonly) NSArray<FATStoreConfig *> *storeConfigs;

/**
 当前用户id，对应管理后台的用户管理->成员管理->用户id。
 若体验版本配置了体验成员，则需要设置正确的userId才能具备打开小程序的权限
 登录/切换用户/退出登录时，需要修改此值。
 小程序缓存信息会存储在以userId命名的不同目录下。
 */
@property (nonatomic, copy) NSString *currentUserId;

/** 渠道，如果不填，默认为项目的 bundleId  */
@property (nonatomic, copy) NSString *channel;

/** 手机号，非必传 */
@property (nonatomic, copy) NSString *phone;

/**
 产品的标识，非必传，默认为存储目录里的finclip，finogeeks和userAgent里的finogeeks
 */
@property (nonatomic, copy) NSString *productIdentification;

/**
是否不让SDK申请权限
如果设置为YES，则SDK内使用权限的api，不会主动申请权限
*/
@property (nonatomic, assign) BOOL disableAuthorize;

/**
 小程序自动申请授权
 如果设置为YES，则小程序申请权限时不会弹出用户确认提示框
 */
@property (nonatomic, assign) BOOL appletAutoAuthorize;

/**
 是否禁用SDK的监管接口API（默认开启：NO）
 如果设置为YES，则SDK禁用监管接口API
*/
@property (nonatomic, assign) BOOL disableGetSuperviseInfo;

/**
 是否忽略webview的证书校验，默认为NO,进行校验
 如果设置为YES，则忽略校验Https的证书
*/
@property (nonatomic, assign) BOOL ignoreWebviewCertAuth;

/**
后台自动检查更新的小程序个数
初始化SDK成功后，如处于wifi网络下，更新最近使用的x个小程序
取值范围：0~50。0代表不检查更新；不设置默认是3。
*/
@property (nonatomic, assign) NSInteger appletIntervalUpdateLimit;

/**
apm 统计的扩展信息
*/
@property (nonatomic, strong) NSDictionary *apmExtension;

/** 是否开启Crash防崩溃，默认为NO。
 如果开启，可以防止如下类型的崩溃：UnrecognizedSelector、Notification、Timer、Container(数组越界，字典插入nil等)、String (越界、nil等)
 如果在开发阶段，建议关闭该属性，否则开发时不便于及时发现代码中的崩溃问题。
*/
@property (nonatomic, assign) BOOL startCrashProtection;

@property (nonatomic, strong) NSDictionary *theme;

/**
 * 数据上报时，是否压缩请求的数据
 * 默认为NO
 */
@property (nonatomic, assign) BOOL enableApmDataCompression;

/**
是否需要接口加密验证（初始化单服务器时使用）
默认为不开启，当设置为YES时开启，接口返回加密数据并处理
*/
@property (nonatomic, assign) BOOL encryptServerData;

/**
 小程序的debug模式。
 默认为FATAppletDebugModeDefault，vConsole跟微信一样。
 当设置为FATAppletDebugModeEnable时，强制所有的小程序都会开启vconsole，且不可关闭（最好只在开发阶段使用）。
 当设置为FATAppletDebugModeForbidden时，所有版本强制关闭vconsole，且不可调api开启
 当设置为FATAppletDebugModeForbiddenRelease时，仅正式版强制关闭vConsole，且不可开启，其他版本效果同FATAppletDebugModeDefault一样。
 */
@property (nonatomic, assign) FATAppletDebugMode appletDebugMode;

/**
 iOS 16.4 以后是否支持WebView调试，默认为NO
 */
@property (nonatomic, assign) BOOL webViewInspectable;

/**
 是否显示水印
 */
@property (nonatomic, assign) BOOL enableWatermark;

/**
 显示水印优先级设置，默认全局配置优先
 */
@property (nonatomic, assign) FATConfigPriority watermarkPriority;

/**
 小程序的自定义启动加载页，非必填。
 自定义启动加载页必须继承自FATBaseLoadingView
 注意：swift中的类名带有命名空间，需要在前拼接项目文件名，如：“SwiftDemo.FCloadingView”。其中SwiftDemo是项目名，FCloadingView是类名
*/
@property (nonatomic, copy) NSString *baseLoadingViewClass;

/**
 小程序的自定义启动失败页，非必填。
 自定义启动失败页必须继承自FATBaseLoadFailedView
 注意：swift中的类名带有命名空间，需要在前拼接项目文件名，如：“SwiftDemo.FCloadingView”。其中SwiftDemo是项目名，FCloadingView是类名
*/
@property (nonatomic, copy) NSString *baseLoadFailedViewClass;



/**
 统一设置小程序中网络请求的header。
 注意，如果小程序调用api时也传递了相同的key，则会用小程序传递的参数覆盖。
 对ft.request、ft.downloadFile、ft.uploadFile均会生效
 */
@property (nonatomic, strong) NSDictionary *header;

/**
 header优先级设置，默认全局配置优先
 */
@property (nonatomic, assign) FATConfigPriority headerPriority;

/**
 是否开启小程序中加载的H5页面hook功能，非必填。
 如果宿主app 拦截了http 或https，会导致H5中的request 丢失body。我们SDK为了兼容这一问题，会hook request请求，
 在发起请求之前，先将body中的参数，通过代理方法传递给宿主App。宿主App可自行存储每个request的body，然后在
 自定义的URLProtocol里发起请求之前，组装上body内容。
 */
@property (nonatomic, assign) BOOL enableH5AjaxHook;

/**
 开启enableH5AjaxHook后，会hook request请求，会在原request 的url 后拼上一个FinClipHookBridge-RequestId=xxx的参数。
 而该参数可设置参数名，比如您可以设置Key 为 FinClip-RequestId，这样会拼接FinClip-RequestId=xxx的参数。
 */
@property (nonatomic, copy) NSString *h5AjaxHookRequestKey;

/**
 小程序中页面栈的最大限制。默认值为0，标识不限制。
 例如，设置为5，则表示页面栈中最多可有5个页面。从主页最多可再navigateTo 4 层页面。
 */
@property (nonatomic, assign) NSUInteger pageCountLimit;

/**
 自定义的scheme数组
 */
@property (nonatomic, strong) NSArray<NSString *> *schemes;

/**
 设置SDK的语言，应用公共UI（比如关于、设置、更多面板等）上展示的文字。默认为中文。
 设置不支持的语言时，显示默认值
 */
@property (nonatomic, copy) FATPreferredLanguage language;

/**
 自定义SDK的语言，优先级高于内置的 language 属性。
 示例：
 如果是放在 mainBundle 下，则设置相对路径：@"abc.lproj"
 如果是放在自定于 Bundle 下，则设置相对路径：@"bundleName.bundle/abc.lproj"
 */
@property (nonatomic, copy, nullable) NSString *customLanguagePath;

/**
 SDK外部校验Key
 */
@property (nonatomic, copy) NSString *finkey;


/// 周期性更新的时间间隔(小时), 设置为0不会发起周期性更新请求和触发预拉取请求，接收设置范围为3-12小时，默认是12小时
@property (nonatomic, assign) NSInteger backgroundFetchPeriod;
/**
 表示用于选择器区域的文件路径。

 这个属性可以用于指定一个自定义的文件路径，用于加载和展示区域数据。当设置此属性时，选择器将尝试从指定路径加载数据。
 如果此属性为空或未设置，选择器将加载默认的区域数据。

 @note 文件路径可以是应用的沙盒目录中的路径，也可以是包含在应用Bundle中的文件名。
 */
@property (nonatomic, copy, nullable) NSString *pickerRegionPath;


/// 权限说明信息未配置时的策略，详细说明可以查看FATAuthDescStrategy
@property (nonatomic, assign) FATAuthDescStrategy  authDescStrategy;

#pragma mark - method
/// 创建config对象
/// @param appSecret appSecret，也就是SDK Secret
/// @param appKey 也就是SDK Key
+ (instancetype)configWithAppSecret:(NSString *)appSecret appKey:(NSString *)appKey;

/**
 创建config对象
 @param storeConfigs 应用市场对象数组
*/
+ (instancetype)configWithStoreConfigs:(NSArray<FATStoreConfig *> *)storeConfigs;

#pragma mark - deprecated api & property
/**
 appKey，也就是SDK Key，必填
 当校验不通过时，api无法使用
 */
@property (nonatomic, copy, readonly) NSString *appKey __attribute__((deprecated("该api(自2.23.1起)废弃，建议使用FATStoreConfig")));

/**
SDK secret
*/
@property (nonatomic, copy, readonly) NSString *appSecret __attribute__((deprecated("该api(自2.23.1起)废弃，建议使用FATStoreConfig")));

/**
 服务器地址，客户部署的后台地址，必填
 * 例：https://www.finclip.com
 */
@property (nonatomic, copy) NSString *apiServer __attribute__((deprecated("该api(自2.23.1起)废弃，建议使用FATStoreConfig")));

/**
 apm统计服务器的地址
 如果不填，则默认与apiServer一致。
 例：https://www.finclip.com
 */
@property (nonatomic, copy) NSString *apmServer __attribute__((deprecated("该api(自2.23.1起)废弃，建议使用FATStoreConfig")));

/// 小程序SDK中的api加密，默认为MD5
@property (nonatomic, assign) FATApiCryptType cryptType __attribute__((deprecated("该api(自2.23.1起)废弃，建议使用FATStoreConfig")));

/**
SDK指纹，证联服务器时，必填
*/
@property (nonatomic, copy) NSString *fingerprint __attribute__((deprecated("该api(自2.23.1起)废弃，建议使用FATStoreConfig")));

/// api的版本（自2.34.1起弃用）
@property (nonatomic, copy) NSString *apiPrefix __attribute__((deprecated("该api(自2.34.1起)废弃，使用后不起作用。")));

/**
 是否开启小程序的debug模式。
 默认为FATBOOLStateUndefined，此时为旧版通过app.json 中 debug:true 开启vconsole。
 当设置为FATBOOLStateTrue时，强制所有的小程序都会开启vconsole。
 当设置为FATBOOLStateFalse时，非正式版会在更多菜单里显示打开和关闭调试的菜单。
 当设置为FATBOOLStateForbidden时，所有版本强制关闭vconsole，且不可调api开启
 */
@property (nonatomic, assign) FATBOOLState enableAppletDebug __attribute__((deprecated("该属性(自2.41.11起)废弃，建议使用appletDebugMode")));

@end

NS_ASSUME_NONNULL_END
