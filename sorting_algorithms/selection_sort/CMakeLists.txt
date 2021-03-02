cmake_minimum_required(VERSION 3.10)

project(selection_sort)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
# Enable the Address Sanitizer
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -fsanitize=address,undefined -fno-omit-frame-pointer")


include_directories(include)

# add_library(ExampleHppLibrary INTERFACE)
# target_include_directories(ExampleHppLibrary INTERFACE include/)

add_library(ClosestPair SHARED src/closestpair.cpp include/closestpair.h)
#add_library(Generators SHARED include/generators.h)

set(SOURCES src/main.cpp)

add_executable(selection_sort ${SOURCES} ${HEADERS})
target_link_libraries(selection_sort PUBLIC ClosestPair)

enable_testing()
add_subdirectory()

