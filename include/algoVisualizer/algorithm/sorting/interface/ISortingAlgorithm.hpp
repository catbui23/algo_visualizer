#pragma once

#include "IAlgorithm.hpp"

using namespace std;

class ISortingAlgorithm : public IAlgorithm {
public:
    virtual void start() = 0;

private:
    virtual void runStep() = 0;
    virtual void end() const = 0;
};
