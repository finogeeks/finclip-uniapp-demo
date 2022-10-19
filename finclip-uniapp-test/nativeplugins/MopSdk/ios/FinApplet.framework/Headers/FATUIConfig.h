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

@interface FATUIConfig : NSObject

/**
 导航栏的标题样式，目前支持了font
 */
@property (nonatomic, strong) NSDictionary<NSAttributedStringKey, id> *navigationTitleTextAttributes;

/**
 导航栏的的高度(不含状态栏高度)，默认值为44
 */
@property (nonatomic, assign) CGFloat navigationHeight;

/**
 右上角胶囊的配置
 */
@property (nonatomic, strong) FATCapsuleConfig *capsuleConfig;
/**
 返回首页按钮的配置
 */
@property (nonatomic, strong) FATNavHomeConfig *navHomeConfig;

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
 是否自适应暗黑模式。
 如果设置为YES，则更多页面、关于等原生页面会随着手机切换暗黑，也自动调整为暗黑模式
 */
@property (nonatomic, assign) BOOL autoAdaptDarkMode;

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

@end
