#pragma once

#include "algoVisualizer/algorithm/sorting/interface/ISortingAlgorithm.hpp"
#include "algoVisualizer/modules/sorting/sortingVisualizer.hpp"
#include <vector>

using namespace std;

class QuickSort : private ISortingAlgorithm {
public:
    QuickSort(const vector<unsigned int>& arr, SortingVisualizer& visualizer);
    ~QuickSort();
    void start();

private:
    vector<unsigned int> mArr;
    SortingVisualizer& mVisualizer;

    void runAlgorithm();
    void quickSort(int l, int r);
    int partition(int l, int r);
    void end() const;
};