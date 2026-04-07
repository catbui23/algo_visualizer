#include "algoVisualizer/algorithm/sorting/implementations/RadixSort.hpp"
#include "algoVisualizer/modules/sorting/sortingVisualizer.hpp"
#include <cassert>
#include <utility>
#include <vector>

using namespace std;

RadixSort::RadixSort(const vector<unsigned int>& arr, SortingVisualizer& visualier)
    : mArr(arr)
    , mVisualizer(visualier)
{
}

RadixSort::~RadixSort()
{
    end();
}

void RadixSort::start()
{
    runAlgorithm();
    bool isSorted = is_sorted(mArr.begin(), mArr.end());
    assert(isSorted);
};

void RadixSort::runAlgorithm()
{
    unsigned int maxVal = findMax();

    for (unsigned int exp = 1; maxVal / exp > 0; exp *= 10) {
        countSort(exp);
    }
}

unsigned int RadixSort::findMax() const
{
    unsigned int maxVal = 0;
    for (unsigned int value : mArr) {
        maxVal = max(maxVal, value);
    }

    return maxVal;
}

void RadixSort::countSort(const unsigned int exp)
{
    int n = mArr.size();
    vector<unsigned int> tmpArr(n, 0);
    int cnt[10] = { 0 };
    for (int i = 0; i < n; ++i) {
        mVisualizer.accessStep(i);
        cnt[(mArr[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; ++i) {
        cnt[i] += cnt[i - 1];
    }
    for (int i = n - 1; i >= 0; --i) {
        mVisualizer.accessStep(i);
        tmpArr[cnt[(mArr[i] / exp) % 10] - 1] = mArr[i];
        cnt[(mArr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; ++i) {
        mVisualizer.assignStep(i, tmpArr[i]);
        mArr[i] = tmpArr[i];
    }
}

void RadixSort::end() const
{
    mVisualizer.printFinalFrame();
}
