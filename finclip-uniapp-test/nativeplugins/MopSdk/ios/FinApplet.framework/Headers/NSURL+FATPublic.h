//
//  NSURL+FATPublic.h
//  FinApplet
//
//  Created by Haley on 2023/6/29.
//  Copyright © 2023 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSURL (FATPublic)

/**
 字符串链接转换为URL对象。（内部会校验URLString，防止崩溃）
 */
+ (NSURL *)fat_URLWithString:(NSString *)URLString;

/**
 文件路径转换为URL对象。（内部会校验URLString，防止崩溃）
 */
+ (NSURL *)fat_fileURLWithPath:(NSString *)path;

@end

