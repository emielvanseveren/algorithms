
#include "gtest/gtest.h"
#include "twoSum.hpp"
#include <vector>

TEST(TwoSum, bruteForce){
    // case 1
    std::vector<int> input0 = {2,7,11,15};
    std::vector<int> output0 = twoSum(input0, 9);
    EXPECT_EQ(output0[0],0);
    EXPECT_EQ(output0[1], 1);
    // case 2
    std::vector<int> input1 = {0,4,3,0};
    std::vector<int> output1= twoSum(input1,0);
    EXPECT_EQ(output1[0], 0);
    EXPECT_EQ(output1[1], 3);
    // case 3
    std::vector<int> input2 = {3,2,4};
    std::vector<int> output2 = twoSum(input2,6);
    EXPECT_EQ(output2[0], 1);
    EXPECT_EQ(output2[1], 2);
}

TEST(TwoSum, twoSumHashTable){
    // case 1
    std::vector<int> input0 = {2,7,11,15};
    std::vector<int> output0 = twoSumHashTable(input0, 9);
    EXPECT_EQ(output0[0],0);
    EXPECT_EQ(output0[1], 1);
    // case 2
    std::vector<int> input1 = {0,4,3,0};
    std::vector<int> output1= twoSumHashTable(input1,0);
    EXPECT_EQ(output1[0], 0);
    EXPECT_EQ(output1[1], 3);
    // case 3
    std::vector<int> input2 = {3,2,4};
    std::vector<int> output2 = twoSumHashTable(input2,6);
    EXPECT_EQ(output2[0], 1);
    EXPECT_EQ(output2[1], 2);
}
