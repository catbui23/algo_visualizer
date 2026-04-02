#pragma once

#include "algoVisualizer/algorithm/sorting/interface/ISortingAlgorithm.hpp"
#include "algoVisualizer/modules/sorting/sortingVisualizer.hpp"
#include <vector>

using namespace std;

class IntroSort : private ISortingAlgorithm {
public:
    IntroSort(const vector<unsigned int>& arr, SortingVisualizer& visualizer);
    ~IntroSort();
    void start();

private:
    static const int INSERTION_SORT_THRESHOLD;

    vector<unsigned int> mArr;
    SortingVisualizer& mVisualizer;

    void runAlgorithm();
    void insertionSort(const int left, const int right);
    int medianOfThree(const int a, const int b, const int c) const;
    int partition(const int low, const int high);
    void heapify(const int begin, const int heapSize, const int root);
    void heapSort(const int begin, const int end);
    void introSort(const int begin, const int end, const int depthLimit);
    void end() const;
};
