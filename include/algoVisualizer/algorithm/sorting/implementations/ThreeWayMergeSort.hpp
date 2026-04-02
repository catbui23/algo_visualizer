#pragma once

#include "algoVisualizer/algorithm/sorting/interface/ISortingAlgorithm.hpp"
#include "algoVisualizer/modules/sorting/sortingVisualizer.hpp"
#include <vector>

using namespace std;

class ThreeWayMergeSort : private ISortingAlgorithm {
public:
    ThreeWayMergeSort(const vector<unsigned int>& arr, SortingVisualizer& visualizer);
    ~ThreeWayMergeSort();
    void start();

private:
    vector<unsigned int> mArr;
    SortingVisualizer& mVisualizer;

    void runAlgorithm();
    void end() const;
    void threeWayMergeSort(size_t l, size_t r);
    void mergeArr(size_t start, size_t m1, size_t m2, size_t end);
};
