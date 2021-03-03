#include "gtest/gtest.h"
#include <vector>
#include "missingNumber.hpp"


TEST(missingNumber, 1){
    std::vector<int> input = {3,0,1};
    EXPECT_EQ(missingNumber(input),2);
}

TEST(missingNumober, 2){
    std::vector<int> input = {0,1};
    EXPECT_EQ(missingNumber(input),2);
}

TEST(missingNumober, 3){
    std::vector<int> input = {9,6,4,2,3,5,7,0,1};
    EXPECT_EQ(missingNumber(input),8);
}

TEST(missingNumber, 4){
    std::vector<int> input = {0};
    EXPECT_EQ(missingNumber(input),1);
}