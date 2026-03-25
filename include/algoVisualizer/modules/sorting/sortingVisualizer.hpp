#pragma once

#include "algoVisualizer/algorithm/sorting/interface/SortStep.hpp"
#include "algoVisualizer/core/visualize.hpp"
#include <string>
#include <vector>

using namespace std;

class SortingVisualizer : public IVisualizer {
public:
    SortingVisualizer(const string name, const vector<unsigned int>& arr);
    ~SortingVisualizer();
    void render() const;
    void printHeader() const;
    void updateSortStep(const SortStep& step);
    void printFinalFrame() const;

private:
    string mName;
    unsigned int mTotalComp;
    unsigned int mTotalSwap;
    unsigned int mUnit;
    unsigned int mMaxHeight;
    vector<unsigned int> mArr;

    void printFrame(const SortStep& step) const;
    void printSortStep(const SortStep& step) const;
    void printStarterFrame() const;
    void calculateUnit();
    void resetFrame() const;
};
