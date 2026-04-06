#include "algoVisualizer/algorithm/sorting/implementations/ThreeWayMergeSort.hpp"
#include "algoVisualizer/modules/sorting/sortingVisualizer.hpp"
#include <climits>
#include <utility>
#include <vector>

using namespace std;

ThreeWayMergeSort::ThreeWayMergeSort(const vector<unsigned int>& arr, SortingVisualizer& visualier)
    : mArr(arr)
    , mVisualizer(visualier)
{
}

ThreeWayMergeSort::~ThreeWayMergeSort()
{
    end();
}

void ThreeWayMergeSort::start()
{
    runAlgorithm();
};

void ThreeWayMergeSort::runAlgorithm()
{
    threeWayMergeSort(0, mArr.size() - 1);
}

void ThreeWayMergeSort::end() const
{
    mVisualizer.printFinalFrame();
}

void ThreeWayMergeSort::threeWayMergeSort(size_t l, size_t r)
{
    if (l >= r) {
        return;
    }
    size_t m1 = l + (r - l) / 3;
    size_t m2 = l + 2 * (r - l) / 3;
    threeWayMergeSort(l, m1);
    threeWayMergeSort(m1 + 1, m2);
    threeWayMergeSort(m2 + 1, r);
    mergeArr(l, m1, m2, r);
}

void ThreeWayMergeSort::mergeArr(size_t l, size_t m1, size_t m2, size_t r)
{
    int size1 = m1 - l + 1;
    int size2 = m2 - m1;
    int size3 = r - m2;

    vector<unsigned int> leftArr(size1), midArr(size2), rightArr(size3);

    for (size_t i = 0; i < size1; ++i) {
        mVisualizer.accessStep(l + i);
        leftArr[i] = mArr[l + i];
    }
    for (size_t i = 0; i < size2; ++i) {
        mVisualizer.accessStep(m1 + 1 + i);
        midArr[i] = mArr[m1 + 1 + i];
    }
    for (size_t i = 0; i < size3; ++i) {
        mVisualizer.accessStep(m2 + 1 + i);
        rightArr[i] = mArr[m2 + 1 + i];
    }

    size_t i = 0, j = 0, k = 0;
    size_t idx = l;
    while (i < size1 || j < size2 || k < size3) {
        unsigned int minValue = INT_MAX;
        int minIdx = -1;

        if (i < size1 && leftArr[i] < minValue) {
            minIdx = 0;
            minValue = leftArr[i];
        }
        if (j < size2 && midArr[j] < minValue) {
            minIdx = 1;
            minValue = midArr[j];
        }
        if (k < size3 && rightArr[k] < minValue) {
            minValue = rightArr[k];
            minIdx = 2;
        }

        mVisualizer.assignStep(idx, minValue);
        mArr[idx] = minValue;
        if (minIdx == 0) {
            i++;
        } else if (minIdx == 1) {
            j++;
        } else if (minIdx == 2) {
            k++;
        }
        idx++;
    }
}