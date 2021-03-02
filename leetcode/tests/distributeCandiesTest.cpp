#include "gtest/gtest.h"
#include "distributeCandies.hpp"
#include <vector>

TEST(distributeCandies, example1){
    std::vector<int> v ={1,1,2,2,3,3};
    EXPECT_EQ(distributeCandies(v),3);
}

TEST(distributeCandies, example2){
    std::vector<int> v ={1,1,2,3};
    EXPECT_EQ(distributeCandies(v), 2);
}

TEST(distributeCandies, example3){
    std::vector<int> v= {6,6,6,6};
    EXPECT_EQ(distributeCandies(v), 1);
}