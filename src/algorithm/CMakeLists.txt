add_library(algorithm
            sorting/BubbleSort.cpp
            sorting/InsertionSort.cpp)
target_include_directories(algorithm PRIVATE ${PROJECT_SOURCE_DIR}/include)
