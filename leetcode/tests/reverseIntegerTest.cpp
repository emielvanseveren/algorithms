#include "gtest/gtest.h"
#include "reverseInteger.hpp"

struct ReverseIntegerFixture: public ::testing::Test {
    static void SetUpTestSuite(){
        std::cout << "\033[1;31m"
        << "Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go"
           "outside the signed 32-bit integer range [-231, 231 - 1], then return 0." << std::endl;
    }
    static void TearDownTestSuite(){}
    void SetUp(){}
    void TearDown(){}
    Solution s_;
};

TEST_F(ReverseIntegerFixture, handlePositiveNumber){
    EXPECT_EQ((123),321);
}

TEST_F(ReverseIntegerFixture, handleNegativeNumber){
    EXPECT_EQ(s_.reverse(-123), -321);
}

TEST_F(ReverseIntegerFixture, handleEndingZero){
    EXPECT_EQ(s_.reverse(120), 21);
}

TEST_F(ReverseIntegerFixture, handleOverflow){
    EXPECT_EQ(s_.reverse(1534236569),0);
}

TEST_F(ReverseIntegerFixture, handleZero){
    EXPECT_EQ(s_.reverse(0),0);
}