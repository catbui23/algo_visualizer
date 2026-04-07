#include "algoVisualizer/modules/sorting/sortingVisualizer.hpp"
#include "algoVisualizer/utils/constants.hpp"
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <pthread.h>
#include <string>
#include <string_view>
#include <thread>
#include <utility>
#include <vector>

#define MIN_HEIGHT 10.0

using namespace std;

constexpr string_view COLUMN_CELL = u8"\u2588";

SortingVisualizer::SortingVisualizer(const string name,
    const vector<unsigned int>& arr)
    : mName(name)
    , mCntOp(0)
    , mArr(arr)
{
    calculateUnit();
    printStarterFrame();
}

void SortingVisualizer::render() const { }

void SortingVisualizer::printHeader() const
{
    cout << "Algorithm: " << mName << "\nNumber of Operations: " << mCntOp << "\n";
}

void SortingVisualizer::compareStep(const size_t i, const size_t j)
{
    mCntOp++;
    printFrame([&](size_t idx) {
        if (idx == i || idx == j) {
            cout << ANSI_COLOR::YELLOW;
        } else {
            cout << ANSI_COLOR::RESET;
        }
    });
}

void SortingVisualizer::swapStep(const size_t i, const size_t j)
{
    mCntOp++;
    swap(mArr[i], mArr[j]);
    printFrame([&](size_t idx) {
        if (idx == i || idx == j) {
            cout << ANSI_COLOR::RED;
        } else {
            cout << ANSI_COLOR::RESET;
        }
    });
}

void SortingVisualizer::assignStep(const size_t i, const unsigned int value)
{
    mCntOp++;
    mArr[i] = value;
    printFrame([&](size_t idx) {
        if (idx == i) {
            cout << ANSI_COLOR::RED;
        } else {
            cout << ANSI_COLOR::RESET;
        }
    });
}

void SortingVisualizer::accessStep(const size_t i)
{
    mCntOp++;
    printFrame([&](size_t idx) {
        if (idx == i) {
            cout << ANSI_COLOR::YELLOW;
        } else {
            cout << ANSI_COLOR::RESET;
        }
    });
}

void SortingVisualizer::printFinalFrame() const
{
    resetFrame();
    printHeader();
    for (int t = 0; t < mArr.size(); ++t) {
        for (unsigned int line = 1; line <= mMaxHeight; ++line) {
            for (size_t i = 0; i < mArr.size(); ++i) {
                unsigned int n = mArr[i];
                n /= mUnit;
                if (line + n > mMaxHeight) {
                    if (i <= t) {
                        cout << ANSI_COLOR::GREEN;
                    } else {
                        cout << ANSI_COLOR::RESET;
                    }
                    cout << COLUMN_CELL;
                } else {
                    cout << " ";
                }
            }
            cout << "\n"
                 << ANSI_COLOR::RESET;
        }
        // reset cursor to the top of the array section
        if (t < mArr.size() - 1) {
            cout << "\033[" << to_string(mMaxHeight) << "A\033[1G";
            this_thread::sleep_for(REFRESH_TIME);
        }
    }
}

void SortingVisualizer::printFrame(function<void(size_t)> highlightFn) const
{
    resetFrame();
    printHeader();
    for (unsigned int line = 1; line <= mMaxHeight; ++line) {
        for (size_t idx = 0; idx < mArr.size(); ++idx) {
            unsigned int n = mArr[idx];
            n /= mUnit;
            if (line + n > mMaxHeight) {
                highlightFn(idx);
                cout << COLUMN_CELL;
            } else {
                cout << " ";
            }
        }
        cout << "\n"
             << ANSI_COLOR::RESET;
    }
    this_thread::sleep_for(REFRESH_TIME);
}

void SortingVisualizer::printStarterFrame() const
{
    printHeader();
    for (unsigned int line = 1; line <= mMaxHeight; ++line) {
        for (auto n : mArr) {
            n /= mUnit;
            if (line + n > mMaxHeight) {
                cout << COLUMN_CELL;
            } else {
                cout << " ";
            }
        }
        cout << "\n";
    }
}

void SortingVisualizer::calculateUnit()
{
    auto maxElement = max_element(mArr.begin(), mArr.end());
    mMaxHeight = *maxElement;
    mUnit = mArr[0];
    for (size_t i = 0; i < mArr.size(); ++i) {
        mUnit = gcd(mUnit, mArr[i]);
        if (mUnit <= 1) {
            return;
        }
    }
    if (mMaxHeight / mUnit < MIN_HEIGHT) {
        mUnit /= ceil(MIN_HEIGHT / ((float)mMaxHeight / (float)mUnit));
    }
    mMaxHeight /= mUnit;
}

void SortingVisualizer::resetFrame() const
{
    cout << "\033[" << to_string(mMaxHeight + 2) << "A\033[1G";
}
