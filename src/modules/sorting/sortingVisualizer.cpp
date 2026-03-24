#include "algoVisualizer/modules/sorting/sortingVisualizer.hpp"
#include "algoVisualizer/utils/constants.hpp"
#include <algorithm>
#include <array>
#include <chrono>
#include <cinttypes>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <iterator>
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
                                     const vector<unsigned int> &arr)
    : mName(name), mTotalComp(0), mTotalSwap(0) {
  calculateUnit(arr);
  // cerr << "Unit: " << mUnit << " mMaxHeight: " << mMaxHeight << "\n";
  printStarterFrame(arr);
}

SortingVisualizer::~SortingVisualizer() {
  // move to the end of frame
  printFinalFrame();
}

void SortingVisualizer::render() const {}

void SortingVisualizer::updateSortStep(const vector<unsigned int> &arr,
                                       const size_t i, const size_t j,
                                       const StepType type) {
  mNewestSortStep.arr = move(arr);
  mNewestSortStep.i = i;
  mNewestSortStep.j = j;
  mNewestSortStep.type = type;
  if (type == StepType::SWAP) {
    mTotalSwap++;
  } else {
    mTotalComp++;
  }
  printFrame(mNewestSortStep);
}

void SortingVisualizer::printHeader() const {
  cout << "Algorithm: " << mName << "\nCompare: " << mTotalComp
       << "\nSwap: " << mTotalSwap << "\n";
}

void SortingVisualizer::printFrame(const SortStep &step) const {
  printHeader();
  printSortStep(step);
  resetFrame();
}

void SortingVisualizer::printFinalFrame() const {
  printHeader();
  vector<unsigned int> arr = move(mNewestSortStep.arr);
  for (int t = 0; t < arr.size(); ++t) {
    for (unsigned int line = 1; line <= mMaxHeight; ++line) {
      for (size_t i = 0; i < arr.size(); ++i) {
        unsigned int n = arr[i];
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
      cout << "\n" << ANSI_COLOR::RESET;
    }
    // reset cursor to the top of the array section
    if (t < arr.size() - 1) {
      cout << "\033[" << to_string(mMaxHeight) << "A\033[1G";
      this_thread::sleep_for(REFRESH_TIME);
    }
  }
}

void SortingVisualizer::printSortStep(const SortStep &step) const {
  // move cursor to the starting point (compare line)
  string stepColor = (step.type == StepType::COMPARE)
                         ? string(ANSI_COLOR::YELLOW)
                         : string(ANSI_COLOR::RED);
  for (unsigned int line = 1; line <= mMaxHeight; ++line) {
    for (size_t i = 0; i < step.arr.size(); ++i) {
      unsigned int n = step.arr[i];
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
    cout << "\n" << ANSI_COLOR::RESET;
  }
}

void SortingVisualizer::printStarterFrame(
    const vector<unsigned int> &arr) const {
  printHeader();
  for (unsigned int line = 1; line <= mMaxHeight; ++line) {
    for (auto n : arr) {
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

void SortingVisualizer::calculateUnit(const vector<unsigned int> &arr) {
  auto maxElement = max_element(arr.begin(), arr.end());
  mMaxHeight = *maxElement;
  mUnit = arr[0];
  for (size_t i = 0; i < arr.size(); ++i) {
    mUnit = gcd(mUnit, arr[i]);
    if (mUnit <= 1) {
      return;
    }
  }
  if (mMaxHeight / mUnit < MIN_HEIGHT) {
    mUnit /= ceil(MIN_HEIGHT / (float)(mMaxHeight / mUnit));
  }
  mMaxHeight /= mUnit;
}

void SortingVisualizer::resetFrame() const {
  cout << "\033[" << to_string(mMaxHeight + 3) << "A\0331G";
}
