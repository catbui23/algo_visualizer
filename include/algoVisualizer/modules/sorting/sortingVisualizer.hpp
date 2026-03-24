#pragma once

#include "algoVisualizer/core/visualize.hpp"
#include <string>
#include <vector>

using namespace std;

enum StepType {
  SWAP,
  COMPARE,
};

struct SortStep {
  vector<unsigned int> arr;
  size_t i;
  size_t j;
  StepType type;
};

class SortingVisualizer : public IVisualizer {
public:
  SortingVisualizer(const string name, const vector<unsigned int> &arr);
  ~SortingVisualizer();
  void render() const;
  void printHeader() const;
  void updateSortStep(const vector<unsigned int> &arr, const size_t i,
                      const size_t j, const StepType type);

private:
  string mName;
  unsigned int mTotalComp;
  unsigned int mTotalSwap;
  SortStep mNewestSortStep;
  unsigned int mUnit;
  unsigned int mMaxHeight;

  void printFrame(const SortStep &step) const;
  void printFinalFrame() const;
  void printSortStep(const SortStep &step) const;
  void printStarterFrame(const vector<unsigned int> &arr) const;
  void calculateUnit(const vector<unsigned int> &arr);
  void resetFrame() const;
};
