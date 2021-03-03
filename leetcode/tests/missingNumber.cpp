#include "gtest/gtest.h"
#include <vector>
#include "missingNumber.hpp"
#include <iostream>

TEST(missingNumber, handleLastElementMissing){
    std::cout   << "\033[0;35m"
                << "[DESCRIPTION] Given an array nums containing n distinct numbers in the range [0, n], "
                    "return the only number in the range that is missing from the array."
                 << std::endl;
    std::vector<int> input = {0,1};
    EXPECT_EQ(missingNumber(input),2);
}

TEST(missingNumber, handleUnorderedSet){
    std::vector<int> input = {9,6,4,2,3,5,7,0,1};
    EXPECT_EQ(missingNumber(input),8);
}

TEST(missingNumber, handleZeroInput){
    std::vector<int> input = {0};
    EXPECT_EQ(missingNumber(input),1);
}