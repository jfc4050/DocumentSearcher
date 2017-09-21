//
//  TxtReader.cpp
//  Document Searcher
//
//  Created by Justin Chiu on 9/20/17.
//  Copyright © 2017 Justin Chiu. All rights reserved.
//


// C++ Class Definition in TxtReader.cpp

#include "TxtReader.hpp"

//int TxtReader::readAndCount(const std::string& filePath,
//                            const std::string& query) {
//    inFile.open(filePath);                    //associate fstream variable (inFile) with input source (@filePath)
//    int count = 0;
//    std::string currentWord;
//    while (inFile >> currentWord) {
//        if (currentWord == query) {
//            count++;
//        }
//    }
//    inFile.close();
//    return count;
//}


int TxtReader::readAndCount(const std::string& filePath,
                            const std::string& query) {
    std::stringstream sStr(query);
    std::string word;
    std::vector<std::string> words;
    //Generate vector of individual words
    while (sStr >> word) {
        words.push_back(word);
    }
    
    inFile.open(filePath);                    //associate fstream variable (inFile) with input source (@filePath)
    int count = 0;
    std::string currentWord;
    while (inFile >> currentWord) {
        bool match = false;
        int i = 0;
        if (currentWord == words[0]) {
            match = true;
            i++;
        }
        while (match and i < words.size()) {
            inFile >> currentWord;
            if (currentWord != words[i]) {
                match = false;
                break;
            }
            i++;
        }
        if (match) count++;
    
    }
    inFile.close();
    return count;
}
