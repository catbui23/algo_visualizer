#pragma once

#include "Options.hpp"
#include <string>
#include <vector>

using namespace std;

class OptionsParser {
public:
    static Options parse(int argc, char* argv[]);
    OptionsParser();
    ~OptionsParser();

private:
    static vector<unsigned int> parseArray(const string& input);
    static Options parseJsonFile(string filePath);
};