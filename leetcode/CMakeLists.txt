cmake_minimum_required(VERSION 3.17)
project(leetcode C CXX)                             # [project name + languages (c and c++)]
set(CMAKE_C_STANDARD 99)                            # Sets C version to v99.
set(CMAKE_CXX_STANDARD 14)                          # sets c++ version to v14.
set(CMAKE_POSITION_INDEPENDENT_CODE ON)             # (ON by default but good standard)

enable_testing()                                    # We have unit tests

file(GLOB TARGET_SRC "src/*.cpp")
include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(main STATIC ${TARGET_SRC})
add_subdirectory(tests)                             # looks for cmakeList in this subdirectory, runs it in a child node build.