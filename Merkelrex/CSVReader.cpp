//
//  CSVReader.cpp
//  Merkelrex
//
//  Created by Akhtar on 02/11/2024.
//

#include "CSVReader.hpp"
#include <iostream>
#include <fstream>

//CSVReader::CSVReader()
//{
//    
//};

std::vector<OrderBookEntry> CSVReader::readCSV(std::string csvFilename)
{
    std::vector<OrderBookEntry> entries;
    std::ifstream csvFile {csvFilename};
    std::string line;
    signed int lineCount {0};
    
    if (csvFile.is_open()) {
        std::cout << "File opened: " << csvFilename << std::endl;
        
        while(std::getline(csvFile, line)){
            lineCount++;
            try {
//                std::string tokens = tokenise(line, ',');
                OrderBookEntry obe = stringsToOBE(tokenise(line, ','), line, lineCount);
                entries.push_back(obe);
            } catch (const std::exception& e) {
                std::cout << "CSVReader::readCSV() >> incorrect token(s) format or count" << std::endl;
            }
        };
    } else {
        std::cout << "Error opening file: " << csvFilename << std::endl;
    };

    std::cout << "CSVReader::readCSV() >> returned entries: " << entries.size() << std::endl;
    csvFile.close();
    return entries;
};

std::vector<std::string> CSVReader::tokenise(std::string csvLine, char separator)
{
    /** pseudocode implementation below*/
//    char separater = separator;
//    // string vector tokens ## stores the tokens
//    std::vector<std::string> tokens;
//    //    int start, end ## used to delineate the position of the tokens
//    signed int start, end;
//    //    start = csvLine.find_first_not_of(separator)
//    start = csvLine.find_first_not_of(separator, 0);
//    //    do
//    do
//    {
//        //    end = next 'separator' after start
//        end = csvLine.find_first_of(separator, start);
//        //    if start == csvLine.length or start == end ## nothing more to find
//        //    break
//        if (start == csvLine.length() || start == end) break;
//        //    if end >= 0 ## we found the separator
//        //    token = csvLine.substr(start, end - start) ## start, substring length
//        std::string token;
//        if (end >= 0) token = csvLine.substr(start, end - start);
//        //    else
//        //    token = csvLine.substr(start, csvLine.length - start) ## end is invalid
//        else token = csvLine.substr(start, csvLine.length() - start);
//        //    add token to the end of the tokens vector
//        //    Trim leading and trailing whitespace from the token
//        token.erase(0, token.find_first_not_of(" \t"));
//        token.erase(token.find_last_not_of(" \t") + 1);
//        tokens.push_back(token);
//        //    start = end + 1 ## move past this token
//        start = end + 1;
//    }
//    //    while (end > 0) ## continue loop condition
//    while (end > 0);
////    while (end != std::string::npos);
//    //
//    return tokens;
    
    std::vector<std::string> tokens;
    
    size_t start = csvLine.find_first_not_of(separator); // Start at first non-separator character
    size_t end;
    
    while (start != std::string::npos){
        end = csvLine.find_first_of(separator, start); // Find the next separator after 'start'
        
        std::string token = csvLine.substr(start, end - start);
        //    Trim leading and trailing whitespace from the token
        token.erase(0, token.find_first_not_of(" \t"));
        token.erase(token.find_last_not_of(" \t") + 1);
        tokens.push_back(token); // add the token
        
        if (end != std::string::npos) start = end + 1; // Move start to the next token
        else break; // exit the loop after the last token
    };
    
    return tokens;
};

OrderBookEntry CSVReader::stringsToOBE(std::vector<std::string> tokens, std::string line, int lineCount)
{
    double price, amount;

    if (tokens.size() != 5){
        std::cout << "Read line " << lineCount << ": " << line << " >> Unexpected token count " << tokens.size() << ": " << "skipping line " << lineCount << std::endl;
        throw std::exception{};
    } else{
//        std::cout << "Read line " << lineCount << ": " << std::endl;
    };
    
    // converting tokens into correct data types
    try {
        price = std::stod(tokens[3]);
        amount = std::stod(tokens[4]);
    } catch (const std::exception& e) {
//        std::cout << "Conversion failed: skipping line " << lineCount << std::endl;
        std::cout << "Conversion error: price float " << tokens[3] << std::endl;
        std::cout << "Conversion error: amount float " << tokens[4] << std::endl;
        throw;
    }
    
    OrderBookEntry obe{tokens[0], tokens[1], OrderBookEntry::stringToOrderBookType(tokens[2]),price, amount};
    return obe;
};
