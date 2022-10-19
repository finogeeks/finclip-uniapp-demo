//
//  IFATXLogManager.h
//  FinApplet
//
//  Created by luojian on 2022/7/1.
//  Copyright © 2022 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FATConstant.h"

/**
 生成的日志文件是xlog格式，因为进行了压缩编码，需要先解码才能打开。
 解码文件是python脚本，需要先安装python2.7 （python3.x无法解码）
 解码文件下载地址：https://public-1251849568.cos.ap-guangzhou.myqcloud.com/sdk/decode_log_file.py
 1.将decode_log_file.py和finclip_xx.xlog日志文件放在同一目录
 2.终端cd到该目录
 3.执行python2 decode_log_file.py finclip_xx.xlog
 生成的log格式文件即为解码后的日志文件
 */

@protocol IFATXLogManager <NSObject>

/// 初始化并开启日志记录
/// @param logDir 日志文件存储路径，默认路径为 沙盒Document/finclip_log（除了日志文件不要把其他文件放入该目录，不然可能会被日志系统清理掉）
/// @param logLevel 日志记录等级（Debug版本推荐 FATLogLevelDebug， Release 版本推荐 FATLogLevelInfo）
/// @param isConsoleLog 是否开启控制台输出日志（Debug版本推荐开启， Release 版本推荐关闭）
- (void)initLogWithLogDir:(NSString *)logDir logLevel:(FATLogLevel)logLevel consoleLog:(BOOL)isConsoleLog;

/// 把内存中的日志立即写入到日志文件
/// 一般在需要导出日志文件时调用，将最新的日志更新到日志文件中。
/// 如果不调用这些日志也不会丢失，日志会以MMAP形式存在于磁盘缓存中，并在合适的时机写入日志文件
/// @param isAsync 是否异步写入（建议异步，否则可能导致卡顿）
- (void)flushLog:(BOOL)isAsync;

/// 设置日志文件保留时间（默认10天，至少为1天）
/// @param duration 保留时间，单位为秒
- (void)setLogFileAliveDuration:(NSUInteger)duration;

/// 关闭日志，在程序退出时调用（applicationWillTerminate:）。
- (void)closeLog;

@end

