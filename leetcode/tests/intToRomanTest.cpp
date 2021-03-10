#include "gtest/gtest.h"
#include "intToRoman.hpp"
#include "vector"
#include "string"


TEST(intToRoman, singleDigit){
   std::vector<std::string> digits = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X"};
   for(int i=0; i<digits.size();i++){
    ASSERT_EQ(intToRoman(i+1),digits.at(i));
   }
}

TEST(intToRoman, twoDigits){
   ASSERT_EQ(intToRoman(58), "LVIII");
}

TEST(intToRoman, year){
    ASSERT_EQ(intToRoman(1994), "MCMXCIV");
}
