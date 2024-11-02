//
//  main.cpp
//  Merkelrex
//
//  Created by Akhtar on 03/10/2024.
//

#include <iomanip>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <unistd.h>

#include "OrderBookEntry.hpp"
#include "MerkelMain.hpp"
#include "CSVReader.hpp"

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



//// main function -------------------------------------------------- //
//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    std::cout << std::fixed << std::setprecision(8);
//    
//    MerkelMain app{}; // instantating the app as an MerkelMain object
//    app.init();
////    return 0;
//};


int main()
{
    
//// ------------------------- tokenise algorithm testing ------------------ //
//////   string variable that stores the input string
//////    std::string s = "hello, I, have three tokens";
//////    std::string s {"thing0,thing1,thing2"}; // the string we are processing
////
////    /** test strings */
//////    std::string s {"x, y, 90, (), R, test2"};
////    std::string s {"2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02187308,7.44564869"};
////    
////    // char separator = ',' ## the character that separates the tokens
////    std::vector<std::string> tokens = tokensie(s, ',');
////    
////    // note the use of const and & below
////    // const says I won't edit t
////    for (const std::string& t : tokens)
////    {
////        std::cout << t << std::endl;
////    };
//    
//// ---------------------- test code for the cwd --------------------------- //
////    char cwd[1024];
////    if (getcwd(cwd, sizeof(cwd)) != nullptr) {
////        std::cout << "Current working dir: " << cwd << std::endl;
////    } else {
////        perror("getcwd() error");
////    }
//    
//    std::string csvFilename {"/Users/akhtar/Documents/computer-science/uol-bsc-cs/level-5/cm-2005-object-oriented-programming/merkelrex/merkelrex-xcode/Merkelrex/Merkelrex/20200317.csv"};
//    std::ifstream csvFile {csvFilename};
//    if (csvFile.is_open()) {
//        std::cout << "File opened: " << csvFilename << std::endl;
//        std::string line;
//        
//        // ------------------ read line and call tokenise ------------------------------------//
//        signed int lineCount {0};
//        while(std::getline(csvFile, line)){
//            lineCount++;
//            std::vector<std::string> tokens = tokensie(line, ',');
//            
//            if (tokens.size() != 5){
//                std::cout << "Read line " << lineCount << ": " << line << std::endl;
//                std::cout << "Unexpected token count " << tokens.size() << ": " << "skipping line " << lineCount << std::endl;
//                continue;
//            } else{
////                std::cout << "Read line " << lineCount << ": " << line << std::endl;
//            };
//            
//            // converting tokens into correct data types
//            try {
//                std::string timestamp = tokens[0];
//                std::string productPair = tokens[1];
//                OrderBookType orderType = OrderBookEntry::stringToOrderBookType(tokens[2]);
//                double price = std::stod(tokens[3]);
//                double amount = std::stod(tokens[4]);
//            } catch (const std::exception& e) {
//                std::cout << "Conversion failed: skipping line " << lineCount << std::endl;
//                continue;
//            }
//        };
//        
//        std::cout << "Lines read: " << lineCount << std::endl;
//    } else {
//        std::cout << "Problem opening file: " << csvFilename << std::endl;
//    };
//    
//    csvFile.close();
    
    // ------------------- testing CSVReader class object instance -------------------------//
    
    std::vector<OrderBookEntry> orderBook = CSVReader::readCSV("/Users/akhtar/Documents/computer-science/uol-bsc-cs/level-5/cm-2005-object-oriented-programming/merkelrex/merkelrex-xcode/Merkelrex/Merkelrex/20200317.csv");
    
    return 0;
};

