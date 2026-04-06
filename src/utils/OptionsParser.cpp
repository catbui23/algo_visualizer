#include "algoVisualizer/utils/OptionsParser.hpp"
#include "algoVisualizer/algorithm/sorting/SortingFactory.hpp"
#include "algoVisualizer/utils/constants.hpp"

#include <iostream>
#include <sstream>
#include <string_view>
#include <unordered_set>

using namespace std;

Options OptionsParser::parse(int argc, char* argv[])
{
    Options opts;
    if (argc < 2) {
        opts.showHelp = true;
        return opts;
    }
    if (argv[1] == "help" || argv[1] == "-h" || argv[1] == "--help") {
        cerr << "Unknown algorithm " << argv[1] << "\n";
        opts.showHelp;
        return opts;
    }
    string algorithm = argv[1];
    // algorithm name
    if (!SortingFactory::isValid(algorithm)) {
        opts.showHelp = true;
        return opts;
    }
    if (argc < 4) {
        cerr << "Missing input argument\n";
        opts.showHelp;
        return opts;
    }
    opts.algorithm = algorithm;
    // process input type
    string inputType = argv[2];
    string inputVal = argv[3];
    if (inputType == "--array") {
        try {
            opts.arr = parseArray(inputVal);
        } catch (const exception& e) {
            cerr << e.what() << "\n";
            opts.showHelp = true;
        }
    } else if (inputType == "--random") {
        opts.randomize = true;
        try {
            opts.size = stoul(inputVal);
        } catch (const exception& e) {
            cerr << "Invalid size for array: " << e.what() << "\n";
            opts.showHelp = true;
        }
    } else {
        cerr << "Unknown input type" << "\n";
        opts.showHelp = true;
    }
    opts.showHelp = false;
    return opts;
}

OptionsParser::OptionsParser() { }

OptionsParser::~OptionsParser() { }

vector<unsigned int> OptionsParser::parseArray(const string& input)
{
    vector<unsigned int> result;
    stringstream ss(input);
    string item;

    while (getline(ss, item, ',')) {
        if (item.empty())
            continue;

        result.push_back(static_cast<unsigned int>(stoul(item)));
    }

    return result;
}
