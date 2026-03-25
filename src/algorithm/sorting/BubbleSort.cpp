#include "algoVisualizer/algorithm/sorting/implementations/BubbleSort.hpp"
#include "algoVisualizer/algorithm/sorting/interface/SortStep.hpp"
#include "algoVisualizer/modules/sorting/sortingVisualizer.hpp"
#include <utility>
#include <vector>

using namespace std;

BubbleSort::BubbleSort(const vector<unsigned int>& arr, SortingVisualizer& visualier)
    : mArr(arr)
    , mVisualizer(visualier)
{
}

BubbleSort::~BubbleSort() { }

void BubbleSort::start()
{
    runStep();
};

void BubbleSort::runStep()
{
    int n = mArr.size();
    bool isSwap;
    for (size_t i = 0; i < n - 1; ++i) {
        isSwap = false;
        for (size_t j = 0; j < n - i - 1; ++j) {
            SortStep compareStep = { j, j + 1, StepType::COMPARE };
            mVisualizer.updateSortStep(compareStep);
            if (mArr[j] > mArr[j + 1]) {
                SortStep swapStep = { j, j + 1, StepType::SWAP };
                swap(mArr[j], mArr[j + 1]);
                mVisualizer.updateSortStep(swapStep);
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
