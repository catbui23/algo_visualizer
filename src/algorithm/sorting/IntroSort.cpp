#include "algoVisualizer/algorithm/sorting/implementations/IntroSort.hpp"
#include "algoVisualizer/modules/sorting/sortingVisualizer.hpp"
#include <cmath>
#include <utility>
#include <vector>

using namespace std;

const int IntroSort::INSERTION_SORT_THRESHOLD = 16;

IntroSort::IntroSort(const vector<unsigned int>& arr, SortingVisualizer& visualier)
    : mArr(arr)
    , mVisualizer(visualier)
{
}

IntroSort::~IntroSort() { }

void IntroSort::start()
{
    runStep();
};

void IntroSort::runStep()
{
    if (mArr.empty()) {
        return;
    }
    int depthLimit = 2 * log2(mArr.size());
    introSort(0, mArr.size() - 1, depthLimit);
}

void IntroSort::insertionSort(const int left, const int right)
{
    for (int i = left + 1; i <= right; i++) {
        unsigned int key = mArr[i];
        int j = i - 1;

        while (j >= left) {
            mVisualizer.accessStep(j);
            if (mArr[j] > key) {
                mVisualizer.assignStep(j + 1, mArr[j]);
                mArr[j + 1] = mArr[j];
                j--;
            } else {
                break;
            }
        }
        mVisualizer.assignStep(j + 1, key);
        mArr[j + 1] = key;
    }
}

int IntroSort::medianOfThree(const int a, const int b, const int c) const
{
    mVisualizer.compareStep(a, b);
    if (mArr[a] < mArr[b]) {
        mVisualizer.compareStep(b, c);
        if (mArr[b] < mArr[c]) {
            return b;
        } else {
            mVisualizer.compareStep(a, c);
            if (mArr[a] < mArr[c]) {
                return c;
            } else {
                return a;
            }
        }
    } else {
        mVisualizer.compareStep(a, c);
        if (mArr[a] < mArr[c]) {
            return a;
        } else {
            mVisualizer.compareStep(b, c);
            if (mArr[b] < mArr[c]) {
                return c;
            } else {
                return b;
            }
        }
    }
}

int IntroSort::partition(const int low, const int high)
{
    unsigned int pivot = mArr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        mVisualizer.accessStep(j);
        if (mArr[j] <= pivot) {
            i++;
            mVisualizer.swapStep(i, j);
            swap(mArr[i], mArr[j]);
        }
    }
    mVisualizer.swapStep(i + 1, high);
    swap(mArr[i + 1], mArr[high]);
    return i + 1;
}

void IntroSort::heapSort(const int begin, const int end)
{
    make_heap(mArr.begin() + begin, mArr.begin() + end + 1);
    sort_heap(mArr.begin() + begin, mArr.begin() + end + 1);
}

void IntroSort::introSort(const int begin, const int end, const int depthLimit)
{
    int size = end - begin + 1;

    // Use insertion sort for small arrays
    if (size < INSERTION_SORT_THRESHOLD) {
        insertionSort(begin, end);
        return;
    }

    // Switch to heap sort if recursion depth limit exceeded
    if (depthLimit == 0) {
        heapSort(begin, end);
        return;
    }

    // Median-of-three pivot selection
    int mid = begin + size / 2;
    int pivotIndex = medianOfThree(begin, mid, end);
    mVisualizer.swapStep(pivotIndex, end);
    swap(mArr[pivotIndex], mArr[end]);

    int p = partition(begin, end);

    introSort(begin, p - 1, depthLimit - 1);
    introSort(p + 1, end, depthLimit - 1);
}

void IntroSort::end() const
{
    mVisualizer.printFinalFrame();
}
