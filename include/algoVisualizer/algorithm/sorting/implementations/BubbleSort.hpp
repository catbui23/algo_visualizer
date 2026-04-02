#pragma once

#include "algoVisualizer/algorithm/sorting/interface/ISortingAlgorithm.hpp"
#include "algoVisualizer/modules/sorting/sortingVisualizer.hpp"
#include <vector>

using namespace std;

class BubbleSort : private ISortingAlgorithm {
public:
    BubbleSort(const vector<unsigned int>& arr, SortingVisualizer& visualizer);
    ~BubbleSort();
    void start();

private:
    vector<unsigned int> mArr;
    SortingVisualizer& mVisualizer;

    void runAlgorithm();
    void end() const;
};
