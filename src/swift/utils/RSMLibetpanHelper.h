//
//  RSMLibetpanHelper.h
//  SmartMail
//
//  Created by Viktor Gedzenko on 1/27/15.
//  Copyright (c) 2015 Readdle. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LibetpanHelper : NSObject

+ (NSDate *)dateFromRFC2822String:(NSString *)string;

@end
