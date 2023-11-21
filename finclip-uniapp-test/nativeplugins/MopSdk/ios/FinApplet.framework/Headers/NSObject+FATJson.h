//
//  NSObject+FATPublic.h
//  FinApplet
//
//  Created by Haley on 2022/12/1.
//  Copyright © 2022 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (FATJson)

- (id)fat_jsonObject;

@end

@interface NSData (FATJson)

- (id)fat_jsonObject;

@end

@interface NSDictionary (FATJson)

- (NSString *)fat_jsonString;

- (NSString *)fat_jsonStringWithOptions:(NSJSONWritingOptions)opt error:(NSError **)error;

@end

@interface NSArray (FATJson)

- (NSString *)fat_jsonString;

- (NSString *)fat_jsonStringWithOptions:(NSJSONWritingOptions)opt error:(NSError **)error;

@end

