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
        void gotoNextTimeframe();
        void exitApp();
        void processInvalidUserIput();
        void processUserOption(int userOption);
    
        std::vector<OrderBookEntry> orders;         // vector data structure to hold orders
};

#endif /* MerkelMain_hpp */
