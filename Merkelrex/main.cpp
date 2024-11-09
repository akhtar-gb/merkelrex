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

// main function -------------------------------------------------- //

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << std::fixed << std::setprecision(8);
    
    MerkelMain app{}; // instantating the app as an MerkelMain object
    app.init();
//    return 0;
};

