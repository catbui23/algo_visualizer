#pragma once

#include "algoVisualizer/core/visualize.hpp"
#include <functional>
#include <string>
#include <vector>

using namespace std;

class SortingVisualizer : public IVisualizer {
public:
    SortingVisualizer(const string name, const vector<unsigned int>& arr);
    ~SortingVisualizer();
    void render() const;
    void printHeader() const;
    void compareStep(const size_t i, const size_t j);
    void swapStep(const size_t i, const size_t j);
    void assignStep(const size_t i, const unsigned int value);
    void printFinalFrame() const;

private:
    string mName;
    unsigned int mCntOp;
    unsigned int mUnit;
    unsigned int mMaxHeight;
    vector<unsigned int> mArr;

    void printFrame(function<void(size_t)> highlightFn) const;
    void printStarterFrame() const;
    void calculateUnit();
    void resetFrame() const;
};
