//
//  FATAppletHUD.h
//  HeraDemo
//
//  Created by Haley on 2019/5/17.
//  Copyright © 2019 weidian. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, FATAppletHUDMode) {
    /// UIActivityIndicatorView.
    FATAppletHUDModeIndeterminate,
    /// Shows a custom view.
    FATAppletHUDModeImageView,
    /// Shows only label.
    FATAppletHUDModeText,
};

@interface FATAppletHUD : UIView

/**
 * HUD mode. 默认值为FATAppletHUDModeIndeterminate.
 */
@property (assign, nonatomic) FATAppletHUDMode mode;

@property (strong, nonatomic) UIColor *contentColor;

/// 文本label
@property (strong, nonatomic, readonly) UILabel *textLabel;

/// 详情label
@property (nonatomic, strong, readonly) UILabel *detailLabel;

/// 图标视图
@property (strong, nonatomic, readonly) UIImageView *imageView;

+ (instancetype)showHUDAddedTo:(UIView *)view mask:(BOOL)mask;

+ (BOOL)hideHUDForView:(UIView *)view;

+ (FATAppletHUD *)HUDForView:(UIView *)view;

- (void)show;

- (void)hide;

- (void)hideAfterDelay:(NSTimeInterval)delay;

@end

/**
 * A progress view for showing definite progress by filling up a circle (pie chart).
 */
@interface FATRoundProgressView : UIView

/**
 * Progress (0.0 to 1.0)
 */
@property (nonatomic, assign) float progress;

/**
 * Indicator progress color.
 * Defaults to white [UIColor whiteColor].
 */
@property (nonatomic, strong) UIColor *progressTintColor;

/**
 * Indicator background (non-progress) color.
 * Only applicable on iOS versions older than iOS 7.
 * Defaults to translucent white (alpha 0.1).
 */
@property (nonatomic, strong) UIColor *backgroundTintColor;

/**
 * Display mode - NO = round or YES = annular. Defaults to round.
 */
@property (nonatomic, assign, getter=isAnnular) BOOL annular;

@end

@interface FATHudHelper : NSObject

#pragma mark - HUD For KeyWindow
/// 在keyWindow上显示loading 视图
+ (void)showLoadingWithTitle:(NSString *)title mask:(BOOL)mask;
/// 从keyWindow 上移除loading视图
+ (void)hideHud;

#pragma mark - HUD For View
/// 在指定视图上显示loading视图
/// - Parameters:
///   - view: 目标视图
///   - title: loading视图的文字信息
///   - mask: 是否显示透明蒙层，防止触摸穿透
+ (void)showLoadingForView:(UIView *)view title:(NSString *)title mask:(BOOL)mask;

/// 在指定视图上显示toast 视图
/// - Parameters:
///   - view: 目标视图
///   - title: toast视图的文字信息
///   - imagePath: 本地图片的绝对路径，当无法转换为image时，会取icon
///   - icon: sdk中支持的图标，合法值有success、error、none，非法值会显示success的图标
///   - duration: 显示toast的时长，单位：ms
///   - mask: 是否显示透明蒙层，防止触摸穿透
+ (void)showToastForView:(UIView *)view
                   title:(NSString *)title
                   image:(NSString *)imagePath
                    icon:(NSString *)icon
                duration:(int)duration
                    mask:(BOOL)mask;

/// 在指定视图上显示toast 视图（快捷方法：duration为1500；imagePath为nil；mask为NO）
/// - Parameters:
///   - view: 目标视图
///   - title: toast视图的文字信息
///   - icon: SDK中支持的图标，合法值有success、error、none，非法值会显示success的图标
+ (void)showToastForView:(UIView *)view title:(NSString *)title icon:(NSString *)icon;

/// 移除指定视图上的HUD视图(loading、toast视图都会移除)
+ (void)hideHudForView:(UIView *)view;
/// 仅移除指定视图上的toast视图
+ (void)hideToastHUDForView:(UIView *)view;
/// 仅移除指定视图上的loading视图
+ (void)hideLoadingHUDForView:(UIView *)view;

@end
