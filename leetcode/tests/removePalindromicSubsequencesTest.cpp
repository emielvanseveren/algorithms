#include "gtest/gtest.h"
#include "removePalindromicSubsequences.hpp"


struct RemovePalindromicSubsequencesFixture: public ::testing::Test {

    Solution s_;
    static void SetUpTestSuite(){
        std::cout << "\033[1;31m"
                  << "You are given a string s consisting only of letters 'a' and 'b'. In a single step you can remove "
                     "one palindromic subsequence from s. Return the minimum number of steps to make the given string "
                     "empty. A string is a subsequence of a given string if it is generated by deleting some characters "
                     "of a given string without changing its order. Note that a subsequence does not necessarily need "
                     "to be contiguous." << std::endl
                  << "A string is called palindrome if is one that reads the same backward as well as forward.";
    }
    static void TearDownTestSuite(){}
    void SetUp(){}
    void TearDown(){}
};

TEST_F(RemovePalindromicSubsequencesFixture, handleEmptyInput){
    EXPECT_EQ(s_.removePalindromeSub(""),0);
}
TEST_F(RemovePalindromicSubsequencesFixture, handlePalindrome) {
    EXPECT_EQ(s_.removePalindromeSub("abb"), 2);
}
TEST_F(RemovePalindromicSubsequencesFixture, handleNotAPalindrome) {
    EXPECT_EQ(s_.removePalindromeSub("baabb"),2);
    EXPECT_EQ(s_.removePalindromeSub("bbaabaaa"),2);
}
