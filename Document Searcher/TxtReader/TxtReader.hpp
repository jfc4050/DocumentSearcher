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
#include <cassert>

class TxtReader {
public:
    std::ifstream inFile;
    std::string wordInQuery;
    std::vector<std::string> wordsInQuery;//Declare ifstream Object inFile
    
    int readAndCountNaive(const std::string& filePath,
                     const std::string& query);
    
    int rabinFingerprint(const std::string& inputStr, const int base);
    
    int readAndCountRK(const std::string& filePath,
                                  const std::string& query);
    
    int levenshteinDistance(const std::string& str, const std::string& target);
};

