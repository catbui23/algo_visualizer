add_library(algorithm
            sorting/BubbleSort.cpp
            sorting/InsertionSort.cpp
            sorting/SelectionSort.cpp)
target_include_directories(algorithm PRIVATE ${PROJECT_SOURCE_DIR}/include)
