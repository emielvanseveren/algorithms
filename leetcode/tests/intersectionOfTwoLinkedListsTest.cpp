#include "intersectionOfTwoLinkedLists.hpp"
#include "gtest/gtest.h"

struct IntersectionOfTwoLinkedListsFixture: public ::testing::Test {
    static void SetUpTestSuite(){
        std::cout << "\033[1;31m"
        << "Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect."
        << "If the two linked lists have no intersection at all, return null."
        // TODO: add explanation here
    }
    static void TearDownTestSuite(){}
    void SetUp(){}
    void TearDown(){}
    Solution s_;
};

TEST_F(IntersectionOfTwoLinkedListsFixture, test1){}