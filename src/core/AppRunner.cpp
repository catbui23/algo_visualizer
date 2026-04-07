#include "algoVisualizer/core/AppRunner.hpp"
#include "algoVisualizer/algorithm/sorting/SortingFactory.hpp"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

using namespace std;

const string AppRunner::HELP_MESSAGE = R"(

Algorithm Visualizer - Command Line Usage
========================================

USAGE:
  algo_visualizer [OPTIONS]

OPTIONS:
  -h, --help
      Show this help message

  -f, --file <file_path>
      Load configuration from JSON file

  -l, --list
      Show all available sorting algorithms

--------------------------------------------------

RUN WITH COMMAND LINE ARGUMENTS:

  algo_visualizer <algorithm> <input_type> <value>

  <algorithm>
      Name of the sorting algorithm (must be valid)
      Use --list to see all supported algorithms

  <input_type>
      --array     Provide input array manually
      --randomize    Generate random array

  <value>
      If --array  : Comma-separated list of integers
                    Example: "5,4,3,2,1"
      If --randomize : Size of the array (positive integer)
                    Example: 20

EXAMPLES:

  algo_visualizer quick --array "5,4,3,2,1"
  algo_visualizer merge --random 20

--------------------------------------------------

RUN WITH JSON FILE:

  algo_visualizer -f config.json

  JSON FORMAT:
  {
      "algorithm": string,              // required
      "array": array<unsigned int>,    // optional
      "randomize": bool,                  // optional (default: false)
      "size": unsigned int             // optional (used if random = true)
  }

  EXAMPLE:
  {
      "algorithm": "tim",
      "array": [5, 4, 3, 2, 1],
      "randomize": true,
      "size": 10
  }

  NOTES:
    - If "randomize" is true → random array will be used and "array" will be ignored
    - If "randomize" is false → "array" will be used and "size" will be ignored
)";

void AppRunner::run(const Options& opts)
{
    vector<unsigned int> arr;
    if (opts.showHelp) {
        printHelp();
        return;
    }
    if (opts.listAlgo) {
        printAlgorithm();
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
    cout << HELP_MESSAGE;
}

void AppRunner::printAlgorithm()
{
    vector<string> sortingAlgo = SortingFactory::getListAlgo();
    for (auto algo : sortingAlgo) {
        cout << algo << "\n";
    }
}

AppRunner::AppRunner() { }

AppRunner::~AppRunner() { }