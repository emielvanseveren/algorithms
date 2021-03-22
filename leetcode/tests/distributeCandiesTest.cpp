#include "gtest/gtest.h"
#include "distributeCandies.hpp"
#include "vector"

struct DistributeCandiesFixture: public ::testing::Test {
    static void SetUpTestSuite(){
        std::cout << "\033[1;31m"

        << "Alice has n candies, where the ith candy is of type candyType[i]. Alice noticed that she started to gain"
           << std::endl
           << "weight, so she visited a doctor. The doctor advised Alice to only eat n / 2 of the candies she has "
           << "(n is always even). Alice likes her candies very much, and she wants to eat the maximum number of "
           << std::endl
           << "different types of candies while still following the doctor's advice."
           << "Given the integer array candyType of length n, return the maximum number of different types of "
           << std::endl
           << "candies she can eat if she only eats n / 2 of them.";
    }
    static void TearDownTestSuite(){}
    void SetUp(){}
    void TearDown(){}
    Solution s_;
};

TEST_F(DistributeCandiesFixture, shouldHandleDifferentTypes){
    std::vector<int> v ={1,1,2,2,3,3};
    EXPECT_EQ(s_.distributeCandies(v),3);
}

TEST_F(DistributeCandiesFixture, shouldHandleSizeEqualToAmountOfTypes){
    std::vector<int> v ={1,1,2,3};
    EXPECT_EQ(s_.distributeCandies(v), 2);
}

TEST_F(DistributeCandiesFixture, shouldHandleOneType){
    std::vector<int> v= {6,6,6,6};
    EXPECT_EQ(s_.distributeCandies(v), 1);
}

TEST_F(DistributeCandiesFixture, shouldHandleDifferentTypesWithBitSet){
    std::vector<int> v ={1,1,2,2,3,3};
    EXPECT_EQ(s_.distributeCandies(v),3);
}

TEST_F(DistributeCandiesFixture, shouldHandleSizeEqualToAmountOfTypesWithBitSet){
    std::vector<int> v ={1,1,2,3};
    EXPECT_EQ(s_.distributeCandies(v), 2);
}

TEST_F(DistributeCandiesFixture, shouldHandleOneTypeWithBitSet){
    std::vector<int> v= {6,6,6,6};
    EXPECT_EQ(s_.distributeCandies(v), 1);
}