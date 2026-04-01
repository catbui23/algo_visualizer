add_library(algorithm
            sorting/BubbleSort.cpp
            sorting/InsertionSort.cpp
            sorting/SelectionSort.cpp
            sorting/MergeSort.cpp
            sorting/ThreeWayMergeSort.cpp
            sorting/QuickSort.cpp
            sorting/HeapSort.cpp
            sorting/CycleSort.cpp
            sorting/RadixSort.cpp
            sorting/IntroSort.cpp)
target_include_directories(algorithm PRIVATE ${PROJECT_SOURCE_DIR}/include)
