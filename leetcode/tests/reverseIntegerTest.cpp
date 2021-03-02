#include "gtest/gtest.h"
#include "reverseInteger.hpp"



TEST(reverseInteger, positiveNumber){
    EXPECT_EQ(reverse(123),321);
}

TEST(reverseInteger, negativeNumber){
    EXPECT_EQ(reverse(-123), -321);
}

TEST(reverseInteger, endingZero){
    EXPECT_EQ(reverse(120), 21);
}

TEST(reverseInteger, overflow){
    EXPECT_EQ(reverse(1534236569),0);
}

TEST(reverseInteger, zero){
    EXPECT_EQ(reverse(0),0);
}