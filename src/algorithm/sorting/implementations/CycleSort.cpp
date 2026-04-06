#include "algoVisualizer/algorithm/sorting/implementations/CycleSort.hpp"
#include "algoVisualizer/modules/sorting/sortingVisualizer.hpp"
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

CycleSort::CycleSort(const vector<unsigned int>& arr, SortingVisualizer& visualier)
    : mArr(arr)
    , mVisualizer(visualier)
{
}

CycleSort::~CycleSort()
{
    end();
}

void CycleSort::start()
{
    runAlgorithm();
};

void CycleSort::runAlgorithm()
{
    size_t n = mArr.size();
    for (size_t start = 0; start < n - 1; ++start) {
        unsigned int item = mArr[start];
        size_t pos = findPosition(start, item);

        if (pos == start) {
            continue;
        }

        pos = skipDuplicates(pos, item);
        if (pos >= n) {
            continue;
        }

        if (pos != start) {
            mVisualizer.assignStep(pos, item);
            swap(item, mArr[pos]);
        }

        while (pos != start) {
            pos = skipDuplicates(findPosition(start, item), item);

            if (pos >= n) {
                continue;
            }

            if (item != mArr[pos]) {
                mVisualizer.assignStep(pos, item);
                swap(item, mArr[pos]);
            }
        }
    }
}

size_t CycleSort::findPosition(const size_t start, const unsigned int item) const
{
    size_t n = mArr.size();
    size_t pos = start;
    for (size_t i = start + 1; i < n; ++i) {
        mVisualizer.accessStep(i);
        if (mArr[i] < item) {
            pos++;
        }
    }
    return pos;
}

size_t CycleSort::skipDuplicates(const size_t start, const unsigned int item) const
{
    size_t pos = start;
    size_t n = mArr.size();
    while (pos < n) {
        mVisualizer.accessStep(pos);
        if (item == mArr[pos]) {
            pos++;
        } else {
            break;
        }
    }
    return pos;
}

void CycleSort::end() const
{
    mVisualizer.printFinalFrame();
}
