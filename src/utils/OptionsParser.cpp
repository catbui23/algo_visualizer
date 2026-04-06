#include "algoVisualizer/utils/OptionsParser.hpp"
#include "algoVisualizer/algorithm/sorting/SortingFactory.hpp"
#include "algoVisualizer/utils/constants.hpp"
#include "nlohmann/json.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string_view>
#include <unordered_set>

using namespace std;
using json = nlohmann::json;

Options OptionsParser::parse(int argc, char* argv[])
{
    Options opts;
    if (argc < 2) {
        opts.showHelp = true;
        return opts;
    }
    string arg1 = argv[1];
    if (arg1 == "help" || arg1 == "-h" || arg1 == "--help") {
        opts.showHelp;
        return opts;
    } else if (arg1 == "-f" || arg1 == "--file") {
        if (argc < 3) {
            opts.showHelp = true;
            return opts;
        }
        try {
            string filePath = argv[2];
            return parseJsonFile(filePath);
        } catch (const exception& e) {
            cerr << "Error while processing file: " << e.what() << "\n";
            opts.showHelp;
            return opts;
        }
    }
    cerr << "Not from file\n";
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

Options OptionsParser::parseJsonFile(string filePath)
{
    ifstream file(filePath);
    json data = json::parse(file);

    Options opts = {
        data.value("algorithm", ""),
        data.value("array", vector<unsigned int>()),
        data.value("random", false),
        data.value("size", 0),
        false,
    };

    return opts;
}
