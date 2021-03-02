cmake_minimum_required(VERSION 3.17)
project(test_twoSum)
set(CMAKE_CXX_STANDARD 14)

#Setup Google testing framework
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        703bd9caab50b139428cea1aaff9974ebee5742e # release-1.10.0
        SOURCE_DIR     "${CMAKE_CURRENT_BINARY_DIR}/googletest-src"
        BINARY_DIR     "${CMAKE_CURRENT_BINARY_DIR}/googletest-build"
)
FetchContent_MakeAvailable(googletest)
find_package(GTest REQUIRED)


file(GLOB TESTS_SRC ./*.cpp)              # Source test files
add_executable(tests ${TESTS_SRC})
target_link_libraries(tests PUBLIC
        gmock                             # googlemock is googltest extension ~ly for mocking as you may have guessed.
        gtest_main                        # provided by google and pulls the main program from that lib
        main                              # library we are testing (library on higher dir is called main)
        )

option(BUILD_GMOCK "builds gmock subproject" ON)
