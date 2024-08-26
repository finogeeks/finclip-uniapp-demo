//
//  FATUIConfig.h
//  FinApplet
//
//  Created by Haley on 2020/7/29.
//  Copyright © 2020 finogeeks. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "FATConstant.h"

/// 返回首页按钮样式
@interface FATNavHomeConfig : NSObject

/**
 返回首页按钮的宽度
 */
@property (nonatomic, assign) CGFloat width;

/**
 返回首页按钮的高度
 */
@property (nonatomic, assign) CGFloat height;

/**
 返回首页按钮的左边距，默认值为10
 */
@property (nonatomic, assign) CGFloat leftMargin;

/**
 返回首页按钮的圆角半径，默认值为5
 */
@property (nonatomic, assign) CGFloat cornerRadius;

/**
 返回首页按钮的边框宽度，默认值为0.8
 */
@property (nonatomic, assign) CGFloat borderWidth;

/**
 浅色返回首页按钮的图片对象，如果不传，会使用默认图标
 （暗黑模式）
*/
@property (nonatomic, strong) UIImage *lightImage;

/**
 深色返回首页按钮的图片对象，如果不传，会使用默认图标
 （明亮模式）
*/
@property (nonatomic, strong) UIImage *darkImage;

/**
 返回首页按钮的边框浅色颜色
 （暗黑模式）
 */
@property (nonatomic, strong) UIColor *borderLightColor;

/**
 返回首页按钮的边框深色颜色
 （明亮模式）
 */
@property (nonatomic, strong) UIColor *borderDarkColor;

/**
 返回首页按钮的背景浅色颜色
 （明亮模式）
 */
@property (nonatomic, strong) UIColor *bgLightColor;

/**
 返回首页按钮的背景深色颜色
 （暗黑模式）
 */
@property (nonatomic, strong) UIColor *bgDarkColor;

@end

/// 胶囊样式
@interface FATCapsuleConfig : NSObject

/**
 隐藏小程序启动后胶囊里的关闭小程序按钮，默认为NO
 */
@property (nonatomic, assign) BOOL hideCapsuleCloseButton;

/**
 右上角胶囊视图的宽度，默认值为88
 */
@property (nonatomic, assign) CGFloat capsuleWidth;

/**
 右上角胶囊视图的高度，默认值为32
 */
@property (nonatomic, assign) CGFloat capsuleHeight;

/**
 右上角胶囊视图的右边距，默认值为10
 */
@property (nonatomic, assign) CGFloat capsuleRightMargin;

/**
 右上角胶囊视图的圆角半径，默认值为5
 */
@property (nonatomic, assign) CGFloat capsuleCornerRadius;

/**
 右上角胶囊视图的边框宽度，默认值为0.8
 */
@property (nonatomic, assign) CGFloat capsuleBorderWidth;

/**
 胶囊里的更多按钮的宽度，高度与宽度相等
 */
@property (nonatomic, assign) CGFloat moreBtnWidth;

/**
 胶囊里的更多按钮的左边距
 */
@property (nonatomic, assign) CGFloat moreBtnLeftMargin;

/**
 胶囊里的关闭按钮的宽度，高度与宽度相等
 */
@property (nonatomic, assign) CGFloat closeBtnWidth;

/**
 胶囊里的关闭按钮的左边距
 */
@property (nonatomic, assign) CGFloat closeBtnLeftMargin;

/**
 胶囊里的浅色定位按钮的图片对象，如果不传，会使用默认图标
 （暗黑模式）
 */
@property (nonatomic, strong) UIImage *locationLightImage;

/**
 胶囊里的深色定位按钮的图片对象，如果不传，会使用默认图标
 */
@property (nonatomic, strong) UIImage *locationDarkImage;

/**
 胶囊里的浅色麦克风按钮的图片对象，如果不传，会使用默认图标
 （暗黑模式）
 */
@property (nonatomic, strong) UIImage *microphoneLightImage;

/**
 胶囊里的深色麦克风按钮的图片对象，如果不传，会使用默认图标
 */
@property (nonatomic, strong) UIImage *microphoneDarkImage;

/**
 胶囊里的浅色更多按钮的图片对象，如果不传，会使用默认图标
 （暗黑模式）
 */
@property (nonatomic, strong) UIImage *moreLightImage;

/**
 胶囊里的深色更多按钮的图片对象，如果不传，会使用默认图标
 */
@property (nonatomic, strong) UIImage *moreDarkImage;

/**
 胶囊里的浅色关闭按钮的图片对象，如果不传，会使用默认图标
 （暗黑模式）
 */
@property (nonatomic, strong) UIImage *closeLightImage;

/**
 胶囊里的深色关闭按钮的图片对象，如果不传，会使用默认图标
 （明亮模式）
 */
@property (nonatomic, strong) UIImage *closeDarkImage;

/**
 右上角胶囊视图的边框浅色颜色
 （暗黑模式）
 */
@property (nonatomic, strong) UIColor *capsuleBorderLightColor;

/**
 右上角胶囊视图的边框深色颜色
 （明亮模式）
 */
@property (nonatomic, strong) UIColor *capsuleBorderDarkColor;

/**
 右上角胶囊视图的背景浅色颜色
 （明亮模式）
 */
@property (nonatomic, strong) UIColor *capsuleBgLightColor;

/**
 右上角胶囊视图的背景深色颜色
 （暗黑模式）
 */
@property (nonatomic, strong) UIColor *capsuleBgDarkColor;

/**
 胶囊里的分割线的浅色颜色
 （暗黑模式）
 */
@property (nonatomic, strong) UIColor *capsuleDividerLightColor;

/**
 胶囊里的分割线的深色颜色
 （明亮模式）
 */
@property (nonatomic, strong) UIColor *capsuleDividerDarkColor;

@end

@interface FATImageViewConfig : NSObject

/**
 圆角半径，默认值为4
 */
@property (nonatomic, assign) CGFloat borderCornerRadius;

/**
 边框宽度，默认值为0.5
 */
@property (nonatomic, assign) CGFloat borderWidth;

/**
 边框颜色，默认#D8D8D8
 */
@property (nonatomic, strong) UIColor *borderColor;

/**
 背景颜色，默认为白色
 */
@property (nonatomic, strong) UIColor *backgroundColor;

@end

/// 权限弹窗按钮样式
@interface FATAuthButtonConfig : NSObject

/**
 按钮的圆角半径
 */
@property (nonatomic, assign) CGFloat cornerRadius;

/**
 按钮默认背景颜色
 */
@property (nonatomic, strong) UIColor *normalBackgroundColor;

/**
 按钮按下背景颜色
 */
@property (nonatomic, strong) UIColor *pressedBackgroundColor;

/**
 按钮默认文字颜色
 */
@property (nonatomic, strong) UIColor *normalTextColor;

/**
 按钮按下文字颜色
 */
@property (nonatomic, strong) UIColor *pressedTextColor;

/**
 按钮默认边框颜色
 */
@property (nonatomic, strong) UIColor *normalBorderColor;

/**
 按钮按下边框颜色
 */
@property (nonatomic, strong) UIColor *pressedBorderColor;

@end

/// 菜单栏按钮的配置项
@interface FATShareItemConfig : NSObject

/**
 右上角更多菜单的转发按钮icon，如果不传，会使用默认图标
 */
@property (nonatomic, strong) UIImage *shareItemImage;

/**
  右上角更多菜单的转发按钮名称，如果不传，默认为转发。如进行配置，请注意进行多语言适配。
*/
@property (nonatomic, copy) NSString *shareItemString;

@end

/// 权限弹窗样式
@interface FATAuthViewConfig : NSObject

/**
 小程序名称字体大小，默认字体为PingFangSC-Regular，默认大小16
 */
@property (nonatomic, strong) UIFont *appletNameFont;

/**
 小程序名称的浅色颜色（明亮模式），默认#202020
 */
@property (nonatomic, strong) UIColor *appletNameLightColor;

/**
 小程序名称的深色颜色（暗黑模式），默认#D0D0D0
 */
@property (nonatomic, strong) UIColor *appletNameDarkColor;

/**
 隐私协议入口icon（明亮模式），大小：22pt（@2× @3×）
 */
@property (nonatomic, strong) UIImage *agreementLightImage;

/**
 隐私协议入口icon（暗黑模式），大小：22pt（@2× @3×）
 */
@property (nonatomic, strong) UIImage *agreementDarkImage;

/**
 权限标题字体大小，默认字体为PingFangSC-Medium，默认大小17
 备注：权限选项文字字体大小使用该配置项，但字体固定为PingFangSC-Regular
 */
@property (nonatomic, strong) UIFont *authorizeTitleFont;

/**
 权限标题的浅色颜色（明亮模式），默认#202020
 备注：权限选项文字字体颜色使用该配置项
 */
@property (nonatomic, strong) UIColor *authorizeTitleLightColor;

/**
 权限标题的深色颜色（暗黑模式），默认#D0D0D0
 备注：权限选项文字字体颜色使用该配置项
 */
@property (nonatomic, strong) UIColor *authorizeTitleDarkColor;

/**
 权限描述字体大小，默认字体为PingFangSC-Regular，默认大小14
 */
@property (nonatomic, strong) UIFont *authorizeDescriptionFont;

/**
 权限描述的浅色颜色（明亮模式），默认#666666
 */
@property (nonatomic, strong) UIColor *authorizeDescriptionLightColor;

/**
 权限描述的深色颜色（暗黑模式），默认#8C8C8C
 */
@property (nonatomic, strong) UIColor *authorizeDescriptionDarkColor;

/**
 协议标题字体大小，默认字体为PingFangSC-Regular，默认大小16
 */
@property (nonatomic, strong) UIFont *agreementTitleFont;

/**
 协议标题的浅色颜色（明亮模式），默认#202020
 */
@property (nonatomic, strong) UIColor *agreementTitleLightColor;

/**
 协议标题的深色颜色（暗黑模式），默认#D0D0D0
 */
@property (nonatomic, strong) UIColor *agreementTitleDarkColor;

/**
 协议描述字体大小，默认字体为PingFangSC-Regular，默认大小14
 */
@property (nonatomic, strong) UIFont *agreementDescriptionFont;

/**
 协议描述的浅色颜色（明亮模式），默认#202020
 */
@property (nonatomic, strong) UIColor *agreementDescriptionLightColor;

/**
 协议描述的深色颜色（暗黑模式），默认#D0D0D0
 */
@property (nonatomic, strong) UIColor *agreementDescriptionDarkColor;

/**
 权限选项选中时的icon（明亮模式），大小：22pt（@2× @3×）
 */
@property (nonatomic, strong) UIImage *authorizeSelectedLightImage;

/**
 权限选项选中时的icon（暗黑模式），大小：22pt（@2× @3×）
 */
@property (nonatomic, strong) UIImage *authorizeSelectedDarkImage;

/**
 链接的浅色颜色（明亮模式），默认#409EFF
 */
@property (nonatomic, strong) UIColor *linkLightColor;

/**
 链接的深色颜色（暗黑模式），默认#368CE4
 */
@property (nonatomic, strong) UIColor *linkDarkColor;

/**
 同意按钮配置（明亮模式），默认配置如下：
 圆角：4
 默认背景色：#4285F4
 默认描边：#4285F4
 默认文字颜色：#FFFFFF
 按下背景色：#3B77DB
 按下默认描边：#3B77DB
 按下文字颜色：#FFFFFF
 */
@property (nonatomic, strong) FATAuthButtonConfig *allowButtonLightConfig;

/**
 同意按钮配置（暗黑模式），默认配置如下：
 圆角：4
 默认背景色：#4285F4
 默认描边：#4285F4
 默认文字颜色：#FFFFFF
 按下背景色：#5E97F5
 按下默认描边：#5E97F5
 按下文字颜色：#FFFFFF
 */
@property (nonatomic, strong) FATAuthButtonConfig *allowButtonDarkConfig;

/**
 拒绝按钮配置（明亮模式），默认配置如下：
 圆角：4
 默认背景色：#FFFFFF
 默认描边：#E2E2E2
 默认文字颜色：#222222
 按下背景色：#D8D8D8
 按下默认描边：#D8D8D8
 按下文字颜色：#222222
 */
@property (nonatomic, strong) FATAuthButtonConfig *rejectButtonLightConfig;

/**
 拒绝按钮配置（暗黑模式），默认配置如下：
 圆角：4
 默认背景色：#2C2C2C
 默认描边：#2C2C2C
 默认文字颜色：#D0D0D0
 按下背景色：#414141
 按下默认描边：#414141
 按下文字颜色：#D0D0D0
 */
@property (nonatomic, strong) FATAuthButtonConfig *rejectButtonDarkConfig;

@end

@interface FATUIConfig : NSObject

/**
 导航栏的标题样式，目前支持了font
 */
@property (nonatomic, strong) NSDictionary<NSAttributedStringKey, id> *navigationTitleTextAttributes;

/**
 导航栏的高度(不含状态栏高度)，默认值为44
 */
@property (nonatomic, assign) CGFloat navigationBarHeight;

/**
 导航栏的标题颜色（深色主题），默认值为[UIColor whiteColor]
 */
@property (nonatomic, strong) UIColor *navigationBarTitleLightColor;

/**
 导航栏的标题颜色（明亮主题），默认值为[UIColor blackColor]
 */
@property (nonatomic, strong) UIColor *navigationBarTitleDarkColor;

/**
 导航栏的返回按钮颜色（深色主题），默认值为[UIColor whiteColor]
 */
@property (nonatomic, strong) UIColor *navigationBarBackBtnLightColor;

/**
 导航栏的返回按钮颜色（明亮主题），默认值为[UIColor blackColor]
 */
@property (nonatomic, strong) UIColor *navigationBarBackBtnDarkColor;

/**
 右上角胶囊的配置
 */
@property (nonatomic, strong) FATCapsuleConfig *capsuleConfig;
/**
 返回首页按钮的配置
 */
@property (nonatomic, strong) FATNavHomeConfig *navHomeConfig;
/**
 权限弹窗UI配置
 */
@property (nonatomic, strong) FATAuthViewConfig *authViewConfig;

/**
 转发按钮的配置
 */
@property (nonatomic, strong) FATShareItemConfig *shareItemConfig;

/**
 ... 弹出的菜单视图的logo配置
 */
@property (nonatomic, strong) FATImageViewConfig *moreMenuLogoConfig;

/**
 导航栏返回按钮的图片对象，如果不传，会使用默认图标
 图片必须是png格式且背景透明
 明亮模式下，图片显示为黑色；暗黑模式下，图片显示为白色
 */
@property (nonatomic, strong) UIImage *navigationBackImage;

/**
 小程序里加载H5时进度条的颜色
 */
@property (nonatomic, strong) UIColor *progressBarColor;

/**
 隐藏小程序里加载H5时进度条，默认为NO
 */
@property (nonatomic, assign) BOOL hideWebViewProgressBar;

/**
 小程序里加载H5时的缓存策略配置，默认为NSURLRequestUseProtocolCachePolicy
 */
@property (nonatomic, assign) NSURLRequestCachePolicy webViewCachePolicy;

/**
 ... 弹出的菜单视图的样式
 */
@property (nonatomic, assign) FATMoreViewStyle moreMenuStyle;

/**
 隐藏...导航栏中的返回首页按钮（全局配置），默认为NO
 */
@property (nonatomic, assign) BOOL hideBackToHome;

/**
 隐藏导航栏返回首页按钮的优先级设置，默认全局配置优先
 不支持FATConfigAppletFilePriority
 */
@property (nonatomic, assign) FATConfigPriority hideBackToHomePriority;

/**
 隐藏...弹出菜单中的 【反馈与投诉】 的菜单，默认为NO
 */
@property (nonatomic, assign) BOOL hideFeedbackMenu;

/**
 隐藏...弹出菜单中的 【分享】 的菜单，默认为YES
 */
@property (nonatomic, assign) BOOL hideShareAppletMenu;

/**
 隐藏...弹出菜单中的 【清理缓存】 的菜单，默认为NO
 */
@property (nonatomic, assign) BOOL hideClearCacheMenu;

/**
 隐藏...弹出菜单中的 【转发】 的菜单，默认为NO
 */
@property (nonatomic, assign) BOOL hideForwardMenu;

/**
 隐藏...弹出菜单中的 【重新进入小程序】 的菜单，默认为NO
 */
@property (nonatomic, assign) BOOL hideRefreshMenu;

/**
 隐藏...弹出菜单中的 【设置】 的菜单，默认为NO
 */
@property (nonatomic, assign) BOOL hideSettingMenu;

/**
 隐藏...弹出菜单中的 【打开/关闭调试】 的菜单，默认为NO
 */
@property (nonatomic, assign) BOOL hideDebugMenu;

/**
 隐藏...弹出菜单中的 【添加/取消收藏】 的菜单，默认为YES
 */
@property (nonatomic, assign) BOOL hideFavoriteMenu;

/**
 隐藏...弹出菜单中的 【添加到桌面】 的菜单，默认为YES
 */
@property (nonatomic, assign) BOOL hideAddToDesktopMenu;

/**
 是否自适应暗黑模式。
 如果设置为YES，则更多页面、关于等原生页面会随着手机切换暗黑，也自动调整为暗黑模式
 */
@property (nonatomic, assign) BOOL autoAdaptDarkMode __attribute__((deprecated("该属性(自2.44.5起)废弃，建议使用themeStyle")));

/// 主题模式，默认FATUserInterfaceLight，浅色模式
@property (nonatomic, assign) FATUserInterfaceStyle themeStyle;

/**
 要拼接的userAgent字符串。
*/
@property (nonatomic, copy) NSString *appendingCustomUserAgent;

/**
 注入小程序统称appletText字符串，默认为“小程序”。
*/
@property (nonatomic, copy) NSString *appletText;

/**
 打开小程序时的默认动画方式，默认为FATTranstionStyleUp。
 该属性主要针对非api方式打开小程序时的动画缺省值。主要改变如下场景的动画方式：
 1. scheme 打开小程序；
 2. universal link 打开小程序；
 3. navigateToMiniprogram
 */
@property (nonatomic, assign) FATTranstionStyle transtionStyle;

/**
 是否隐藏转场页的关闭按钮。默认为NO
 */
@property (nonatomic, assign) BOOL hideTransitionCloseButton;

/**
 是否禁用侧滑关闭小程序的手势。默认为NO
 该手势禁用，不影响小程序里页面的侧滑返回上一页的功能
 */
@property (nonatomic, assign) BOOL disableSlideCloseAppletGesture;

/**

 非小程序页面支持的屏幕方向，默认竖屏方向
 注意：确保工程是支持设置的方向，比如工程只支持竖屏，这里的设置就只能设置为竖屏，否则需要去AppDelegate的代理方法中设置允许的方向
 */
@property (nonatomic, assign) FATInterfaceOrientation commonUISupportOrientaion;




/**
 默认值为NO。当设置为YES表示使用内置的live组件，此时需要依赖FATAppletLive扩展SDK
 */
@property (nonatomic, assign) BOOL useNativeLiveComponent;


@end



