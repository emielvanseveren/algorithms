#include "setMismatch.hpp"
#include "gmock/gmock.h"
#include "vector"

using namespace testing;

TEST(setMismatch, numInMiddleMissing){
    std::vector<int> input = {1,2,2,4};
    ASSERT_THAT(findErrorNums(input), ElementsAreArray({2,3}));
}

TEST(setMismatch, firstNumDouble){
    std::vector<int> input = {1,1};
    ASSERT_THAT(findErrorNums(input), ElementsAreArray({1,2}));
}

TEST(setMismatch, firstNumberMissing){
    std::vector<int> input = {2,2};
    ASSERT_THAT(findErrorNums(input), ElementsAreArray({2,1}));
}

TEST(setMismatch, unorderedSet){
    std::vector<int> input = {1, 5, 3, 2, 2, 7, 6, 4, 8, 9};
    ASSERT_THAT(findErrorNums(input), ElementsAreArray({2,10}));
}
