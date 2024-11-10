//
//  OrderBook.cpp
//  Merkelrex
//
//  Created by Akhtar on 02/11/2024.
//

#include "OrderBook.hpp"

/** constructor for the OrderBook object instantiated in MerkelMain.hpp as orders -- see line 42 */
OrderBook::OrderBook(std::string filename)
{
    OrderBook::orders = CSVReader::readCSV(filename);
};

/* Lecture version
std::vector<std::string> OrderBook::getKnownProducts()
{
    std::map<std::string, bool> prodMap;
    
    for (const OrderBookEntry& e : orders)
    {
        // passing in the product pair as the key and setting its value to true
        // subsequent iteration overwites the key if found again in subsequent strings with value set to true
        prodMap[e.productPair] = true;
    };
    
    std::vector<std::string> productPairs;
    for (const auto& e : prodMap)
    {
        productPairs.push_back(e.first);
    };
    
    return productPairs;
};
*/

/* Challenge version */
std::vector<std::string> OrderBook::getKnownProducts()
{
    std::unordered_set<std::string> uniqueProductPairs;
    for (const OrderBookEntry& e : orders)
    {
        uniqueProductPairs.insert(e.productPair);
    };
    
    std::vector<std::string> productPairs;
    for (const auto& productPair : uniqueProductPairs)
    {
        productPairs.push_back(productPair);
    };
    return productPairs;
};

/** order quesry function ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
std::vector<OrderBookEntry> OrderBook::getOrders(std::string timestamp, std::string productPair, OrderBookType type)
{
    std::vector<OrderBookEntry> queriedOrders;
    
    for (OrderBookEntry& e : orders){
        if (e.timestamp == timestamp && e.productPair == productPair && e.orderType == type)
        {
            queriedOrders.push_back(e);
        };
    };
    return queriedOrders;
};

/** time frame functions ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
std::string OrderBook::getEarliestTime()
{
    return orders[0].timestamp;
};

std::string OrderBook::getNextTime(const std::string& timestamp)
{
    std::string next_timestamp {""};
    
    for (OrderBookEntry& e : orders){
        if (e.timestamp > timestamp)
        {
            next_timestamp = e.timestamp;
            break;
        } else if (next_timestamp == ""){
            // reset timestamp to the earlies time if no next_timestamp
            next_timestamp = getEarliestTime();
        }
    };
    return next_timestamp;
};

/** statistical functions ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
double OrderBook::getHighPrice(std::vector<OrderBookEntry>& orders)
{
    double max {orders[0].price};
    
    for (OrderBookEntry& e : orders){
        if (e.price > max) max = e.price;
    };
    return max;
};

double OrderBook::getLowPrice(std::vector<OrderBookEntry>& orders)
{
    double min {orders[0].price};
    
    for (OrderBookEntry& e : orders){
        if (e.price < min) min = e.price;
    };
    return min;
};

double OrderBook::computeSpread(double minAsk, double maxBid)
{
    double spread {minAsk - maxBid};
    return spread;
};

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

