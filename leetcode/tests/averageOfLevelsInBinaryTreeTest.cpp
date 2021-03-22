#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "averageOfLevelsInBinaryTreeTest.hpp"
#include "vector"

using namespace testing;

struct AverageOfLevelsInBinaryTreeFixture: public ::testing::Test {
    static void SetUpTestSuite(){
        std::cout << "\033[1;31m";
    }

    static void TearDownTestSuite(){}
    void SetUp(){}
    void TearDown(){}
    Solution s_;
};

TEST_F(AverageOfLevelsInBinaryTreeFixture, handleNormal){
    Node* root = new Node(3, new Node(9), new Node(20));
    root->right->left = new Node(15);
    root->right->right = new Node(7);
    ASSERT_THAT(s_.averageOfLevelsInBinaryTreeTwoQueues(root), ElementsAreArray<double>({3,14.5,11}));
    free(root);
}
TEST_F(AverageOfLevelsInBinaryTreeFixture, handleNullRoot){
    Node *root = nullptr;
    ASSERT_THAT(s_.averageOfLevelsInBinaryTreeTwoQueues(root),ElementsAreArray<double>({}));
}

TEST_F(AverageOfLevelsInBinaryTreeFixture, nullRoot){
    Node *root = nullptr;
    ASSERT_THAT(s_.averageOfLevelsInBinaryTreeSingleQueue(root),ElementsAreArray<double>({}));
}