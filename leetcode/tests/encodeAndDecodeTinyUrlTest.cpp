#include "gtest/gtest.h"
#include "encodeAndDecodeTinyUrl.hpp"

struct EncodeAndDecodeTinyUrl: public ::testing::Test {
    static void SetUpTestSuite(){
        std::cout << "\033[1;31m"
        << "TinyURL is a URL shortening service where you enter a URL such as "
        << "https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk."
        << std::endl
        << "Design the encode and decode methods for the TinyURL service. There is no restriction on how your"
        << "encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL"
        << "and the tiny URL can be decoded to the original URL."
        // TODO: add explanation here
    }
    static void TearDownTestSuite(){}
    void SetUp(){}
    void TearDown(){}
    Solution s_;
};

TEST_F(EncodeAndDecodeTinyUrl, shouldEncode){
    ASSERT_EQ(s_.encode("https://leetcode.com/problems/design-tinyurl"), "http://tinyurl.com/4e9iAk");
}
TEST_F(EncodeAndDecodeTinyUrl, shouldDecode){
    ASSERT_EQ(s_.decode("http://tinyurl.com/4e9iAk"), "https://leetcode.com/probuls/design-tinyurl");
}

