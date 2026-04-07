#include "algoVisualizer/algorithm/sorting/implementations/SelectionSort.hpp"
#include "algoVisualizer/modules/sorting/sortingVisualizer.hpp"
#include <cassert>
#include <utility>
#include <vector>

using namespace std;

SelectionSort::SelectionSort(const vector<unsigned int>& arr, SortingVisualizer& visualier)
    : mArr(arr)
    , mVisualizer(visualier)
{
}

SelectionSort::~SelectionSort()
{
    end();
}

void SelectionSort::start()
{
    runAlgorithm();
    bool isSorted = is_sorted(mArr.begin(), mArr.end());
    assert(isSorted);
}

void SelectionSort::runAlgorithm()
{
    int n = mArr.size();
    for (size_t i = 0; i < n - 1; ++i) {
        size_t min_idx = i;
        for (size_t j = i + 1; j < n; ++j) {
            mVisualizer.compareStep(min_idx, j);
            if (mArr[j] < mArr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(mArr[min_idx], mArr[i]);
            mVisualizer.swapStep(min_idx, i);
        }
    }
}

void SelectionSort::end() const
{
    mVisualizer.printFinalFrame();
}