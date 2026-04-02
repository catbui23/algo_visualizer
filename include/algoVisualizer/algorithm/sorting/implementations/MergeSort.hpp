#pragma once

#include "algoVisualizer/algorithm/sorting/interface/ISortingAlgorithm.hpp"
#include "algoVisualizer/modules/sorting/sortingVisualizer.hpp"
#include <vector>

using namespace std;

class MergeSort : private ISortingAlgorithm {
public:
    MergeSort(const vector<unsigned int>& arr, SortingVisualizer& visualizer);
    ~MergeSort();
    void start();

private:
    vector<unsigned int> mArr;
    SortingVisualizer& mVisualizer;

    void runAlgorithm();
    void end() const;
    void mergeSort(size_t l, size_t r);
    void mergeArr(size_t start, size_t mid, size_t end);
};
