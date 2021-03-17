#include "gtest/gtest.h"
#include "checkIfAStringContainsAllBinaryCodesOfSizeK.hpp"

TEST(CheckIfAStringContainsAllBinaryCodesOfSizeK, s1){
    ASSERT_EQ(hasAllCodes("00110110", 2), true);
}

TEST(CheckIfAStringContainsAllBinaryCodesOfSizeK, s2){
    ASSERT_EQ(hasAllCodes("00110", 2), true);
}

TEST(CheckIfAStringContainsAllBinaryCodesOfSizeK, s3){
    ASSERT_EQ(hasAllCodes("0110", 1), true);
}

TEST(CheckIfAStringContainsAllBinaryCodesOfSizeK, s4){
    ASSERT_EQ(hasAllCodes("0110", 2), false);
}

// BITSET solution

TEST(CheckIfAStringContainsAllBinaryCodesOfSizeKWithBitSet, s1){
    ASSERT_EQ(hasAllCodesWithBitSet("00110110", 2), true);
}

TEST(CheckIfAStringContainsAllBinaryCodesOfSizeKWithBitSet, s2){
    ASSERT_EQ(hasAllCodesWithBitSet("00110", 2), true);
}

TEST(CheckIfAStringContainsAllBinaryCodesOfSizeKWithBitSet, s3){
    ASSERT_EQ(hasAllCodesWithBitSet("0110", 1), true);
}

TEST(CheckIfAStringContainsAllBinaryCodesOfSizeKWithBitSet, s4){
    ASSERT_EQ(hasAllCodesWithBitSet("0110", 2), false);
}
