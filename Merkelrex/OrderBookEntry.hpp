//
//  OrderBookEntry.hpp
//  Merkelrex
//
//  Created by Akhtar on 08/10/2024.
//

#ifndef OrderBookEntry_hpp
#define OrderBookEntry_hpp

#include <stdio.h>
#include <string>
#pragma once

enum class OrderBookType {bid, ask};

class OrderBookEntry
{
    public:
        /** Craete a new OrderBookEntry with the price set to the sent in value
         */
    OrderBookEntry(std::string _timestamp, std::string _product, OrderBookType _orderType, double _price, double _amount);
        std::string timestamp;
        std::string product;
        OrderBookType orderType;
        double price;
        double amount;
};

#endif /* OrderBookEntry_hpp */
