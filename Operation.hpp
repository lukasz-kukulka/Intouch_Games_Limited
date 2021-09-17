#pragma once
#include <string>

class Operation {
public:
    virtual ~Operation() = default;
    virtual int getResult() const = 0;
private:

};