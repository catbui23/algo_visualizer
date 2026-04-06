#include "algoVisualizer/utils/utils.hpp"

#include <algorithm>

using namespace std;

string toLower(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}