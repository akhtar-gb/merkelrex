//
//  OrderBook.hpp
//  Merkelrex
//
//  Created by Akhtar on 02/11/2024.
//

#ifndef OrderBook_hpp
#define OrderBook_hpp

#include <stdio.h>

#pragma once

#include "OrderBookEntry.hpp"
#include "CSVReader.hpp"
#include <string>
#include "vector"
#include <map>
#include <unordered_set>

class OrderBook
{
    public:
        /** constructor, reading a csv file */
        OrderBook(std::string filename);
        /** return a vector of all known products in the dataset */
        std::vector<std::string> getKnownProducts();
        /** return vector of Orders according to the sent filters */
        std::vector<OrderBookEntry> getOrders(std::string timestamp, std::string product, OrderBookType type);
        /** return the price of the highest bid in the sent set */
        static double getHighPrice(std::vector<OrderBookEntry>& orders);
        /** return the price of the lowest bid in the sent set */
        static double getLowPrice(std::vector<OrderBookEntry>& orders);
        /** return the spread = {Min Ask Price} -{Max Bid Price} */
        static double computeSpread(double minAsk, double maxBid);
    
    private:
        std::vector<OrderBookEntry> orders;
};

#endif /* OrderBook_hpp */
