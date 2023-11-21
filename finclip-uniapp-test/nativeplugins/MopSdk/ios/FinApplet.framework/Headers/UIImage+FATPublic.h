//
//  UIImage+FATPublic.h
//  FinApplet
//
//  Created by Haley on 2022/12/1.
//  Copyright © 2022 finogeeks. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Photos/Photos.h>

@interface UIImage (FATPublic)

/// Create a image with the color.
+ (instancetype)fat_imageWithColor:(UIColor *)color;

/// 压缩图片 至某size
/// @param image 待压缩的图片
/// @param newSize 目标size
+ (UIImage *)fat_scaleImage:(UIImage *)image toSize:(CGSize)newSize;

/// 压缩图片 至某size
/// @param image 待压缩的图片
/// @param newSize 目标size
/// @param scale scale
+ (UIImage *)fat_scaleImage:(UIImage *)image toSize:(CGSize)newSize scale:(CGFloat)scale;

/**
 压缩图片到指定大小

 @param image 图片
 @param maxLength 要压缩到的大小，单位字节 如果是 128kb 则为 128 *1024
 @return 图片数据
 */
+ (NSData *)fat_compressImage:(UIImage *)image toMaxLength:(NSUInteger)maxLength;

/**
将图片转换为指定颜色

@param tintColor 颜色

@return 渲染后的图片
*/
- (UIImage *)fat_imageWithTintColor:(UIColor *)tintColor;

/**
 *
 * @brief 图片顺时针旋转
 *
 * @param degrees 旋转角度
 *
 * @return 旋转后的图片
 *
 */
- (UIImage *)fat_rotateImgByDegrees:(CGFloat)degrees;

/// 获取gif图片
/// @param data 图片数据
+ (UIImage *)fat_animatedGIFWithData:(NSData *)data;


/// 获取图片格式
/// @param data 图片数据
+ (NSString *)fat_typeForImageData:(NSData *)data;

/// 获取图片方向正确的图片
- (UIImage *)fat_normalizedImage;

/// 获取图片的镜像图片
- (UIImage *)fat_mirroredImage;

/**
  图片剪裁接口
 * 1.rect超过image.size则返回原图
 * 2.rect可以是size的任何一个子集，比如取中间半区域 CG
*/
- (UIImage *)fat_imageByCropToRect:(CGRect)rect;

/**
 *  生成视频缩略图
 
 @param aAsset Library的asset对象
 @return 缩略图
 */
+ (UIImage *)fat_coverImageWithAsset:(AVURLAsset *)aAsset;

/// 加载本地图片或网络图片
/// @param url 图片url
+ (UIImage *)fat_getImageWithUrl:(NSString *)url;

/// 异步加载图片
/// @param url 图片url
/// @param completion completion description
+ (void)fat_getImageWithUrl:(NSString *)url completion:(void (^)(UIImage *image, NSError *error))completion;

@end

