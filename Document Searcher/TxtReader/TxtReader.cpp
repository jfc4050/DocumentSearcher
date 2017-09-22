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

// NAIVE ALGORITHM
int TxtReader::readAndCountNaive(const std::string& filePath, const std::string& query) {
    
    //Generate Vector of words in query
    std::stringstream sStr(query);
    std::string wordInQuery;
    std::vector<std::string> wordsInQuery;
    while (sStr >> wordInQuery)
        wordsInQuery.push_back(wordInQuery);
    
    inFile.open(filePath);
    int count = 0;
    std::string currentWord;
    while (inFile >> currentWord) {
        bool match = false;
        int i = 0;
        if (currentWord == wordsInQuery[0]) {
            match = true;
            i++;
        }
        while (match and i < wordsInQuery.size()) {
            inFile >> currentWord;
            if (currentWord != wordsInQuery[i]) {
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


// Rabin Fingerprint Generator
int TxtReader::rabinFingerprint(const std::string& inputStr, const int base=101) {
    int hash = 0;
    int i = 0;
    for (char currChar : inputStr) {
        hash += currChar*(base^i);
        i++;
    }
    return hash;
}


// RABIN-KARP ALGORITHM
int TxtReader::readAndCountRK(const std::string& filePath, const std::string& query) {
    
    // Generate vector of characters in file
    inFile.open(filePath);
    std::vector<char> fileChars;
    char charIn;
    while (inFile >> std::noskipws >> charIn)
        fileChars.emplace_back(charIn);
    inFile.close();
    
    // Iterate through vector of characters in file, looking for target hash value
    int target = rabinFingerprint(query);
    int count = 0;
    for (auto iter = fileChars.begin() ; iter < fileChars.end() ; ++iter) {
        if (*iter == query.at(0)) {
            std::string candidateStr(iter, iter+query.size());
            if (rabinFingerprint(candidateStr) == target) {
                count++;
            }
        }
    }
    return count;
}



