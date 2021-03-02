#include "gmock/gmock.h"
#include "twoSum.hpp"
#include <vector>

using namespace testing;

TEST(TwoSumBruteForce, normal){
    std::vector<int> input = {2,7,11,15};
    ASSERT_THAT(twoSum(input,9), ElementsAreArray({0,1}));
}
TEST(TwoSumBruteForce, twoZeros){
    std::vector<int> input = {0,4,3,0};
    ASSERT_THAT(twoSum(input,0), ElementsAreArray({0,3}));
}
TEST(TwoSumBruteForce, last){
    std::vector<int> input = {3,2,4};
    ASSERT_THAT(twoSum(input,6), ElementsAreArray({1,2}));
}

/*  ################################################################
 *              IMPLEMENTATION USING HASHTABLE
 *  ################################################################
*/

TEST(twoSumHashTable, normal){
    std::vector<int> input = {2,7,11,15};
    ASSERT_THAT(twoSumHashTable(input,9), ElementsAreArray({0,1}));
}
TEST(twoSumHashTable, twoZeros){
    std::vector<int> input = {0,4,3,0};
    ASSERT_THAT(twoSumHashTable(input,0), ElementsAreArray({0,3}));
}
TEST(twoSumHashTable, last){
    std::vector<int> input = {3,2,4};
    ASSERT_THAT(twoSumHashTable(input,6), ElementsAreArray({1,2}));
}


