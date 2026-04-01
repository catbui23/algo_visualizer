#include "algoVisualizer/algorithm/sorting/implementations/HeapSort.hpp"
#include "algoVisualizer/modules/sorting/sortingVisualizer.hpp"
#include <utility>
#include <vector>

using namespace std;

HeapSort::HeapSort(const vector<unsigned int>& arr, SortingVisualizer& visualier)
    : mArr(arr)
    , mVisualizer(visualier)
{
}

HeapSort::~HeapSort() { }

void HeapSort::start()
{
    runStep();
};

void HeapSort::runStep()
{
    int n = mArr.size();
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(n, i);
    }
    for (int i = n - 1; i > 0; --i) {
        swap(mArr[0], mArr[i]);
        mVisualizer.swapStep(0, i);
        heapify(i, 0);
    }
}

void HeapSort::heapify(size_t n, size_t i)
{
    int largest = i;
    int l = i * 2 + 1;
    int r = i * 2 + 2;

    if (l < n) {
        mVisualizer.compareStep(l, largest);
        if (mArr[l] > mArr[largest]) {
            largest = l;
        }
    }

    if (r < n) {
        mVisualizer.compareStep(r, largest);
        if (mArr[r] > mArr[largest]) {
            largest = r;
        }
    }

    if (largest != i) {
        swap(mArr[i], mArr[largest]);
        mVisualizer.swapStep(i, largest);
        heapify(n, largest);
    }
}

void HeapSort::end() const
{
    mVisualizer.printFinalFrame();
}