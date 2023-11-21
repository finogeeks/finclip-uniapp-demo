//
//  UIView+FATPublic.h
//  FinApplet
//
//  Created by Haley on 2022/12/1.
//  Copyright © 2022 finogeeks. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (FATPublic)

@property (nonatomic) CGFloat fat_x;
@property (nonatomic) CGFloat fat_y;
@property (nonatomic) CGFloat fat_left;    ///< Shortcut for frame.origin.x.
@property (nonatomic) CGFloat fat_top;     ///< Shortcut for frame.origin.y
@property (nonatomic) CGFloat fat_right;   ///< Shortcut for frame.origin.x + frame.size.width
@property (nonatomic) CGFloat fat_bottom;  ///< Shortcut for frame.origin.y + frame.size.height
@property (nonatomic) CGFloat fat_width;   ///< Shortcut for frame.size.width.
@property (nonatomic) CGFloat fat_height;  ///< Shortcut for frame.size.height.
@property (nonatomic) CGFloat fat_centerX; ///< Shortcut for center.x
@property (nonatomic) CGFloat fat_centerY; ///< Shortcut for center.y
@property (nonatomic) CGPoint fat_origin;  ///< Shortcut for frame.origin.
@property (nonatomic) CGSize fat_size;     ///< Shortcut for frame.size.


+ (CGFloat)fat_screenWidth;
+ (CGFloat)fat_screenHeight;
+ (CGFloat)fat_statusHeight;

@end

