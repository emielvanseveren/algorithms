#include "gtest/gtest.h"
#include "vector"
#include "missingNumber.hpp"

TEST(missingNumber, handleLastElementMissing){
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