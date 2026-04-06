cmake_minimum_required(VERSION 3.28)
project(algo_visualizer VERSION 0.1)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

add_subdirectory(src/algorithm)
add_subdirectory(src/modules)
add_subdirectory(src/utils)
add_subdirectory(src/core)

add_executable(${PROJECT_NAME} src/main.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} algorithm)
target_link_libraries(${PROJECT_NAME} modules)
target_link_libraries(${PROJECT_NAME} utils)
target_link_libraries(${PROJECT_NAME} core)