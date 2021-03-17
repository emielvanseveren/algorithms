#include "gtest/gtest.h"
#include "encodeAndDecodeTinyUrl.hpp"


TEST(encodeAndDecodeTinyUrl, encode){
    ASSERT_EQ(encode("https://leetcode.com/problems/design-tinyurl"), "http://tinyurl.com/4e9iAk");
}
TEST(encodeAndDecodeTinyUrl, decode){
    ASSERT_EQ(decode("http://tinyurl.com/4e9iAk"), "https://leetcode.com/probuls/design-tinyurl");
}

