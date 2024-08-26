//
//  FATSearchAppletRequest.h
//  FinApplet
//
//  Created by beetle_92 on 2021/5/7.
//  Copyright © 2021 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    FATAppStatusAll,    // 所有
    FATAppStatusListed,  // 已上架
    FATAppStatusNotListed, // 未上架
    FATAppStatusDeListed    // 已下架
} FATAppStatus;

@interface FATSearchAppletRequest : NSObject

/**
 服务器地址，客户部署的后台地址，必填
 * 例：https://www.finclip.com
 */
@property (nonatomic, copy) NSString *apiServer;

/**
查找的关键字
*/
@property (nonatomic, copy) NSString *text;

@end

@interface FATFetchBindAppletRequest : NSObject

/** 服务器地址，必填，不可为空*/
@property (nonatomic, copy) NSString *apiServer;
/** 小程序的分类，默认为‘’ */
@property (nonatomic, copy) NSString *appClass;
/** 需要获取的小程序状态类型，默认为FATAppStatusListed */
@property (nonatomic, assign) FATAppStatus appStatus;
/** 是否获取被禁用的小程序，默认为NO*/
@property (nonatomic, assign) BOOL containForbiddenApp;
/** 分页的页码，默认为1*/
@property (nonatomic, assign) NSUInteger pageNo;
/** 分页的大小，默认为20*/
@property (nonatomic, assign) NSUInteger pageSize;

@end

@interface FATFetchBindApplet : NSObject

/** 服务器地址*/
@property (nonatomic, copy) NSString *apiServer;
/** 小程序id*/
@property (nonatomic, copy) NSString *miniAppId;
/** 小程序名称 */
@property (nonatomic, copy) NSString *name;
/** 小程序logo */
@property (nonatomic, copy) NSString *logo;
/** 小程序分类 */
@property (nonatomic, copy) NSString *appClass;
/** 小程序 状态*/
@property (nonatomic, assign) FATAppStatus displayStatus;
/** 小程序简介 */
@property (nonatomic, copy) NSString *desc;
/** 小程序详细描述 */
@property (nonatomic, copy) NSString *detailDesc;
/** 小程序是否被禁用 */
@property (nonatomic, assign) BOOL isForbidden;

- (instancetype)initWithDict:(NSDictionary *)dict apiServer:(NSString *)apiServer;

@end

@interface FATFetchBindAppletResponse : NSObject

/** 获取到的小程序对象*/
@property (nonatomic, strong) NSArray<FATFetchBindApplet *> *items;
/** 获取到小程序个数*/
@property (nonatomic, assign) NSInteger total;

@end
