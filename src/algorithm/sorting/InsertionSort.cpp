#include "algoVisualizer/algorithm/sorting/implementations/InsertionSort.hpp"
#include "algoVisualizer/modules/sorting/sortingVisualizer.hpp"
#include <utility>
#include <vector>

using namespace std;

InsertionSort::InsertionSort(const vector<unsigned int>& arr, SortingVisualizer& visualier)
    : mArr(arr)
    , mVisualizer(visualier)
{
}

InsertionSort::~InsertionSort() { }

void InsertionSort::start()
{
    runStep();
};

void InsertionSort::runStep()
{
    int n = mArr.size();
    for (size_t i = 1; i < n; ++i) {
        size_t j = i - 1;
        do {
            mVisualizer.compareStep(j, j + 1);
            if (mArr[j] > mArr[j + 1]) {
                swap(mArr[j], mArr[j + 1]);
                mVisualizer.swapStep(j, j + 1);
            } else {
                break;
            }
            j--;
        } while (j >= 0);
    }
}

void InsertionSort::end() const
{
    mVisualizer.printFinalFrame();
}
