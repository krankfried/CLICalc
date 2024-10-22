//Created by krankfried, for personal learning purposes
#include <iostream>
#include <fstream>
#include <tuple>
#include <string>
#include <array>
#include <random>
#include <regex>
#include <sstream>
#include <iomanip>
#include "calculator.h"


//Todo Create a more advanced history and update history within the calc() function by accessing the tuple by reference
//Todo New Project: Simple Notes Program with buffer saving to file



int main()
{

    calculator calc = calculator();

    //Todo Create advanced history with file saving, read out array and write calculations to file

    constexpr int size = 5;

    std::tuple<double, char , double, double>  historytuple[size];
    [[maybe_unused]] bool calcmode {false};
    std::array<std::string, 10> motd = {
            "Why don't scientists trust atoms?\nBecause they make up everything!", "Why did the scarecrow win an award?\nBecause he was outstanding in his field!", "Why don't skeletons fight each other?\nThey don't have the guts!", "Why did the bicycle fall over?\nBecause it was two-tired!", "What do you call fake spaghetti?\nAn impasta!",
            "How does a penguin build its house?\nIgloos it together!", "Why did the math book look sad?\nBecause it had too many problems.", "What did the grape do when it got stepped on?\nNothing, it just let out a little wine!", "How do you organize a space party?\nYou planet!", "Why don't some couples go to the gym?\nBecause some relationships don’t work out."
    };
    std::random_device rd;

    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis(0, 9);

    const int rdm_index = dis(gen);
    auto history = calc.getHistory();
    auto messages = calc.greetUser();
    std::string userinput;
    std::regex const pattern(R"(^[-+]?[0-9]*\.?[0-9]+[+\-*/][-+]?[0-9]*\.?[0-9]+$)");

    std::cout << "Hello, welcome to the Simple CLI Calculator by Krankfried\n" << motd[rdm_index] << std::endl;
    std::cout << "Example Use: 200+200" << std::endl;



    //Beginning the Main Loop , Fix line spamming while retrieving inputStream dataTypes and calc() function
    while(true) {
        std::getline(std::cin, userinput);
        //Checking for the abort command, before checking for regex condition
        if(userinput.contains("abort") || userinput.contains("exit")) {
            std::cout << "Thank you for using my calculator\nCalculator will shut down now\nPress enter to continue";
            std::cin.ignore();
            break;
        }
        if(userinput.contains("history") || userinput.contains("h")) {
                //Is meant to call the getHistory() function and interate over it to print out all results
                std::cout << "Damn you found a not yet implemented function!" << std::endl;
        }
        //Check if userinput matches condition, only contains mathematical expressions
        if(std::regex_match(userinput, pattern)) {
            std::stringstream inputStream(userinput);
            char op {'+'};
            double a {0};
            double b {0};
            double result {0};
            //Iterating through the userinput stream obtaining the doubles and char
            while(inputStream >> a) {
                if(inputStream >> op >> b) {
                        //Calls the calc() function and checks for the first calculation
                        result = calculator::calculate(a,op,b);
                } else {
                    break;
                }

                //Simple History - Move this logic part into calculator.cpp
                if(result >=100000000) {
                    std::cout << std::fixed << std::setprecision(1);
                } else {
                    std::cout << std::fixed << std::setprecision(0);
                }
                std::get<0>(historytuple[0]) = a;
                std::get<1>(historytuple[0]) = op;
                std::get<2>(historytuple[0]) = b;
                std::get<3>(historytuple[0]) = result;
                std::cout << "The result is: " << result << std::endl;
                std::cout << "Type 'abort' to exit the calculator" << std::endl;
            }

        } else {
            std::cout << "You may only use simple mathematical expressions (+-*/)" << std::endl;
        }
    }

    return 0;


}