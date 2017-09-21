//
//  CppWrap2.m
//  Document Searcher
//
//  Created by Justin Chiu on 9/20/17.
//  Copyright © 2017 Justin Chiu. All rights reserved.
//

#import "CppWrap2.h"
#include "CppTest2.hpp"

@implementation CppWrap2

- (NSString*)concatenate_wrapped:(NSString*)name {
    CppTest2 cpp;
    std::string stdName = std::string([name UTF8String]);
    std::string stdOutput = cpp.concatenate(stdName);
    return @(stdOutput.c_str());
}

@end
