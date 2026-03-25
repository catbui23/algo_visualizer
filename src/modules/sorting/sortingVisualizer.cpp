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
    , mTotalComp(0)
    , mTotalSwap(0)
    , mArr(arr)
{
    calculateUnit();
    printStarterFrame();
}

SortingVisualizer::~SortingVisualizer()
{
    // move to the end of frame
    printFinalFrame();
}

void SortingVisualizer::render() const { }

void SortingVisualizer::updateSortStep(const SortStep& step)
{
    if (step.type == StepType::SWAP) {
        mTotalSwap++;
        swap(mArr[step.i], mArr[step.j]);
    } else {
        mTotalComp++;
    }
    printFrame(step);
    this_thread::sleep_for(REFRESH_TIME);
}

void SortingVisualizer::printHeader() const
{
    cout << "Algorithm: " << mName << "\nCompare: " << mTotalComp
         << "\nSwap: " << mTotalSwap << "\n";
}

void SortingVisualizer::printFrame(const SortStep& step) const
{
    printHeader();
    printSortStep(step);
    resetFrame();
}

void SortingVisualizer::printFinalFrame() const
{
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

void SortingVisualizer::printSortStep(const SortStep& step) const
{
    // move cursor to the starting point (compare line)
    string stepColor = (step.type == StepType::COMPARE) ? string(ANSI_COLOR::YELLOW) : string(ANSI_COLOR::RED);
    for (unsigned int line = 1; line <= mMaxHeight; ++line) {
        for (size_t i = 0; i < mArr.size(); ++i) {
            unsigned int n = mArr[i];
            n /= mUnit;
            if (line + n > mMaxHeight) {
                if (i == step.i || i == step.j) {
                    cout << stepColor;
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
    resetFrame();
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
    cout << "\033[" << to_string(mMaxHeight + 3) << "A\0331G";
}
