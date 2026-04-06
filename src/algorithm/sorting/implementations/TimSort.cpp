#include "algoVisualizer/algorithm/sorting/implementations/TimSort.hpp"
#include "algoVisualizer/modules/sorting/sortingVisualizer.hpp"
#include <utility>
#include <vector>

using namespace std;

const unsigned int TimSort::MIN_RUN = 16;

TimSort::TimSort(const vector<unsigned int>& arr, SortingVisualizer& visualier)
    : mArr(arr)
    , mVisualizer(visualier)
{
}

TimSort::~TimSort()
{
    end();
}

void TimSort::start()
{
    runAlgorithm();
};

void TimSort::runAlgorithm()
{
    size_t n = mArr.size();
    unsigned int minRun = calculateMinRun();
    vector<pair<unsigned int, unsigned int>> runs;
    size_t i = 0;
    while (i < n) {
        unsigned int runEnd = findRun(i);
        unsigned int runLength = runEnd - i;

        if (runLength < minRun) {
            size_t end = min(i + minRun, n);
            insertionSort(i, end - 1);
            runEnd = end;
        }

        runs.push_back({ i, runEnd });
        i = runEnd;

        while (runs.size() > 1) {
            unsigned int l1 = runs[runs.size() - 2].first;
            unsigned int r1 = runs[runs.size() - 2].second;
            unsigned int l2 = runs[runs.size() - 1].first;
            unsigned int r2 = runs[runs.size() - 1].second;

            unsigned int len1 = r1 - l1;
            unsigned int len2 = r2 - l2;
            if (len1 <= len2) {
                merge(l1, r1 - 1, r2 - 1);
                runs.pop_back();
                runs[runs.size() - 1] = { l1, r2 };
            } else {
                break;
            }
        }
    }

    while (runs.size() > 1) {
        unsigned int l1 = runs[runs.size() - 2].first;
        unsigned int r1 = runs[runs.size() - 2].second;
        unsigned int l2 = runs[runs.size() - 1].first;
        unsigned int r2 = runs[runs.size() - 1].second;
        merge(l1, r1 - 1, r2 - 1);
        runs.pop_back();
        runs[runs.size() - 1] = { l1, r2 };
    }
}

unsigned int TimSort::calculateMinRun() const
{
    int r = 0;
    int n = mArr.size();
    while (n >= MIN_RUN) {
        r |= (n & 1);
        n >>= 1;
    }
    return n + r;
}

void TimSort::insertionSort(const size_t left, const size_t right)
{
    for (size_t i = left + 1; i <= right; ++i) {
        unsigned int key = mArr[i];
        size_t j = i - 1;
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

void TimSort::merge(const size_t left, const size_t mid, const size_t right)
{
    vector<unsigned int> leftArr(mArr.begin() + left, mArr.begin() + mid + 1);
    vector<unsigned int> rightArr(mArr.begin() + mid + 1, mArr.begin() + right + 1);

    unsigned int leftSize = leftArr.size();
    unsigned int rightSize = rightArr.size();

    size_t i = 0, j = 0;
    size_t k = left;

    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) {
            mVisualizer.assignStep(k, leftArr[i]);
            mArr[k++] = leftArr[i++];
        } else {
            mVisualizer.assignStep(k, rightArr[j]);
            mArr[k++] = rightArr[j++];
        }
    }
    while (i < leftSize) {
        mVisualizer.assignStep(k, leftArr[i]);
        mArr[k++] = leftArr[i++];
    }
    while (j < rightSize) {
        mVisualizer.assignStep(k, rightArr[j]);
        mArr[k++] = rightArr[j++];
    }
}

size_t TimSort::findRun(size_t start)
{
    size_t end = start + 1;
    size_t n = mArr.size();
    if (end == n) {
        return end;
    }
    if (mArr[end] < mArr[start]) {
        while (end < n) {
            mVisualizer.compareStep(end, end - 1);
            if (mArr[end] < mArr[end - 1]) {
                end++;
            } else {
                break;
            }
        }
        reverseSection(start, end);
    } else {
        while (end < n) {
            mVisualizer.compareStep(end, end - 1);
            if (mArr[end] >= mArr[end - 1]) {
                end++;
            }
            break;
        }
    }

    return end;
}

void TimSort::reverseSection(const size_t begin, const size_t end)
{
    for (size_t i = begin; i < begin + (end - begin) / 2; ++i) {
        size_t j = end - i + begin;
        mVisualizer.swapStep(i, j);
        swap(mArr[i], mArr[j]);
    }
}

void TimSort::end() const
{
    mVisualizer.printFinalFrame();
}
