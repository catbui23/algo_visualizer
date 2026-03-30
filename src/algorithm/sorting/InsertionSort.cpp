#include "algoVisualizer/algorithm/sorting/implementations/InsertionSort.hpp"
#include "algoVisualizer/algorithm/sorting/interface/SortStep.hpp"
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
            SortStep compareStep = { j, j + 1, StepType::COMPARE };
            mVisualizer.updateSortStep(compareStep);
            if (mArr[j] > mArr[j + 1]) {
                SortStep swapStep = { j, j + 1, StepType::SWAP };
                mVisualizer.updateSortStep(swapStep);
                swap(mArr[j], mArr[j + 1]);
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
