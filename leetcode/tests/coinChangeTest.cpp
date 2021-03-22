#include "gtest/gtest.h"
#include "vector"
#include "coinChange.hpp"


struct CoinChangeFixture: public ::testing::Test {
    static void SetUpTestSuite(){
        std::cout << "\033[1;31m"
            << "You are given an integer array coins representing coins of different denominations and an integer amount "
               "representing a total amount of money."
               << std::endl
               << "Return the fewest number of coins that you need to make up that amount. If that amount of money "
               "cannot be made up by any combination of the coins, return -1."
               << std::endl
               << "You may assume that you have an infinite number of each kind of coin."
               << std::endl;
    }
    static void TearDownTestSuite(){}
    void SetUp(){}
    void TearDown(){}
    Solution s_;
};

TEST_F(CoinChangeFixture, simple){
    std::vector<int> input = {1,2,5};
    ASSERT_EQ(s_.coinChange(input, 11), 3);
}

TEST_F(CoinChangeFixture, handleSingleCoinType){
    std::vector<int> input = {2};
    ASSERT_EQ(s_.coinChange(input, 3), -1);
}

TEST_F(CoinChangeFixture, handleNoAmount){
    std::vector<int> input = {1};
    ASSERT_EQ(s_.coinChange(input, 0), 0);
}

TEST_F(CoinChangeFixture, handleCoinTypeEqualToAmount){
    std::vector<int> input = {1};
    ASSERT_EQ(s_.coinChange(input, 1), 1);
}

TEST_F(CoinChangeFixture, handleAmountMultiplicationOfCoinType){
    std::vector<int> input = {1};
    ASSERT_EQ(s_.coinChange(input, 2), 2);
}

TEST_F(CoinChangeFixture, handleCoinTypeLargerThanAmount){
    std::vector<int> input = {1,2147483647};
    ASSERT_EQ(s_.coinChange(input, 2), 2);
}

TEST_F(CoinChangeFixture, handleCoinTypesRandomOrder){
    std::vector<int> input = {2,5,10,1};
    EXPECT_EQ(s_.coinChange(input, 27), 4);
}

TEST_F(CoinChangeFixture, handleRandomNumbers){
    std::vector<int> input = {186,419,83,408};
    EXPECT_EQ(s_.coinChange(input, 6249), 20);
}
