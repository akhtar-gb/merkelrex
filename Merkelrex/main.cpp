//
//  main.cpp
//  Merkelrex
//
//  Created by Akhtar on 03/10/2024.
//

#include <iomanip>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <unistd.h>

#include "OrderBookEntry.hpp"
#include "MerkelMain.hpp"
#include "CSVReader.hpp"

//// ------------------- useful functions -------------------------- //
//double computeAveragePrice(std::vector<OrderBookEntry>& entries)
//{
//    double sum = 0;
//    for (OrderBookEntry& e : entries)
//    {
//        sum += e.price;
//    };
//    return sum / entries.size();
//};
//
//double computeLowPrice(std::vector<OrderBookEntry>& entries)
//{
//    double lowPrice = entries[0].price;
//    for (OrderBookEntry& e : entries)
//    {
//        if (e.price < lowPrice) lowPrice = e.price;
//    };
//    return lowPrice;
//};
//
//double computeHighPrice(std::vector<OrderBookEntry>& entries)
//{
//    double highPrice = entries[0].price;
//    for (OrderBookEntry& e : entries)
//    {
//        if (e.price > highPrice) highPrice = e.price;
//    };
//    return highPrice;
//};
//
//double computeSpread(std::vector<OrderBookEntry>& entries)
//{
//    double spread = 0;
//    for (OrderBookEntry& e : entries)
//    {
//        spread = computeLowPrice(entries) - computeHighPrice(entries);
//    };
//    return spread;
//};



//// main function -------------------------------------------------- //

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << std::fixed << std::setprecision(8);
    
    MerkelMain app{}; // instantating the app as an MerkelMain object
    app.init();
//    return 0;
};

