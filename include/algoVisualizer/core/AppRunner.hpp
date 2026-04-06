#pragma once

#include "algoVisualizer/algorithm/sorting/interface/ISortingAlgorithm.hpp"
#include "algoVisualizer/utils/Options.hpp"
#include <memory>
#include <vector>

using namespace std;

class AppRunner {
public:
    AppRunner();
    ~AppRunner();

    static void run(const Options& opts);

private:
    static vector<unsigned int> generateRandomVector(const unsigned int size);
    static void printHelp();
};
