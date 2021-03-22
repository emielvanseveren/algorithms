#include "addOneRowToTree.hpp"

TreeNode* Solution::addOneRow(TreeNode *root, int v, int d){
    if(d==1){
        return new TreeNode(v,root, nullptr);
    } if(d==2){
        root->left = new TreeNode(v, root->left, nullptr);
        root->right = new TreeNode(v, nullptr, root->right);
    }
    else {
        if(root->left) addOneRow(root->left, v, d-1);
        if(root->right) addOneRow(root->right, v, d-1);
    }
    return root;
}
