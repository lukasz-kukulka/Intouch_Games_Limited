#pragma once
#include "Sum.hpp"

#include <memory>
#include <string>

class Calculator {
public:
    void calculatorInit();
    int Add(std::string userInput);
    std::string userInput();
    int countResult();

    enum class Calc {
        Add
    };
private:
    std::shared_ptr<Operation>operation_ { nullptr };
    Calc calcOperation_;

};