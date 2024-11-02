//
//  OrderBookEntry.cpp
//  Merkelrex
//
//  Created by Akhtar on 08/10/2024.
//

#include "OrderBookEntry.hpp"

OrderBookEntry::OrderBookEntry(std::string _timestamp, std::string _product, OrderBookType _orderType, double _price, double _amount):
                                timestamp(_timestamp), product(_product), orderType(_orderType), price(_price), amount(_amount)
{
    /**
     * assignment style syntax is not the preferred one in modern C++
     * data members assignment below converted to initialisation list above
     */
//    price = _price;
//    amount = _amount;
//    timestamp = _timestamp;
//    product = _product;
//    orderType = _orderType;
};

OrderBookType OrderBookEntry::stringToOrderBookType(const std::string& s)
{
    if (s == "ask") {
        return OrderBookType::ask;
    };
    if (s == "bid") {
        return OrderBookType::bid;
    };
    return OrderBookType::unknown;
};
