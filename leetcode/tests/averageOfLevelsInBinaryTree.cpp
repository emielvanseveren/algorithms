#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "averageOfLevelsInBinaryTree.hpp"
#include "vector"

using namespace testing;

TEST(averageOfLevelsInBinaryTreeTwoQueues, normal){
    Node* root = new Node(3, new Node(9), new Node(20));
    root->right->left = new Node(15);
    root->right->right = new Node(7);
    ASSERT_THAT(averageOfLevelsInBinaryTreeTwoQueues(root), ElementsAreArray<double>({3,14.5,11}));
    free(root);
}
TEST(averageOfLevelsInBinaryTreeTwoQueues, nullRoot){
    Node *root = nullptr;
    ASSERT_THAT(averageOfLevelsInBinaryTreeTwoQueues(root),ElementsAreArray<double>({}));
}

TEST(averageOfLevelsInBinaryTreeSingleQueue, normal){
    Node* root = new Node(3, new Node(9), new Node(20));
    root->right->left = new Node(15);
    root->right->right = new Node(7);
    free(root);
}
TEST(averageOfLevelsInBinaryTreeSingleQueue, nullRoot){
    Node *root = nullptr;
    ASSERT_THAT(averageOfLevelsInBinaryTreeSingleQueue(root),ElementsAreArray<double>({}));
}