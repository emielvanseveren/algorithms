#include "gtest/gtest.h"
#include "vector"
#include "missingNumber.hpp"
#include "iostream"

struct MissingNumberFixture: public ::testing::Test {
    static void SetUpTestSuite(){
        std::cout << "\033[1;31m"
        << "Given an array nums containing n distinct numbers in the range [0, n], return the only number in "
        << "the range that is missing from the array.";
    }

    static void TearDownTestSuite(){}
    void SetUp(){}
    void TearDown(){}
    Solution s_;
};

TEST_F(MissingNumberFixture, handleLastElementMissing){
    std::vector<int> input = {0,1};
    EXPECT_EQ(s_.missingNumber(input),2);
}

TEST_F(MissingNumberFixture, handleUnorderedSet){
    std::vector<int> input = {9,6,4,2,3,5,7,0,1};
    EXPECT_EQ(s_.missingNumber(input),8);
}

TEST_F(MissingNumberFixture, handleZeroInput){
    std::vector<int> input = {0};
    EXPECT_EQ(s_.missingNumber(input),1);
}