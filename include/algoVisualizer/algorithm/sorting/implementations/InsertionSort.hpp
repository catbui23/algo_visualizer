#pragma once

#include "algoVisualizer/algorithm/sorting/interface/ISortingAlgorithm.hpp"
#include "algoVisualizer/modules/sorting/sortingVisualizer.hpp"
#include <vector>

using namespace std;

class InsertionSort : private ISortingAlgorithm {
public:
    InsertionSort(const vector<unsigned int>& arr, SortingVisualizer& visualizer);
    ~InsertionSort();
    void start();

private:
    vector<unsigned int> mArr;
    SortingVisualizer& mVisualizer;

    void runAlgorithm();
    void end() const;
};
