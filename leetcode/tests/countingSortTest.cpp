#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "countingSort.hpp"
#include "vector"

using namespace testing;

struct CountingSortFixture: public ::testing::Test {
    static void SetUpTestSuite(){
        std::cout << "\033[1;31m"
        << "Implementation of counting sort algorithm." << std::endl;
    }
    static void TearDownTestSuite(){}
    void SetUp(){}
    void TearDown(){}
    Solution s_;
};

TEST_F(CountingSortFixture, case1){
    std::vector<int> input = {1,4,1,2,7,5,2,8};
    ASSERT_THAT(s_.sort(input, 1,8), ElementsAreArray({1,1,2,2,4,5,7,8}));
}