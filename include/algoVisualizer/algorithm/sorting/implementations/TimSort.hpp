#pragma once

#include "algoVisualizer/algorithm/sorting/interface/ISortingAlgorithm.hpp"
#include "algoVisualizer/modules/sorting/sortingVisualizer.hpp"
#include <vector>

using namespace std;

class TimSort : public ISortingAlgorithm {
public:
    TimSort(const vector<unsigned int>& arr, SortingVisualizer& visualizer);
    ~TimSort();
    void start();

private:
    static const unsigned int MIN_RUN;
    vector<unsigned int> mArr;
    SortingVisualizer& mVisualizer;

    void runAlgorithm();
    unsigned int calculateMinRun() const;
    void insertionSort(const size_t left, const size_t right);
    void merge(const size_t left, const size_t mid, const size_t right);
    size_t findRun(size_t start);
    void reverseSection(const size_t begin, const size_t end);
    void end() const;
};
