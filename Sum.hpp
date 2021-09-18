#pragma once

#include <string>
#include <vector>

#include "Operation.hpp"

class Sum : public Operation {
public:
    Sum(std::string userInput);
    ~Sum() override;
    int getResult() const override { return result_; }
    void validationData(); 
    bool isDelimiter(std::string userInput);
    void generateDelimiter(std::string userInput); 
    void generateMultiDelimiter(std::string delimiter);
    void generateNumbers(std::string userInput);
    void generateData(std::string userInput);
    void couting();
    void checkIfMoreThan1000(std::vector<int>& checkData);
    
private:
    std::string userInput_;
    int result_ { 0 };
    std::string delimiter_ { "," };
    std::vector<std::string>delimiters_;
    std::vector<std::string>numbersToCount_{ };
    std::string::iterator delimiterEndIt_ { };
    bool isDelimiter_ { false };
};