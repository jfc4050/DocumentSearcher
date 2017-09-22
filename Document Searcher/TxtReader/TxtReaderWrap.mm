//
//  TxtReaderWrap.m
//  Document Searcher
//
//  Created by Justin Chiu on 9/20/17.
//  Copyright © 2017 Justin Chiu. All rights reserved.
//

#import "TxtReaderWrap.h"
#include "TxtReader.hpp"

@implementation TxtReaderWrap

-(int)readAndCount_wrapped:(NSString*)filePath
                          second:(NSString*)query {
    TxtReader txt;
    std::string stdPath = std::string([filePath UTF8String]);
    std::string stdQuery = std::string([query UTF8String]);
    int count = txt.readAndCountNaive(stdPath, stdQuery);
    return count;
}

-(int)rabinKarp_wrapped:(NSString *)filePath
         second:(NSString *)query {
    TxtReader txt;
    std::string stdPath = std::string([filePath UTF8String]);
    std::string stdQuery = std::string([query UTF8String]);
    int count = txt.readAndCountRK(stdPath, stdQuery);
    return count;
}

@end
