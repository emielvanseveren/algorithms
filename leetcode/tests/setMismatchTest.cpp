#include "setMismatch.hpp"
#include "gmock/gmock.h"
#include "vector"

using namespace testing;

struct SetMismatchFixture: public ::testing::Test {
    static void SetUpTestSuite(){
        std::cout << "\033[1;31m"
        << "You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to "
           "some error, one of the numbers in s got duplicated to another number in the set, which results in repetition"
           "of one number and loss of another number."
           << std::endl
        << "You are given an integer array nums representing the data status of this set after the error." << std::endl;
    }
    static void TearDownTestSuite(){}
    void SetUp(){}
    void TearDown(){}
    Solution s_;
};

TEST_F(SetMismatchFixture, handleNumInMiddleMissing){
    std::vector<int> input = {1,2,2,4};
    ASSERT_THAT(s_.findErrorNums(input), ElementsAreArray({2,3}));
}

TEST_F(SetMismatchFixture, handleFirstNumDouble){
    std::vector<int> input = {1,1};
    ASSERT_THAT(s_.findErrorNums(input), ElementsAreArray({1,2}));
}

TEST_F(SetMismatchFixture, handleFirstNumberMissing){
    std::vector<int> input = {2,2};
    ASSERT_THAT(s_.findErrorNums(input), ElementsAreArray({2,1}));
}

TEST_F(SetMismatchFixture, handleUnorderedSet){
    std::vector<int> input = {1, 5, 3, 2, 2, 7, 6, 4, 8, 9};
    ASSERT_THAT(s_.findErrorNums(input), ElementsAreArray({2,10}));
}
