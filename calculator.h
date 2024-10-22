//
// Created by Krankfried on 09.10.24.
// Copyright (c) 2024 All rights reserved.
//

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <array>
#include <tuple>


double calc(double r1, char op, double r2);

class calculator {
private:
std::array<std::string, 9> const messages;
std::tuple<double, char, double, double> calc_history;


public:
 [[nodiscard]] std::tuple<double, char, double, double> getHistory() const{
     return calc_history;
 }
 [[nodiscard]] std::array<std::string, 9> greetUser() const {
    return messages;
 }
};


#endif //CALCULATOR_H

