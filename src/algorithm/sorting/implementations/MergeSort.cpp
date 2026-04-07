#include "algoVisualizer/algorithm/sorting/implementations/MergeSort.hpp"
#include "algoVisualizer/modules/sorting/sortingVisualizer.hpp"
#include <cassert>
#include <utility>
#include <vector>

using namespace std;

MergeSort::MergeSort(const vector<unsigned int>& arr, SortingVisualizer& visualier)
    : mArr(arr)
    , mVisualizer(visualier)
{
}

MergeSort::~MergeSort()
{
    end();
}

void MergeSort::start()
{
    runAlgorithm();
    bool isSorted = is_sorted(mArr.begin(), mArr.end());
    assert(isSorted);
};

void MergeSort::runAlgorithm()
{
    mergeSort(0, mArr.size() - 1);
}

void MergeSort::end() const
{
    mVisualizer.printFinalFrame();
}

void MergeSort::mergeSort(size_t l, size_t r)
{
    if (l >= r) {
        return;
    }
    size_t m = l + (r - l) / 2;
    mergeSort(l, m);
    mergeSort(m + 1, r);
    mergeArr(l, m, r);
}

void MergeSort::mergeArr(size_t l, size_t m, size_t r)
{
    int size1 = m - l + 1;
    int size2 = r - m;

    vector<unsigned int> leftArr(size1), rightArr(size2);

    for (size_t i = 0; i < size1; ++i) {
        mVisualizer.accessStep(l + i);
        leftArr[i] = mArr[l + i];
    }
    for (size_t i = 0; i < size2; ++i) {
        mVisualizer.accessStep(m + 1 + i);
        rightArr[i] = mArr[m + 1 + i];
    }

    size_t i = 0, j = 0;
    size_t k = l;
    while (i < size1 && j < size2) {
        if (leftArr[i] <= rightArr[j]) {
            mVisualizer.assignStep(k, leftArr[i]);
            mArr[k] = leftArr[i];
            i++;
        } else {
            mVisualizer.assignStep(k, rightArr[j]);
            mArr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < size1) {
        mVisualizer.assignStep(k, leftArr[i]);
        mArr[k] = leftArr[i];
        k++;
        i++;
    }

    while (j < size2) {
        mVisualizer.assignStep(k, rightArr[j]);
        mArr[k] = rightArr[j];
        k++;
        j++;
    }
}