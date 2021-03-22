#include "gtest/gtest.h"
#include "addOneRowToTree.hpp"

struct AddOneRowToTreeFixture: public ::testing::Test {
    static void SetUpTestSuite(){
        std::cout << "\033[1;31m"
                  << "Given the root of a binary tree and two integers val and depth, add a row of nodes with value val"
                     "at the given depth depth";

        std::cout << "The adding rule is:"
                     "Given the integer depth, for each not null tree node cur at the depth depth - 1, create two tree "
                     "nodes with value val as cur's left subtree root and right subtree root. cur's original left subtree "
                     "should be the left subtree of the new left subtree root. cur's original right subtree should be "
                     "the right subtree of the new right subtree root. If depth == 1 that means there is no depth depth "
                     "- 1 at all, then create a tree node with value val as the new root of the whole original tree, and "
                     "the original tree is the new root's left subtree.";
    }
    static void TearDownTestSuite(){}
    void SetUp(){}
    void TearDown(){}
    Solution s_;
};

// TODO: Write tests
TEST_F(AddOneRowToTreeFixture, test1){}