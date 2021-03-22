#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "threeSum.hpp"
#include "vector"

using namespace testing;

struct ThreeSumFixture: public ::testing::Test {
    static void SetUpTestSuite(){
        std::cout << "\033[1;31m"
        << "Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all "
           "unique triplets in the array which gives the sum of zero.";
    }
    static void TearDownTestSuite(){}
    void SetUp(){}
    void TearDown(){}
    Solution s_;
};


TEST_F(ThreeSumFixture, normal){
    std::vector<int> input = {-1,0,1,2,-1,-4};
    ASSERT_THAT(s_.threeSum(input), ElementsAreArray({ElementsAreArray({-1,-1,2}), ElementsAreArray({-1,0,1})}));
}
TEST_F(ThreeSumFixture, empty){
    std::vector<int> input = {};
    ASSERT_THAT(s_.threeSum(input), input);
}
TEST_F(ThreeSumFixture, singleElement){
    std::vector<int> input = {0};
    std::vector<int> output = {};
    ASSERT_THAT(s_.threeSum(input), output);
}

*/
