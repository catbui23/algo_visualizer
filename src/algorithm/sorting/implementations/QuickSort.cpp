#include "algoVisualizer/algorithm/sorting/implementations/QuickSort.hpp"
#include "algoVisualizer/modules/sorting/sortingVisualizer.hpp"
#include <utility>
#include <vector>

using namespace std;

QuickSort::QuickSort(const vector<unsigned int>& arr, SortingVisualizer& visualier)
    : mArr(arr)
    , mVisualizer(visualier)
{
}

QuickSort::~QuickSort()
{
    end();
}

void QuickSort::start()
{
    runAlgorithm();
};

void QuickSort::runAlgorithm()
{
    quickSort(0, mArr.size() - 1);
}

void QuickSort::quickSort(int l, int r)
{
    if (l >= r) {
        return;
    }
    int pi = partition(l, r);
    quickSort(l, pi - 1);
    quickSort(pi + 1, r);
}

int QuickSort::partition(int l, int r)
{
    unsigned int pivot = mArr[r];
    int i = l - 1;

    for (int j = l; j <= r - 1; ++j) {
        mVisualizer.accessStep(j);
        if (mArr[j] < pivot) {
            i++;
            mVisualizer.swapStep(i, j);
            swap(mArr[i], mArr[j]);
        }
    }
    mVisualizer.swapStep(i + 1, r);
    swap(mArr[i + 1], mArr[r]);
    return i + 1;
}

void QuickSort::end() const
{
    mVisualizer.printFinalFrame();
}