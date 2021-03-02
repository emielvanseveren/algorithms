cmake_minimum_required (VERSION 3.19)
project (test_selection_sort)

# In comparison with 
include(FetchContent)
FetchContent_Declare(catch
  GIT_REPOSITORY  "https://github.com/catchorg/catch2"
  GIT_TAG         "v2.13.4"
  GIT_SHALLOW     true
)
# 
FetchContent_MakeAvailable(catch)

LIST(APPEND CMAKE_MODULE_PATH "${catch_SOURCE_DIR}/contrib")
set(AdditionalCatchParameters )

add_executable(test_selection_sort testselectionsort.cpp)
target_link_libraries(test_selection_sort Catch2::Catch2 ClosestPair)

include(CTest)
include(Catch)
catch_discover_tests(test_selection_sort
	EXTRA_ARGS -o report.xml -s -r junit
)
