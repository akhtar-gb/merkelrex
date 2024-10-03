//
//  MerkelMain.cpp
//  Merkelrex
//
//  Created by Akhtar on 08/10/2024.
//

#include "MerkelMain.hpp"
#include <string>
#include <iostream>
#include <vector>

// app initialisation function
void MerkelMain::init()
{
    loadOrderBook();
    int userOptionInput;
    while(true)
    {
        printMenu();                              // app menu options in the CLI
        userOptionInput = getUserOption();        // read and process user input
        processUserOption(userOptionInput);
    };
};

// ----------------------------- load order book
void MerkelMain::loadOrderBook()
{
    orders.push_back( OrderBookEntry { "2020/03/17 17:01:24.884492",
                                        "BTC/USDT",
                                        OrderBookType::bid,
                                        5348.8502489,
                                        2.46021} );
    
    orders.push_back(OrderBookEntry { "2020/03/17 17:01:24.884492",
                                        "BTC/USDT",
                                        OrderBookType::bid,
                                        4000.0001, 0.0001} );
};

// ----------------------------- menu options functions
void MerkelMain::printMenu()
{
    std::cout << "1: Print help" << std::endl;
    std::cout << "2: Print exchange stats" << std::endl;
    std::cout << "3: Make an ask" << std::endl;
    std::cout << "4: Make a bid" << std::endl;
    std::cout << "5: Print wallet" << std::endl;
    std::cout << "6: Continue" << std::endl;
    std::cout << "7: Exit" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
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
