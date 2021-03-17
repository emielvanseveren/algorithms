#include "gtest/gtest.h"
#include "maximumSubArray.hpp"
#include "vector"


TEST(maximumSubArray, temp){
    std::vector<int> v = {1,-3,4,-1,2,1,-5,4};
    ASSERT_EQ(maximumSubArrayDaQ(v, 0, v.size()-1), 6);
}

TEST(maximumSubArray, case1){
    std::vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    ASSERT_EQ(maximumSubArray(v), 6);
}

TEST(maximumSubArray, singleNumber){
    std::vector<int> v = {1};
    ASSERT_EQ(maximumSubArray(v), 1);
}

TEST(maximumSubArray, case2){
    std::vector<int> v = {5,4,-1,7,8};
    ASSERT_EQ(maximumSubArray(v), 23);
}

