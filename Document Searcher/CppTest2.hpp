//
//  CppTest2.hpp
//  Document Searcher
//
//  Created by Justin Chiu on 9/20/17.
//  Copyright © 2017 Justin Chiu. All rights reserved.
//


// Declaration of Cpp Class in CppTest2.hpp

#ifndef CppTest2_hpp
#define CppTest2_hpp

#include <string>

class CppTest2{
public:
    std::string concatenate(const std::string stringIn);
};

#endif /* CppTest2_hpp */

//#ifndef,
//#endif prevent header file from being included multiple times
//similar effect as #pragma once
