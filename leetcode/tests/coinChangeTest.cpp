#include "gtest/gtest.h"
#include "vector"
#include "coinChange.hpp"

TEST(coinChange, simple){
    std::vector<int> input = {1,2,5};
    EXPECT_EQ(coinChange(input, 11), 3);
}

TEST(coinChange, singleCoinType){
    std::vector<int> input = {2};
    EXPECT_EQ(coinChange(input, 3), -1);
}

TEST(coinChange, noAmount){
    std::vector<int> input = {1};
    EXPECT_EQ(coinChange(input, 0), 0);
}

TEST(coinChange, coinTypeEqualToAmount){
    std::vector<int> input = {1};
    EXPECT_EQ(coinChange(input, 1), 1);
}

TEST(coinChange, amountMultiplicationOfCoinType){
    std::vector<int> input = {1};
    EXPECT_EQ(coinChange(input, 2), 2);
}


TEST(coinChange, coinTypeLargerThanAmount){
    std::vector<int> input = {1,2147483647};
    EXPECT_EQ(coinChange(input, 2), 2);
}

TEST(coinChange, coinTypesRandomOrder){
    std::vector<int> input = {2,5,10,1};
    EXPECT_EQ(coinChange(input, 27), 4);
}

TEST(coinChange, randomNumbers){
    std::vector<int> input = {186,419,83,408};
    EXPECT_EQ(coinChange(input, 6249), 20);
}

