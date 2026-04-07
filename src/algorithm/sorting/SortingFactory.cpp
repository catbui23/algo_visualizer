#include "algoVisualizer/algorithm/sorting/SortingFactory.hpp"
#include "algoVisualizer/algorithm/sorting/implementations/BubbleSort.hpp"
#include "algoVisualizer/algorithm/sorting/implementations/CycleSort.hpp"
#include "algoVisualizer/algorithm/sorting/implementations/HeapSort.hpp"
#include "algoVisualizer/algorithm/sorting/implementations/InsertionSort.hpp"
#include "algoVisualizer/algorithm/sorting/implementations/IntroSort.hpp"
#include "algoVisualizer/algorithm/sorting/implementations/MergeSort.hpp"
#include "algoVisualizer/algorithm/sorting/implementations/QuickSort.hpp"
#include "algoVisualizer/algorithm/sorting/implementations/RadixSort.hpp"
#include "algoVisualizer/algorithm/sorting/implementations/SelectionSort.hpp"
#include "algoVisualizer/algorithm/sorting/implementations/ThreeWayMergeSort.hpp"
#include "algoVisualizer/algorithm/sorting/implementations/TimSort.hpp"

#include <stdexcept>

const unordered_map<string, SortingMeta> SortingFactory::SORTING_REGISTRY = {
    {
        "bubble",
        { "Bubble Sort",
            [](const vector<unsigned int>& arr, SortingVisualizer& vis) {
                return make_unique<BubbleSort>(arr, vis);
            } },
    },
    { "cycle",
        { "Cycle Sort",
            [](const vector<unsigned int>& arr, SortingVisualizer& vis) {
                return make_unique<CycleSort>(arr, vis);
            } } },
    { "heap",
        { "Heap Sort",
            [](const vector<unsigned int>& arr, SortingVisualizer& vis) {
                return make_unique<HeapSort>(arr, vis);
            } } },
    { "insertion",
        { "Insertion Sort",
            [](const vector<unsigned int>& arr, SortingVisualizer& vis) {
                return make_unique<InsertionSort>(arr, vis);
            } } },
    { "intro",
        { "Intro Sort",
            [](const vector<unsigned int>& arr, SortingVisualizer& vis) {
                return make_unique<IntroSort>(arr, vis);
            } } },
    { "merge",
        { "Merge Sort",
            [](const vector<unsigned int>& arr, SortingVisualizer& vis) {
                return make_unique<MergeSort>(arr, vis);
            } } },
    { "quick",
        { "Quick Sort",
            [](const vector<unsigned int>& arr, SortingVisualizer& vis) {
                return make_unique<QuickSort>(arr, vis);
            } } },
    { "radix",
        { "Radix Sort",
            [](const vector<unsigned int>& arr, SortingVisualizer& vis) {
                return make_unique<RadixSort>(arr, vis);
            } } },
    { "selection",
        { "Selection Sort",
            [](const vector<unsigned int>& arr, SortingVisualizer& vis) {
                return make_unique<SelectionSort>(arr, vis);
            } } },
    { "three_way_merge",
        { "Three-way Merge Sort",
            [](const vector<unsigned int>& arr, SortingVisualizer& vis) {
                return make_unique<ThreeWayMergeSort>(arr, vis);
            } } },
    { "tim",
        { "Tim Sort",
            [](const vector<unsigned int>& arr, SortingVisualizer& vis) {
                return make_unique<TimSort>(arr, vis);
            } } },
};

bool SortingFactory::isValid(const string algorithm)
{
    return (SORTING_REGISTRY.find(algorithm) != SORTING_REGISTRY.end());
}

const SortingMeta SortingFactory::getMeta(const string algorithm)
{
    if (!isValid(algorithm)) {
        throw invalid_argument("Unknown algorithm: " + algorithm);
    }
    return SORTING_REGISTRY.at(algorithm);
}

vector<string> SortingFactory::getListAlgo()
{
    vector<string> listAlgo;

    for (auto& [name, _] : SORTING_REGISTRY) {
        listAlgo.push_back(name);
    }

    return listAlgo;
}
