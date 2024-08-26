//
//  NSString+FATPublic.h
//  FinApplet
//
//  Created by Haley on 2022/12/1.
//  Copyright © 2022 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (FATPublic)

- (unsigned long long)unsignedLongLongValue;

/// 判断是否字符串是否不为空
- (BOOL)fat_isNotEmpty;

/// 判断字符串是否为空
/// 1:不是字符串类型；2.字符类型长度==0
+ (BOOL)fat_isEmptyWithString:(NSString *)string;

/// 去除字符串开头的多个0。如果非字符串则返回nil；如果为@""则返回@“”；如果全是0，则返回@“0”
/// - Parameter inputString: 入参字符串
+ (NSString *)fat_removeLeadingZeros:(NSString *)inputString;

/// 返回的是小写的MD5，长度(32)
- (NSString *)fat_md5String;

/// 返回的是小写的MD5，长度(32)
+ (NSString *)fat_md5LowercaseString:(NSString *)originString;

/// 返回的是大写的MD5，长度(32)
+ (NSString *)fat_md5:(NSString *)originString;

/// 返回二进制数据的MD5摘要字符串信息(大写MD5，长度32)
+ (NSString *)fat_md5WithBytes:(char *)bytes length:(NSUInteger)length;

/// 返回二进制数据的MD5摘要字符串信息(大写MD5，长度32)
+ (NSString *)fat_md5WithData:(NSData *)data;

/// 返回二进制数据的sha1摘要字符串信息
+ (NSString *)fat_sha1DigestWithData:(NSData *)data;

+ (NSString *)fat_sha256:(NSData *)data;

@end

@interface NSData (FATHash)

+ (NSData *)fat_hashData:(NSData *)data;

@end
