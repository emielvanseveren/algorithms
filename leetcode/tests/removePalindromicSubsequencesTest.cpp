#include "gtest/gtest.h"
#include "removePalindromicSubsequences.hpp"


TEST(removePalindromicSubsequences, emptyInput){
    EXPECT_EQ(removePalindromeSub(""),0);
}
TEST(removePalindromicSubsequences, palindrome) {
    EXPECT_EQ(removePalindromeSub("abb"), 2);
}
TEST(removePalindromicSubsequences, notAPalindrome) {
    EXPECT_EQ(removePalindromeSub("baabb"),2);
}

TEST(removePalindromicSubsequences, notAPalindrome2) {
    EXPECT_EQ(removePalindromeSub("bbaabaaa"),2);
}