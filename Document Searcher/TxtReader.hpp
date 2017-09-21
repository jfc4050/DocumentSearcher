//
//  TxtReader.hpp
//  Document Searcher
//
//  Created by Justin Chiu on 9/20/17.
//  Copyright © 2017 Justin Chiu. All rights reserved.
//


// C++ Class Declaration in TxtReader.hpp

#pragma once
#define TxtReader_hpp

#include <fstream>
#include <string>
#include <sstream>
#include <vector>

class TxtReader {
public:
    std::ifstream inFile;                               //Declare ifstream Object inFile
    int readAndCount(const std::string& filePath,       //Search input file @ provided filePath for query
                     const std::string& query);
};

