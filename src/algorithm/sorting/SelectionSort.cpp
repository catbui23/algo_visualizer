#include "algoVisualizer/algorithm/sorting/implementations/SelectionSort.hpp"
#include "algoVisualizer/algorithm/sorting/interface/SortStep.hpp"
#include "algoVisualizer/modules/sorting/sortingVisualizer.hpp"
#include <utility>
#include <vector>

using namespace std;

SelectionSort::SelectionSort(const vector<unsigned int> &arr, SortingVisualizer &visualier) : mArr(arr), mVisualizer(visualier) {}

SelectionSort::~SelectionSort()
{
}

void SelectionSort::start()
{
    runStep();
}

void SelectionSort::runStep()
{
    int n = mArr.size();
    for (size_t i = 0; i < n - 1; ++i)
    {
        size_t min_idx = i;
        for (size_t j = i + 1; j < n; ++j)
        {
            SortStep compareStep = {min_idx, j, StepType::COMPARE};
            mVisualizer.updateSortStep(compareStep);
            if (mArr[j] < mArr[min_idx])
            {
                min_idx = j;
            }
        }
        if (min_idx != i)
        {
            SortStep swapStep = {i, min_idx, StepType::SWAP};
            mVisualizer.updateSortStep(swapStep);
            swap(mArr[min_idx], mArr[i]);
        }
    }
}

void SelectionSort::end() const
{
    mVisualizer.printFinalFrame();
}