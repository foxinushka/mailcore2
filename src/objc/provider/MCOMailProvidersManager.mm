//
//  MCOMailProvidersManager.m
//  mailcore2
//
//  Created by Robert Widmann on 4/28/13.
//  Copyright (c) 2013 MailCore. All rights reserved.
//

#import "MCOMailProvidersManager.h"
#include "MCMailProvidersManager.h"
#import "MCOMailProvider.h"

#import "NSString+MCO.h"
#import "NSDictionary+MCO.h"
#import "NSObject+MCO.h"

@implementation MCOMailProvidersManager 

+ (MCOMailProvidersManager *) sharedManager
{
    static MCOMailProvidersManager * sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[self alloc] init]; \
    });
    return sharedInstance;
}

- (id) init {
    if (self = [super init]) {
        NSString *pathRes = [self pathForProvidersJSONInResources];
        NSString *pathDoc = [self pathForProvidersJSONInDocuments];
        
        BOOL jsonExistAtDoc = NO;
        NSFileManager *fm = [NSFileManager defaultManager];
        if (pathRes.length && pathDoc.length) {
            if ([fm fileExistsAtPath:pathRes] && ![fm fileExistsAtPath:pathDoc]) {
                jsonExistAtDoc = [fm copyItemAtPath:pathRes toPath:pathDoc error:nil];
            } else if ([fm fileExistsAtPath:pathDoc]) {
                jsonExistAtDoc = YES;
            }
        }
        
        if (jsonExistAtDoc) {
            mailcore::MailProvidersManager::sharedManager()->registerProvidersWithFilename(pathDoc.mco_mcString);
        }
    }
    
    return self;
}

- (MCOMailProvider *) providerForEmail:(NSString *)email
{
    mailcore::MailProvider *provider = mailcore::MailProvidersManager::sharedManager()->providerForEmail(email.mco_mcString);
    return MCO_TO_OBJC(provider);
}

- (MCOMailProvider *) providerForMX:(NSString *)hostname
{
    mailcore::MailProvider *provider = mailcore::MailProvidersManager::sharedManager()->providerForMX(hostname.mco_mcString);
    return MCO_TO_OBJC(provider);
}

- (MCOMailProvider *) providerForIdentifier:(NSString *)identifier
{
    mailcore::MailProvider *provider = mailcore::MailProvidersManager::sharedManager()->providerForIdentifier(identifier.mco_mcString);
    return MCO_TO_OBJC(provider);
}

- (void)registerProvidersWithFilename:(NSString *)filename
{
    mailcore::MailProvidersManager::sharedManager()->registerProvidersWithFilename(filename.mco_mcString);
}

- (NSString *)pathForProvidersJSONInDocuments {
    return [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES)[0] stringByAppendingPathComponent:@"providers.json"];
}

- (NSString *)pathForProvidersJSONInResources {
    return [[NSBundle bundleForClass:[self class]] pathForResource:@"providers" ofType:@"json"];
}

- (void)updateRegisteredProviders {
    NSString *pathDoc = [self pathForProvidersJSONInDocuments];
    if (pathDoc.length && [[NSFileManager defaultManager] fileExistsAtPath:pathDoc]) {
        mailcore::MailProvidersManager::sharedManager()->registerProvidersWithFilename(pathDoc.mco_mcString, true);
    }
}

@end
