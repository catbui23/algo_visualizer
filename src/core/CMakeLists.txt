add_library(core AppRunner.cpp)
target_include_directories(core PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(core
                        modules
                        algorithm)