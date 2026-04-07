#pragma once

#include <optional>
#include <string>
#include <vector>

using namespace std;

struct Options {
    string algorithm;
    optional<vector<unsigned int>> arr;
    bool randomize = false;
    optional<unsigned int> size;
    bool showHelp = false;
    bool listAlgo = false;
};
