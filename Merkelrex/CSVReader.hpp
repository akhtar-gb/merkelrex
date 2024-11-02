//
//  CSVReader.hpp
//  Merkelrex
//
//  Created by Akhtar on 02/11/2024.
//

#ifndef CSVReader_hpp
#define CSVReader_hpp

#include <stdio.h>

#pragma once

#include "OrderBookEntry.hpp"
#include <vector>
#include <string>


class CSVReader{
public:
    
    CSVReader() = default;
    /** parse the sent CSV file into multiple
     OrderBookEntry objects which should contain lines like
     this:
     2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02187163,0.03322569
     */

    static std::vector<OrderBookEntry> readCSV(std::string csvFile);
    
private:
    static std::vector<std::string> tokenise(std::string csvLine, char separator);
    static OrderBookEntry stringsToOBE(std::vector<std::string> tokenstrings);
};



#endif /* CSVReader_hpp */
