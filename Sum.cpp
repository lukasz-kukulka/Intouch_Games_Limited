#include "Sum.hpp"

#include "algorithm"
#include <cctype>
#include <iostream>
#include <iterator>
#include <numeric>

Sum::Sum(std::string userInput) 
    : userInput_(userInput)
{
    generateData(userInput_);
    couting();
}

Sum::~Sum() {}

void Sum::validationData() {
     // to do
}

bool Sum::isDelimiter(std::string userInput) {
    if (userInput.size() > 2 && userInput[0] == '/' && userInput[1] == '/') {
        return true;
    }
    return false;
}

void Sum::generateDelimiter(std::string userInput) {
    std::string beforeNumber { };
    if (isDelimiter(userInput) == true) {
        std::copy_if(userInput.begin(), userInput.end(), std::back_inserter(beforeNumber), [](auto ele){ return !std::isdigit(ele); });
    }
}

void Sum::generateData(std::string userInput) {
    generateDelimiter(userInput);
}

void Sum::couting() {
    std::vector<int>dataToCount;
    dataToCount.reserve(dataToCount_.size());
    std::transform(dataToCount_.begin(), dataToCount_.end(), dataToCount.begin(), [](auto ele){ return std::stoi(ele);} );
    checkIfMoreThan1000(dataToCount);
    result_ = std::accumulate(dataToCount.begin(), dataToCount.end(), 0);
}

void Sum::checkIfMoreThan1000(std::vector<int>& checkData) {
    checkData.erase(std::remove_if(checkData.begin(), checkData.end(), [](auto ele){ return ele > 1000; }), checkData.end());
}

