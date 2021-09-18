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
    std::string delimiter { };
    if (isDelimiter(userInput) == true) {
        auto delimiterEndIt = std::find_if(userInput.begin(), userInput.end(), [](auto ele){ return ele == '\n'; });
        std::copy_if(userInput.begin() + 2, delimiterEndIt, std::back_inserter(delimiter), [](auto ele){ return !std::isdigit(ele) && ele != '\n'; });
    }
    //std::cout << delimiter << "\n";
    if (delimiter[0] == '[') {
        generateMultiDelimiter(delimiter);
    } else {
        delimiter_ = delimiter;
    }
}

void Sum::generateMultiDelimiter(std::string delimiter) {
    delimiter_ = "";
    //std::cout << delimiter << "\n";
    for (size_t i = 0; i < delimiter.size(); i++) {
        if (delimiter[i] == '[') {
            i++;
            delimiter_ += delimiter[i];
        } else if (delimiter[i] == ']') {
            delimiters_.push_back(delimiter_);
            delimiter_ = "";
        } else {
            delimiter_ += delimiter[i];
        }
    }
}

void Sum::generateData(std::string userInput) {
    generateDelimiter(userInput);
    for (auto xxx : delimiters_) {
        std::cout << xxx << "\n";
    }
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

