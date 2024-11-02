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

std::vector<OrderBookEntry> CSVReader::readCSV(std::string csvFile)
{
    std::vector<OrderBookEntry> entries;
    return entries;
};

std::vector<std::string> CSVReader::tokenise(std::string csvLine, char separator)
{
    std::vector<std::string> tokens;
    return tokens;
};

OrderBookEntry CSVReader::stringsToOBE(std::vector<std::string> tokens)
{
    OrderBookEntry obe{"", "", OrderBookType::bid, 0, 0};
    return obe;
};
