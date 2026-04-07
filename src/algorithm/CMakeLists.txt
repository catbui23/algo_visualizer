add_library(algorithm
            sorting/implementations/BubbleSort.cpp
            sorting/implementations/InsertionSort.cpp
            sorting/implementations/SelectionSort.cpp
            sorting/implementations/MergeSort.cpp
            sorting/implementations/ThreeWayMergeSort.cpp
            sorting/implementations/QuickSort.cpp
            sorting/implementations/HeapSort.cpp
            sorting/implementations/CycleSort.cpp
            sorting/implementations/RadixSort.cpp
            sorting/implementations/IntroSort.cpp
            sorting/implementations/TimSort.cpp
            sorting/SortingFactory.cpp)
target_include_directories(algorithm PRIVATE ${PROJECT_SOURCE_DIR}/include)
