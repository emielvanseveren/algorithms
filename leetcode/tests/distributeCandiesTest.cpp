#include "gtest/gtest.h"
#include "distributeCandies.hpp"
#include <vector>

TEST(distributeCandies, types){
    std::vector<int> v ={1,1,2,2,3,3};
    EXPECT_EQ(distributeCandies(v),3);
}

TEST(distributeCandies, sizeEqualToAmountOfTypes){
    std::vector<int> v ={1,1,2,3};
    EXPECT_EQ(distributeCandies(v), 2);
}

TEST(distributeCandies, oneType){
    std::vector<int> v= {6,6,6,6};
    EXPECT_EQ(distributeCandies(v), 1);
}