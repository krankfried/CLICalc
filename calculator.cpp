//
// Created by Krankfried on 09.10.24.
// Copyright (c) 2024 All rights reserved.
//

#include "calculator.h"
#include <iostream>

//This file contains the calculation related logic
// TODO: Access the lastcarray by reference and update the calculation history directly from this function.

double calc(double r1, char op, double r2) {

    switch (op)
    {
        case '+': //Addition - Char
            return r1 + r2;
        case '-':	//Substraktion - Char
            return r1 - r2;
        case '/': //Division - Char
            if (r2 != 0) {
                return r1 / r2;
            }
            else {
                std::cerr << "Error: Cant divide by zero!" << std::endl;
                return 0;
            }
        case '*': //Multiplikation
            return r1 * r2;
        default:
            std::cerr << "Error: Invalid arguments\nExample use: 100+200." << std::endl;
            return 0;
    }
}

std::tuple<double, char, double> getHistory {

};
void setHistory() {

}
void updateHistory() {

}


/*void greetUser() {
    std::cout << "Hello, welcome to the Simple CLI Calculator by Krankfried\n" << motd[rdm_index] << std::endl;
    std::cout << "Example Use: 200+200" << std::endl;
}*/
