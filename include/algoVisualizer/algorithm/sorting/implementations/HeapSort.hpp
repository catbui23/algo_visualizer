#pragma once

#include "algoVisualizer/algorithm/sorting/interface/ISortingAlgorithm.hpp"
#include "algoVisualizer/modules/sorting/sortingVisualizer.hpp"
#include <vector>

using namespace std;

class HeapSort : private ISortingAlgorithm {
public:
    HeapSort(const vector<unsigned int>& arr, SortingVisualizer& visualizer);
    ~HeapSort();
    void start();

private:
    vector<unsigned int> mArr;
    SortingVisualizer& mVisualizer;

    void runStep();
    void heapify(size_t n, size_t i);
    void end() const;
};