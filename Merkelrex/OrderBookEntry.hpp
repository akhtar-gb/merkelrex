//
//  OrderBookEntry.hpp
//  Merkelrex
//
//  Created by Akhtar on 08/10/2024.
//

#ifndef OrderBookEntry_hpp
#define OrderBookEntry_hpp

#include <stdio.h>

#pragma once

#include <string>

enum class OrderBookType {bid, ask, unknown};

class OrderBookEntry
{
    public:
        /** Craete a new OrderBookEntry with the price set to the sent in value
         */
        OrderBookEntry(std::string _timestamp, std::string _productPair, OrderBookType _orderType, double _price, double _amount);
        std::string timestamp;
        std::string productPair;
        OrderBookType orderType;
        double price;
        double amount;
        
        static OrderBookType stringToOrderBookType(const std::string& s);
};

#endif /* OrderBookEntry_hpp */
