//
//  MerkelMain.cpp
//  Merkelrex
//
//  Created by Akhtar on 08/10/2024.
//

#include "MerkelMain.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>

// app initialisation function
void MerkelMain::init()
{
    std::cout << "===================================================================================================================" << std::endl;
    std::cout << "Welcome to Merkelrex Trading Simulation" << std::endl;
    
    loadOrderBook();
    int userInput;
    while(true)
    {
        printMenu();                        // app menu options in the CLI
        userInput = getUserOption();        // read and process user input
        processUserOption(userInput);
    };
};

// ----------------------------- load order book
void MerkelMain::loadOrderBook()
{
//    orders = CSVReader::readCSV("/Users/akhtar/Documents/computer-science/uol-bsc-cs/level-5/cm-2005-object-oriented-programming/merkelrex/merkelrex-xcode/Merkelrex/Merkelrex/20200317.csv");
//    std::cout << "MerkelMain::loadOrderBook() >> read orders: " << orders.size() << std::endl;
};

// ----------------------------- menu options functions
void MerkelMain::printMenu()
{
    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "1: Print help" << std::endl;
    std::cout << "2: Print exchange stats" << std::endl;
    std::cout << "3: Make an ask" << std::endl;
    std::cout << "4: Make a bid" << std::endl;
    std::cout << "5: Print wallet" << std::endl;
    std::cout << "6: Continue" << std::endl;
    std::cout << "7: Exit" << std::endl;
    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
};

int MerkelMain::getUserOption(){
    std::cout << "Type in 1-7" << std::endl;
    
    int userOption;
    std::cin >> userOption;
    
    if (std::cin.fail() || userOption < 1 || userOption > 7)
    {
        processInvalidUserIput();
        std::cout << "Invalid input. Please enter an integer between 1 and 7. \n" << std::endl;
    }
    else
    {
        std::cout << ">> You chose: " << userOption << "\n" << std::endl;
    };
    
    return userOption;
};

void MerkelMain::printHelp()
{
    std::cout << "Help - your aim is to make money." << std::endl;
    std::cout << "Analyse the market and make bids" << std::endl;
    std::cout << "and offers. \n" << std::endl;
    std::cout << "Choose options from the menu" << std::endl;
    std::cout << "and follow the on screen instructions \n" << std::endl;
};

void MerkelMain::printMarketStats()
{
    std::cout << "Check ask/bid rates" << std::endl;
    std::cout << "and compare to other exchanges \n" << std::endl;
    
    // print timeStamp
    std::string timeStamp{"2020/03/17 17:01:24.884492"};
    std::cout << "Timestamp: " << timeStamp << std::endl;
    
    // table setup
    const int productPairWidth {12};
    const int ordertypeWidth {12};
    const int maxPriceWidth {15};
    const int minPriceWidth {15};
    const int spreadWidth {19};
    
    std::cout << std::left
              << std::setw(productPairWidth) << "Product Pair" << " | "
              << std::setw(ordertypeWidth) << "Asks Seen"
              << std::setw(maxPriceWidth) << "Max Price"
              << std::setw(minPriceWidth) << "Min Price" << " | "
              << std::setw(ordertypeWidth) << "Bids Seen"
              << std::setw(maxPriceWidth) << "Max Price"
              << std::setw(minPriceWidth) << "Min Price" << " | "
              << std::setw(spreadWidth) << "Spread"
              << std::endl;
    
    // seperator line
    int simConsoleWidth {productPairWidth + ordertypeWidth * 2 + maxPriceWidth * 2 + minPriceWidth * 2 + spreadWidth};
    std::cout << std::string(simConsoleWidth, '-') << std::endl;
    
    for (std::string const& p : orderBook.getKnownProducts())
    {
        /** cout for testing */
//         std::vector<OrderBookEntry> entries = orderBook.getOrders("2020/03/17 17:01:24.884492", p, OrderBookType::ask);
//         std::cout << "Product: " << p << std::endl;
//         std::cout << "Bids seen: " << entries.size() << std::endl;
//         std::cout << "Max price: " << OrderBook::getHighPrice(entries) << std::endl;
//         std::cout << "Min price: " << OrderBook::getLowPrice(entries) << "\n" << std::endl;
         
        /** prinitng the stats table */
        std::vector<OrderBookEntry> askEntries = orderBook.getOrders(timeStamp, p, OrderBookType::ask);
        std::vector<OrderBookEntry> bidEntries = orderBook.getOrders(timeStamp, p, OrderBookType::bid);
        
    // calculate ask statistics
        int asksSeen = askEntries.size();
        double maxAskPrice = asksSeen > 0 ? OrderBook::getHighPrice(askEntries) : 0;
        double minAskPrice = asksSeen > 0 ? OrderBook::getLowPrice(askEntries) : 0;
        
    // calculate bid statistics
        int bidsSeen = bidEntries.size();
        double maxBidPrice = bidsSeen > 0 ? OrderBook::getHighPrice(bidEntries) : 0;
        double minBidPrice = bidsSeen > 0 ? OrderBook::getLowPrice(bidEntries) : 0;
        
        std::cout << std::left
                  << std::setw(productPairWidth) << p << " | "
                  << std::setw(ordertypeWidth) << asksSeen
                  << std::setw(maxPriceWidth) << OrderBook::getHighPrice(askEntries)
                  << std::setw(minPriceWidth) << OrderBook::getHighPrice(askEntries) << " | "
                  << std::setw(ordertypeWidth) << bidsSeen
                  << std::setw(maxPriceWidth) << OrderBook::getHighPrice(bidEntries)
                  << std::setw(minPriceWidth) << OrderBook::getHighPrice(bidEntries) << " | "
                  << std::setw(minPriceWidth) << OrderBook::computeSpread(minAskPrice, maxBidPrice)
                  << std::endl;
    };
    
//    std::cout << "\n" << std::endl;
};

void MerkelMain::enterAsk()
{
    std::cout << "Place a sell call to the exchange" << std::endl;
    std::cout << "and wait for buyers \n" << std::endl;
    std::cout << "Make an offer - enter the amount \n" << std::endl;
};

void MerkelMain::enterBid()
{
    std::cout << "Place a bid for your order" << std::endl;
    std::cout << "and wait for sellers \n" << std::endl;
    std::cout << "Make a bid - enter the amount \n" << std::endl;
};

void MerkelMain::printWallet()
{
    std::cout << "Check your wallet" << std::endl;
    std::cout << "and see how much you have \n" << std::endl;
    std::cout << "Your wallet is empty. \n" << std::endl;
};

void MerkelMain::gotoNextTimeframe()
{
    std::cout << "Go to the next time frame" << std::endl;
    std::cout << "and select the next option \n" << std::endl;
};

void MerkelMain::exitApp()
{
    std::cout << "Exiting \n" << std::endl;
    exit(0);
};

void MerkelMain::processInvalidUserIput()
{
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    };
};


void MerkelMain::processUserOption(int userOption)
{
    switch(userOption)
    {
        case 1: printHelp();
            break;
        case 2: printMarketStats();
            break;
        case 3: enterAsk();
            break;
        case 4: enterBid();
            break;
        case 5: printWallet();
            break;
        case 6: gotoNextTimeframe();
            break;
        case 7: exitApp();
            break;
        default:
            processInvalidUserIput();
    };
};
