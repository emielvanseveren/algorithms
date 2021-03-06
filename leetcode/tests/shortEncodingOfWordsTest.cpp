#include "gtest/gtest.h"
#include "shortEncodingOfWords.hpp"
#include "vector"
#include "string"


TEST(shortEncodingOfWords, normal){
   std::vector<std::string> words = {"time", "me", "bell"};
   EXPECT_EQ(minimumLengthEncoding(words), 10);
}
TEST(shortEncodingOfWords, letter){
    std::vector<std::string> words = {"t"};
    EXPECT_EQ(minimumLengthEncoding(words), 2);
}
TEST(shortEncodingOfWords, empty){
    std::vector<std::string> words = {};
    EXPECT_EQ(minimumLengthEncoding(words), 0);
}

