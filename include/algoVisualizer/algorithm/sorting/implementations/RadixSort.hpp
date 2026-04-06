#pragma once

#include "algoVisualizer/algorithm/sorting/interface/ISortingAlgorithm.hpp"
#include "algoVisualizer/modules/sorting/sortingVisualizer.hpp"
#include <vector>

using namespace std;

class RadixSort : public ISortingAlgorithm {
public:
    RadixSort(const vector<unsigned int>& arr, SortingVisualizer& visualizer);
    ~RadixSort();
    void start();

private:
    vector<unsigned int> mArr;
    SortingVisualizer& mVisualizer;

    void runAlgorithm();
    unsigned int findMax() const;
    void countSort(const unsigned int n);
    void end() const;
};
