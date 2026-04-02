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
    runAlgorithm();
};

void IntroSort::runAlgorithm()
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

int IntroSort::medianOfThree(int a, int b, int c) const
{
    mVisualizer.compareStep(a, b);

    if (mArr[a] < mArr[b]) {
        mVisualizer.compareStep(b, c);
        if (mArr[b] < mArr[c])
            return b;

        mVisualizer.compareStep(a, c);
        return (mArr[a] < mArr[c]) ? c : a;
    }

    mVisualizer.compareStep(a, c);
    if (mArr[a] < mArr[c])
        return a;

    mVisualizer.compareStep(b, c);
    return (mArr[b] < mArr[c]) ? c : b;
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

void IntroSort::heapify(const int begin, const int heapSize, const int root)
{
    int largest = root;
    int left = 2 * (root - begin) + 1 + begin;
    int right = 2 * (root - begin) + 2 + begin;

    if (left < begin + heapSize) {
        mVisualizer.compareStep(left, largest);
        if (mArr[left] > mArr[largest]) {
            largest = left;
        }
    }

    if (right < begin + heapSize) {
        mVisualizer.compareStep(right, largest);
        if (mArr[right] > mArr[largest]) {
            largest = right;
        }
    }

    if (largest != root) {
        mVisualizer.swapStep(root, largest);
        swap(mArr[root], mArr[largest]);

        heapify(begin, heapSize, largest);
    }
}

void IntroSort::heapSort(const int begin, const int end)
{
    int n = end - begin + 1;

    for (int i = begin + n / 2 - 1; i >= begin; i--) {
        heapify(begin, n, i);
    }

    for (int i = end; i > begin; i--) {
        mVisualizer.swapStep(begin, i);
        swap(mArr[begin], mArr[i]);

        heapify(begin, i - begin, begin);
    }
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
