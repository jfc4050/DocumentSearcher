//
//  CPPTesterWrapper.mm
//  Doc Searcher
//
//  Created by Justin Chiu on 9/20/17.
//  Copyright © 2017 Justin Chiu. All rights reserved.
//

//Wrapper Definition in CPPTesterWrapper.mm


#import "CPPTesterWrapper.h"
#include "CPPTester.hpp"

//Wrapper Definition
@implementation CPPTesterWrapper

- (void)hello_cpp_wrapped:(NSString *)name{
    CPPTester cpp;
    cpp.hello_cpp([name cStringUsingEncoding:NSUTF8StringEncoding]);
}


@end
