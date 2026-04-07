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
#include "algoVisualizer/core/AppRunner.hpp"
#include "algoVisualizer/modules/sorting/sortingVisualizer.hpp"
#include "algoVisualizer/utils/OptionsParser.hpp"
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    Options opts = OptionsParser::parse(argc, argv);
    AppRunner::run(opts);
}