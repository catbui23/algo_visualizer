#include "algoVisualizer/algorithm/sorting/implementations/BubbleSort.hpp"
#include "algoVisualizer/modules/sorting/sortingVisualizer.hpp"
#include <utility>
#include <vector>

using namespace std;

BubbleSort::BubbleSort(const vector<unsigned int>& arr, SortingVisualizer& visualier)
    : mArr(arr)
    , mVisualizer(visualier)
{
}

BubbleSort::~BubbleSort()
{
    end();
}

void BubbleSort::start()
{
    runAlgorithm();
};

void BubbleSort::runAlgorithm()
{
    int n = mArr.size();
    bool isSwap;
    for (size_t i = 0; i < n - 1; ++i) {
        isSwap = false;
        for (size_t j = 0; j < n - i - 1; ++j) {
            mVisualizer.compareStep(j, j + 1);
            if (mArr[j] > mArr[j + 1]) {
                swap(mArr[j], mArr[j + 1]);
                mVisualizer.swapStep(j, j + 1);
                isSwap = true;
            }
        }
        if (!isSwap) {
            break;
        }
    }
}

void BubbleSort::end() const
{
    mVisualizer.printFinalFrame();
}
