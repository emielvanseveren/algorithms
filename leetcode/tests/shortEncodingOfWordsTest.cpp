#include "gtest/gtest.h"
#include "shortEncodingOfWords.hpp"
#include "vector"
#include "string"

struct ShortEncodingOfWordsFixture: public ::testing::Test {
    static void SetUpTestSuite(){
        std::cout << "\033[1;31m"
        << "A valid encoding of an array of words is any reference string s and array of indices indices such that:\n"
           << std::endl
           << "words.length == indices.length"
           << std::endl
           << "The reference string s ends with the '#' character."
           << std::endl
           << "For each index indices[i], the substring of s starting from indices[i] and up to (but not including) the "
              "next '#' character is equal to words[i]. Given an array of words, return the length of the shortest "
              "reference string s possible of any valid encoding of words."
              << std::endl;
    }
    static void TearDownTestSuite(){}
    void SetUp(){}
    void TearDown(){}
    Solution s_;
};


TEST_F(ShortEncodingOfWordsFixture, normal){
   std::vector<std::string> words = {"time", "me", "bell"};
   EXPECT_EQ(s_.minimumLengthEncoding(words), 10);
}
TEST_F(ShortEncodingOfWordsFixture, letter){
    std::vector<std::string> words = {"t"};
    EXPECT_EQ(s_.minimumLengthEncoding(words), 2);
}
TEST_F(ShortEncodingOfWordsFixture, empty){
    std::vector<std::string> words = {};
    EXPECT_EQ(s_.minimumLengthEncoding(words), 0);
}

