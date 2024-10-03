//
//  main.cpp
//  Merkelrex
//
//  Created by Akhtar on 03/10/2024.
//

#include <iomanip>
#include <iostream>
#include <map>
#include <vector>
#include <string>

#include "OrderBookEntry.hpp"
#include "MerkelMain.hpp"

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



// main function -------------------------------------------------- //

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << std::fixed << std::setprecision(8);
    
    
//    // -------------- data structure - vector creating and testing -- //
//    // defining vectors to store data for each attribute/column
//    std::vector<double> prices;
//    std::vector<double> amounts;
//    std::vector<std::string> timestamps;
//    std::vector<std::string> products;
//    std::vector<OrderBookType> orderTypes;
//    
//    // push_back value for each data type in the vectors for each type
//    prices.push_back(5348.8502489);
//    amounts.push_back(2.46021);
//    timestamps.push_back("2020/03/17 17:01:24.884492");
//    products.push_back("BTC/USDT");
//    orderTypes.push_back(OrderBookType::bid);
//    
//    prices.push_back(4000.0001);
//    amounts.push_back(0.0001);
//    timestamps.push_back("2020/03/17 17:01:24.884492");
//    products.push_back("BTC/USDT");
//    orderTypes.push_back(OrderBookType::bid);
//    
    // accessing the values in each vector
//    std::cout << "First row price: " << prices[0] << std::endl;
//    std::cout << "First row amounts: " << amounts[0] << std::endl;
//    std::cout << "First row timestamp: " << timestamps[0] << std::endl;
//    std::cout << "First row prodcuts: " << products[0] << std::endl;
//    std::cout << "First row price: " << (orderTypes[0] == OrderBookType::bid ? "bid" : "ask") << std::endl;
    
    // -------------- order book entry class object creation testing --- //
//    OrderBookEntry obe1 {0.125, 2.46021, "2020/03/17 17:01:24.884492", "BTC/USDT", OrderBookType::bid};
//    OrderBookEntry obe2 {0.5, 2.46021, "2020/03/17 17:01:24.884492", "BTC/USDT", OrderBookType::bid};
//    OrderBookEntry obe1 {"2020/06/01 11:57:30.328127", "ETH/BTC", OrderBookType::bid, 0.02482205, 23.9999428};
//    OrderBookEntry obe2 {"2020/06/01 11:57:30.328127", "ETH/BTC", OrderBookType::bid, 0.02481485, 65.};
//    OrderBookEntry obe3 {"2020/06/01 11:57:30.328127", "ETH/BTC", OrderBookType::bid, 0.02480983, 0.39562087};
//    OrderBookEntry obe4 {"2020/06/01 11:57:30.328127", "ETH/BTC", OrderBookType::bid, 0.02480883, 8.05447423};
//    OrderBookEntry obe5 {"2020/06/01 11:57:30.328127", "ETH/BTC", OrderBookType::bid, 0.02480882, 3.};
//    OrderBookEntry obe6 {"2020/06/01 11:57:30.328127", "ETH/BTC", OrderBookType::bid, 0.02480866, 3.702};
//    OrderBookEntry obe7 {"2020/06/01 11:57:30.328127", "ETH/BTC", OrderBookType::bid, 0.02480841, 31.13304484};
    
//    entries.push_back(obe1);
//    entries.push_back(obe2);
//    entries.push_back(obe3);
//    entries.push_back(obe4);
//    entries.push_back(obe5);
//    entries.push_back(obe6);
//    entries.push_back(obe7);
//    
//    for (OrderBookEntry& e : entries)
//    {
//        std::cout << e.price << std::endl;
//    };
//    
//    std::cout << "entries vector size: " << entries.size() << std::endl;
//    
//    double averagePrice = computeAveragePrice(entries);
//    std::cout << "Average price: " << averagePrice << std::endl;
//    
//    double lowestPrice = computeLowPrice(entries);
//    std::cout << "Low price: " << lowestPrice << std::endl;
//    
//    double highestPrice = computeHighPrice(entries);
//    std::cout << "High price: " << highestPrice << std::endl;
//    
//    double spread = computeSpread(entries);
//    std::cout << "Spread: " << spread << std::endl;
    
    // ----------------------- commented out for testing the cout of the values pushed back into the vector
    
    MerkelMain app{}; // instantating the app as an MerkelMain object
    app.init();
//    return 0;
};


