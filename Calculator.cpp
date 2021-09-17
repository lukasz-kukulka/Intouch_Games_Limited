#include "Calculator.hpp"
#include "Operation.hpp"
#include <iostream>

void Calculator::calculatorInit() {
    auto userChoice { 0 };
    // std::cin userChoice; this will be use if we have more option in calculator
    calcOperation_ = static_cast<Calculator::Calc>(userChoice);
    switch (calcOperation_) {
        case Calc::Add : {
            Add(userInput());
        } break;
        default : {
            // to do
        } break;
    }
    operation_ = nullptr;
}

int Calculator::Add(std::string userInput) {
    operation_ = (std::make_shared<Sum>(userInput));
    return countResult();
}

std::string Calculator::userInput() {
    std::string userInput;
    std::cin >> userInput;
    return userInput;
}

int Calculator::countResult() {

    return operation_->getResult();
}