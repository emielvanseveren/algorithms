#ifndef AVERAGE_OF_LEVELS_IN_BINARYTREE_HPP
#define AVERAGE_OF_LEVELS_IN_BINARYTREE_HPP

#include "vector"

struct Node {
    int val;
    Node *left;
    Node *right;
    Node(): val(0), left(nullptr), right(nullptr){}
    Node(int x): val(x), left(nullptr), right(nullptr){}
    Node(int x, Node *left, Node *right): val(x), left(left), right(right){}
};

std::vector<double> averageOfLevelsInBinaryTreeTwoQueues(Node* root);
std::vector<double> averageOfLevelsInBinaryTreeSingleQueue(Node* root);

#endif
