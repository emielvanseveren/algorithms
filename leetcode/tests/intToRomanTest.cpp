#include "gtest/gtest.h"
#include "intToRoman.hpp"
#include "vector"
#include "string"

struct intToRomanFixture: public ::testing::Test {
    static void SetUpTestSuite(){
        std::cout << "\033[1;31m"
        << "Translate integer to roman" << std::endl;
        // TODO: add explanation here
    }
    static void TearDownTestSuite(){}
    void SetUp(){}
    void TearDown(){}
    Solution s_;
};

TEST_F(intToRomanFixture, handleSingleDigit){
   std::vector<std::string> digits = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X"};
   for(int i=0; i<digits.size();i++){
    ASSERT_EQ(s_.intToRoman(i+1),digits.at(i));
   }
}

TEST_F(intToRomanFixture, handleTwoDigits){
   ASSERT_EQ(s_.intToRoman(58), "LVIII");
}

TEST_F(intToRomanFixture, handleYear){
    ASSERT_EQ(s_.intToRoman(1994), "MCMXCIV");
}
