//
// This software is licensed under the GNU General Public License.
// Created by Krankfried.
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
    void setHistory(const std::tuple<double, char, double, double>& history) {
        calc_history = history;
    }
    [[nodiscard]] std::array<std::string, 9> greetUser() const {
    return messages;
 }
    static double calculate(double r1, char op, double r2) {
        return ::calc(r1, op, r2);
    }
};


#endif //CALCULATOR_H

