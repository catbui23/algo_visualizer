#pragma once

#include "algoVisualizer/algorithm/sorting/interface/ISortingAlgorithm.hpp"
#include "algoVisualizer/modules/sorting/sortingVisualizer.hpp"
#include <vector>

using namespace std;

class CycleSort : public ISortingAlgorithm {
public:
    CycleSort(const vector<unsigned int>& arr, SortingVisualizer& visualizer);
    ~CycleSort();
    void start();

private:
    vector<unsigned int> mArr;
    SortingVisualizer& mVisualizer;

    void runAlgorithm();
    size_t findPosition(const size_t start, const unsigned int item) const;
    size_t skipDuplicates(const size_t start, const unsigned int item) const;
    void end() const;
};
