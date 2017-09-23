//
//  TxtReaderWrap.m
//  Document Searcher
//
//  Created by Justin Chiu on 9/20/17.
//  Copyright © 2017 Justin Chiu. All rights reserved.
//

#import "TxtReaderWrap.h"
#import "TxtReader.hpp"

@interface TxtReaderWrap () {
    TxtReader *txt;
}

-(std::string)convertStrToStd:(NSString*)NSInput;
-(NSMutableDictionary*)levenshteinEachWord:(NSString*)filePath
                                    second:(NSString*)query;

@end


@implementation TxtReaderWrap

-(id)init {
    if (self = [super init]) {
        txt = new TxtReader();
    }
    return self;
}
-(void)dealloc {
    delete txt;
}

-(std::string)convertStrToStd:(NSString*)NSInput {
    return std::string([NSInput UTF8String]);
}

-(int)readAndCount_wrapped:(NSString*)filePath
                    second:(NSString*)query
{
    std::string stdPath = std::string([filePath UTF8String]);
    std::string stdQuery = std::string([query UTF8String]);
    
    int count = txt->readAndCountNaive(stdPath, stdQuery);
    return count;
}

-(int)rabinKarp_wrapped:(NSString*)filePath
                 second:(NSString*)query
{
    std::string stdPath = std::string([filePath UTF8String]);
    std::string stdQuery = std::string([query UTF8String]);
    
    int count = txt->readAndCountRK(stdPath, stdQuery);
    return count;
}

-(NSMutableDictionary*)levenshteinEachWord:(NSString*)filePath
                                    second:(NSString*)query {
    
    std::string stdPath = std::string([filePath UTF8String]);
    std::string stdQuery = std::string([query UTF8String]);
    
    NSMutableDictionary* NSMap;
    
    for (auto entry : txt->levenshteinEachWord(stdPath, stdQuery, false)) {
        std::string stdKey = entry.first;
        int stdVal = entry.second;
        NSString* NSKey = [NSString stringWithUTF8String:stdKey.c_str()];
        NSNumber* NSVal = [NSNumber numberWithInt:stdVal];
        NSMap[NSKey] = NSVal;
    }
    return NSMap;
}


@end
