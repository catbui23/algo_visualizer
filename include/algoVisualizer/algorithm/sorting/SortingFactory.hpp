#pragma once

#include "algoVisualizer/algorithm/sorting/interface/ISortingAlgorithm.hpp"
#include "algoVisualizer/modules/sorting/sortingVisualizer.hpp"
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

struct SortingMeta {
    string displayName;
    function<unique_ptr<ISortingAlgorithm>(const vector<unsigned int>&, SortingVisualizer&)> creator;
};

class SortingFactory {
public:
    static bool isValid(const string algorithm);
    static const SortingMeta getMeta(const string algorithm);
    static vector<string> getListAlgo();

private:
    static const unordered_map<string, SortingMeta> SORTING_REGISTRY;
};