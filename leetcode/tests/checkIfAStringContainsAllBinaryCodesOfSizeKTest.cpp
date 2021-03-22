#include "gtest/gtest.h"
#include "checkIfAStringContainsAllBinaryCodesOfSizeK.hpp"


struct CheckIfAStringContainsAllBinaryCodesOfSizeKFixture: public ::testing::Test {
    static void SetUpTestSuite(){
        std::cout << "\033[1;31m"
        << "Given a binary string s and an integer k.\n"
           "Return true if every binary code of length k is a substring of s. Otherwise, return false.\n";
    }

    static void TearDownTestSuite(){}
    void SetUp(){}
    void TearDown(){}
    Solution s_;
};

TEST_F(CheckIfAStringContainsAllBinaryCodesOfSizeKFixture, s1){
    ASSERT_EQ(s_.hasAllCodes("00110110", 2), true);
}

TEST_F(CheckIfAStringContainsAllBinaryCodesOfSizeKFixture, s2){
    ASSERT_EQ(s_.hasAllCodes("00110", 2), true);
}

TEST_F(CheckIfAStringContainsAllBinaryCodesOfSizeKFixture, s3){
    ASSERT_EQ(s_.hasAllCodes("0110", 1), true);
}

TEST_F(CheckIfAStringContainsAllBinaryCodesOfSizeKFixture, s4){
    ASSERT_EQ(s_.hasAllCodes("0110", 2), false);
}


// BITSET solution
TEST_F(CheckIfAStringContainsAllBinaryCodesOfSizeKFixture, s5){
    ASSERT_EQ(s_.hasAllCodesWithBitSet("00110110", 2), true);
}
TEST_F(CheckIfAStringContainsAllBinaryCodesOfSizeKFixture, s6){
    ASSERT_EQ(s_.hasAllCodesWithBitSet("00110", 2), true);
}
TEST_F(CheckIfAStringContainsAllBinaryCodesOfSizeKFixture, s7){
    ASSERT_EQ(s_.hasAllCodesWithBitSet("0110", 1), true);
}
TEST_F(CheckIfAStringContainsAllBinaryCodesOfSizeKFixture, s8){
    ASSERT_EQ(s_.hasAllCodesWithBitSet("0110", 2), false);
}
