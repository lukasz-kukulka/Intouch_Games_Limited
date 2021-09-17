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
    void checkDelimiter(std::string userInput); 
    void generateData();
    void couting();
    void checkIfMoreThan1000(std::vector<int>& checkData);
    
private:
    std::string userInput_;
    int result_ { 0 };
    std::string delimiter_ { "," };
    std::vector<std::string>dataToCount_{ };
    bool changeDelimeter { false };
};