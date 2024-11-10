//
//  MerkelMain.hpp
//  Merkelrex
//
//  Created by Akhtar on 08/10/2024.
//

#ifndef MerkelMain_hpp
#define MerkelMain_hpp

#include <stdio.h>
#include <vector>
#include "OrderBookEntry.hpp"
#include "CSVReader.hpp"
#include "OrderBook.hpp"

class MerkelMain
{
//    <#instance variables#>
    public:
        MerkelMain() = default; // default constructor
        
        /** Call the initialise function to start the app */
        void init();
        
    private:
        void loadOrderBook();                       // function to load data from order book vector
    
        void printMenu();
        int getUserOption();
        void printHelp();
        void printMarketStats();
        void enterAsk();
        void enterBid();
        void printWallet();
        void exitApp();
        void processInvalidUserIput();
        void processUserOption(int userOption);
    
        void gotoNextTimeframe();
    
        std::string currentTime;
    
//        std::vector<OrderBookEntry> orders;         // vector data structure to hold orders
        // new way to represent orders
        OrderBook orderBook{"/Users/akhtar/Documents/computer-science/uol-bsc-cs/level-5/cm-2005-object-oriented-programming/merkelrex/merkelrex-xcode/Merkelrex/Merkelrex/20200317.csv"};
};

#endif /* MerkelMain_hpp */
