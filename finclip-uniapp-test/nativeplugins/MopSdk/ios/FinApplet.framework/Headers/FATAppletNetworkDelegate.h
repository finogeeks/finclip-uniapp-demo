//
//  FATAppletNetworkDelegate.h
//  FinApplet
//
//  Created by 王兆耀 on 2024/1/23.
//

#import <Foundation/Foundation.h>
#import "FATAppletInfo.h"

NS_ASSUME_NONNULL_BEGIN

/**
 FATAppletNetworkDelegate 协议定义了与网络请求相关的可选方法集合。
 遵循此协议的类可以根据需求选择实现下列方法，用以处理网络请求、文件上传和下载。
 所有方法都是可选的，可根据小程序的特定需求进行定制实现。
 */

@protocol FATAppletNetworkDelegate <NSObject>

@optional

/**
 执行网络请求。

 @param appInfo 小程序信息，包含了请求相关的上下文信息。
 @param requestData 请求数据，包含请求所需的所有参数，具体包括：
    - url: 请求的URL地址。
    - data: 请求的数据，可以是JSON字符串或字典。如果是arrayBuffer类型的数据，会被转成base64，在使用时需注意。类似的处理方案：
         NSArray *nativeBuffers = self.param[@"__nativeBuffers__"];
         if ([nativeBuffers isKindOfClass:[NSArray class]] && nativeBuffers.count > 0) {
             for (NSDictionary *dict in nativeBuffers) {
                 NSString *key = dict[@"key"];
                 NSString *base64 = dict[@"base64"];
                 if ([key isEqualToString:@"data"]) {
                     NSData *base64_decodeData = [[NSData alloc] initWithBase64EncodedString:base64 options:0];
                     data = base64_decodeData;
                     break;
                 }
             }
         }
    - header: 请求头信息，为NSDictionary类型。
    - timeout: 请求的超时时间，单位为毫秒。
    - dataType: 请求的数据类型，默认为json。
    - responseType: 响应的数据类型，默认为text。可选值为text或arraybuffer。

 @param onChunckReceived 数据块接收回调。当接收到数据块时调用此回调，参数为：
    - data: 收到的数据块，编码为base64字符串。示例：NSString *base64String = [data base64EncodedStringWithOptions:0]; data为二进制数据。

 @param completion 完成回调，当请求完成时调用，返回网络请求的结果。参数包括：
    - data: 返回给小程序的数据，编码为UTF-8。若responseType为arraybuffer，则数据需转换为base64字符串。
    - headers: HTTP响应头（allHeaderFields）
    - code: 请求结果状态码。FATExtensionCodeSuccess表示成功，FATExtensionCodeFailure表示失败。
    - errMsg: 错误信息描述。
    - statusCode: HTTP状态码。

 @discussion 请确保正确处理data参数的格式转换。对于arraybuffer类型的响应，数据应转换为base64编码的字符串。使用chunked回调来处理流式数据或大型数据的分块接收。
 */
- (void)appletInfo:(FATAppletInfo *)appInfo performRequest:(NSDictionary *)requestData chunked:(void (^)(NSString *base64String))onChunckReceived completion:(void (^)(NSString *data, NSDictionary *headers, FATExtensionCode code, NSString *errMsg, NSInteger statusCode))completion;

/**
 执行文件上传操作。

 @param appInfo 小程序信息，提供上传操作的上下文。
 @param fileUploadData 文件上传的相关数据，包括以下属性：
    - taskId: 上传任务的唯一标识。
    - url: 开发者服务器的URL地址。
    - filePath: 要上传的文件资源路径。
    - name: 文件对应的键，服务器端通过此键获取文件二进制内容。
    - header: HTTP请求头信息，header中不能设置Referer。
    - formData: HTTP请求中其他额外的form data。
    - timeout: 请求的超时时间，单位为毫秒。

 @param uploadProgressDic 上传进度回调，返回当前上传进度的信息。格式示例：
    - totalBytesSent: 已经发送的数据量（字节）。此字段表示到目前为止在上传任务中已经成功发送到服务器的数据量。
    - totalBytesExpectedToSend: 预期发送的总数据量（字节）。此字段表示整个上传任务预期需要发送的总数据量。
    - progress: 上传进度的百分比。此字段为整数，表示已完成部分占整个上传任务的百分比。
    - taskId: 上传任务的唯一标识符。如果设置了taskId，则此字段包含它，用于标识和追踪具体的上传任务。
         NSDictionary *resulsst = @{
             FATTotalBytesSent : @(totalBytesSent),
             FATTotalBytesExpectedToSend : @(totalBytesExpectedToSend),
             FATProgress : @((int)progress),
             FATTaskId : self.taskId ? self.taskId : @""
         };
 @param completion 完成回调，当上传完成时调用，返回上传请求的结果，参数包括：
    - data: 返回给小程序的数据，UTF-8编码。若responseType为arraybuffer，则数据需转换为base64字符串。
    - headers: HTTP响应头（allHeaderFields）
    - code: 请求结果状态码。FATExtensionCodeSuccess表示成功，FATExtensionCodeFailure表示失败。
    - errMsg: 错误信息描述。
    - statusCode: HTTP状态码。

 @discussion 请确保文件上传过程中正确处理超时设置，并在上传完成后清理任何临时资源。
 */
- (void)appletInfo:(FATAppletInfo *)appInfo
 performupLoadFile:(NSDictionary *)fileUploadData
          progress:(void (^)(NSDictionary <FATNetworkProcessKey, NSString *>*uploadProgressDic))uploadProgressDic
        completion:(void (^)(NSString *data, NSDictionary *headers, FATExtensionCode code, NSString *errMsg, NSInteger statusCode))completion;


/**
 执行文件下载操作。

 @param appInfo 小程序信息，提供下载操作的上下文。
 @param fileDownloadData 文件下载的相关数据，具体包括：
    - url: 文件资源的URL地址。
    - header: HTTP请求头信息，header中不能设置Referer。
    - formData: HTTP请求中其他额外的form data。
    - timeout: 请求的超时时间，单位为毫秒。
    - 其他下载相关的配置参数。

 @param downloadProgressDic 下载进度回调，返回当前下载进度的详细信息。字典包含以下字段：
    - FATTotalBytesWritten: 到目前为止已接收的数据量（字节）。
    - FATTotalBytesExpectedToWrite: 预期接收的总数据量（字节）。
    - progress: 下载进度的百分比。此字段为整数，表示已完成部分占整个下载任务的百分比。
    - headers: HTTP响应头（allHeaderFields）。类似下面的方式获取
    - taskId: 下载任务的唯一标识符，用于标识和追踪具体的下载任务。
     NSDictionary *resulsst = @{
         FATTotalBytesWritten : @(totalBytesWritten),
         FATTotalBytesExpectedToWrite : @(totalBytesExpectedToWrite),
         FATProgress : @((int)progress),
         FATHeader  : header ?: @{}
         FATTaskId : self.taskId ? self.taskId : @""
     };
 @param completion 完成回调，当下载完成时调用，返回下载请求的结果，参数包括：
    - filePath: 下载的文件存储路径。
    - headers: HTTP响应头（allHeaderFields）。类似下面的方式获取
         NSDictionary *header = nil;
         NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *)downloadTask.response;
         if ([httpResponse isKindOfClass:[NSHTTPURLResponse class]]) {
             header = httpResponse.allHeaderFields;
         }
    - code: 请求结果状态码。FATExtensionCodeSuccess表示成功，FATExtensionCodeFailure表示失败。
    - errMsg: 错误信息描述。
    - statusCode: HTTP状态码。

 @discussion
 请确保在下载过程中正确处理超时设置，并在下载完成后清理任何临时资源。下载进度信息可用于更新UI进度条或进行其他相关操作。
 */

- (void)appletInfo:(FATAppletInfo *)appInfo
performDownloadFile:(NSDictionary *)fileDownloadData
            progress:(void (^)(NSDictionary <FATNetworkProcessKey, NSString *>*downloadProgressDic))downloadProgressDic
          completion:(void (^)(NSString *filePath, NSDictionary *headers, FATExtensionCode code, NSString *errMsg, NSInteger statusCode))completion;

@end

NS_ASSUME_NONNULL_END
