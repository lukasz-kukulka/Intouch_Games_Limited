#include "Sum.hpp"

#include "algorithm"
#include <cctype>
#include <iterator>
#include <numeric>

Sum::Sum(std::string userInput) 
    : userInput_(userInput)
{
    checkDelimiter(userInput_);
}

Sum::~Sum() {}

void Sum::validationData() {
     // to do
}

void Sum::checkDelimiter(std::string userInput) {
    if (userInput[0] && userInput[1] == '/') {
        delimiter_ = userInput_[2];
        for (int i = 3; !std::isdigit(userInput_[i]); i++) {
            if (i > 3 && userInput_[i] != userInput_[i - 1]) {
                delimiters_.push_back(delimiter_);
                delimiter_ = "";
            }
            delimiter_ += userInput_[i];
            changeDelimeter = true;
        }
    }
}

void Sum::generateData() {
    std::string number { };
    size_t delimeterSize { 0 };
    if (changeDelimeter == true) {
        for (const auto & count : delimiters_) {
            delimeterSize += count.size();
        }
    }
    for(size_t i = delimeterSize ; i < userInput_.size(); i++) {
        if(userInput_[i] == delimiter_[0]) {
            i += delimeterSize;
            dataToCount_.push_back(std::to_string(userInput_[i]));
        } else {
            dataToCount_[dataToCount_.size() - 1] += std::to_string(userInput_[i]);
        }
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

