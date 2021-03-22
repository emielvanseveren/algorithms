#include "gtest/gtest.h"
#include "maximumSubArray.hpp"
#include "vector"

struct MaximumSubArrayFixture: public ::testing::Test {
    static void SetUpTestSuite(){
        std::cout << "\033[1;31m"
        << "Given an integer array nums, find the contiguous subarray (containing at least one number) which has the "
           "largest sum and return its sum.";
        // TODO: add explanation here
    }
    static void TearDownTestSuite(){}
    void SetUp(){}
    void TearDown(){}
    Solution s_;
};

TEST_F(MaximumSubArrayFixture, case1){
    std::vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    ASSERT_EQ(s_.maximumSubArray(v), 6);
}

TEST_F(MaximumSubArrayFixture, singleNumber){
    std::vector<int> v = {1};
    ASSERT_EQ(s_.maximumSubArray(v), 1);
}

TEST_F(MaximumSubArrayFixture, case2){
    std::vector<int> v = {5,4,-1,7,8};
    ASSERT_EQ(s_.maximumSubArray(v), 23);
}
