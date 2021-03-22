#include "gmock/gmock.h"
#include "twoSum.hpp"
#include "vector"

using namespace testing;

struct TwoSumFixture: public Test {
    static void SetUpTestSuite(){
        std::cout << "\033[1;31m"
            << "Given an array of integers nums and an integer target, return indices of the two numbers such that they "
           "add up to target."
           << "You may assume that each input would have exactly one solution, and you may not use the same element twice."
           << "You can return the answer in any order."
           << std::endl;
    }
    static void TearDownTestSuite(){}
    void SetUp(){}
    void TearDown(){}
    Solution s_;
};

TEST_F(TwoSumFixture, handleNormal){
    std::vector<int> input = {2,7,11,15};
    ASSERT_THAT(s_.twoSum(input,9), ElementsAreArray({0,1}));
}
TEST_F(TwoSumFixture, handleTwoZeros){
    std::vector<int> input = {0,4,3,0};
    ASSERT_THAT(s_.twoSum(input,0), ElementsAreArray({0,3}));
}
TEST_F(TwoSumFixture, handleLast){
    std::vector<int> input = {3,2,4};
    ASSERT_THAT(s_.twoSum(input,6), ElementsAreArray({1,2}));
}

/*  ################################################################
 *              HASHTABLE IMPLEMENTATION
 *  ################################################################
*/

TEST_F(TwoSumFixture, handleHashTableDefault){
    std::vector<int> input = {2,7,11,15};
    ASSERT_THAT(s_.twoSumHashTable(input,9), ElementsAreArray({0,1}));
}
TEST_F(TwoSumFixture, handleHashTabletwoZeros){
    std::vector<int> input = {0,4,3,0};
    ASSERT_THAT(s_.twoSumHashTable(input,0), ElementsAreArray({0,3}));
}
TEST_F(TwoSumFixture, handleHashTableLast){
    std::vector<int> input = {3,2,4};
    ASSERT_THAT(s_.twoSumHashTable(input,6), ElementsAreArray({1,2}));
}
