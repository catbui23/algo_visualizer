#include "algoVisualizer/core/AppRunner.hpp"
#include "algoVisualizer/algorithm/sorting/SortingFactory.hpp"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <random>

using namespace std;

void AppRunner::run(const Options& opts)
{
    vector<unsigned int> arr;
    if (opts.showHelp) {
        printHelp();
        return;
    }
    if (opts.randomize) {
        try {
            arr = generateRandomVector(opts.size.value());
        } catch (const bad_optional_access& e) {
            cerr << "Randomize but size is empty: " << e.what() << "\n";
        }
    } else {
        try {
            arr = opts.arr.value();
        } catch (const bad_optional_access& e) {
            cerr << "Input array but it is empty: " << e.what() << "\n";
        }
    }
    try {
        SortingMeta meta = SortingFactory::getMeta(opts.algorithm);
        SortingVisualizer vis(meta.displayName, arr);
        unique_ptr<ISortingAlgorithm> sortingALgorithm = meta.creator(arr, vis);
        sortingALgorithm->start();
        sortingALgorithm.reset();
    } catch (const invalid_argument& e) {
        cerr << "Invalid argument: " << e.what() << "\n";
    }
}

vector<unsigned int> AppRunner::generateRandomVector(const unsigned int size)
{
    vector<unsigned int> arr(size);
    iota(arr.begin(), arr.end(), 1);
    std::random_device rd;
    std::mt19937 g(rd());
    shuffle(arr.begin(), arr.end(), g);
    return arr;
}

void AppRunner::printHelp()
{
    cout << "You really need help\n";
}

AppRunner::AppRunner() { }

AppRunner::~AppRunner() { }