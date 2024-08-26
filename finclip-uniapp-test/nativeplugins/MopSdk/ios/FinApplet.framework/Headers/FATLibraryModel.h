//
//  FATLibraryModel.h
//  FinApplet
//
//  Created by Haley on 2020/11/18.
//  Copyright © 2020 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface FATLibraryModel : NSObject


/// 基础库版本号
@property (nonatomic, copy, readonly) NSString *version;
/// 基础库zip包md5
@property (nonatomic, copy, readonly) NSString *downloadMd5;
/// 基础库ftpkg包sha256
@property (nonatomic, copy, readonly) NSString *ftpkgSha256;

#pragma mark - helper properties
@property (nonatomic, copy) NSString *apiServer;
@property (nonatomic, assign, readonly) BOOL isFTPKG;
@property (nonatomic, copy, readonly) NSString *fileMd5;
@property (nonatomic, copy, readonly) NSString *unzipPrefix;

- (instancetype)initWithDict:(NSDictionary *)dict;

- (void)updateWithDict:(NSDictionary *)dict;

- (NSDictionary *)dictFromModel;

@end
