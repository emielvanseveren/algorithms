#include "averageOfLevelsInBinaryTreeTest.hpp"
#include "vector"
#include "queue"
#include "cmath"

/* Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation: The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
*/

std::vector<double> averageOfLevelsInBinaryTreeTwoQueues(Node *root){
    std::vector<double> avg;
    if(root == nullptr){
        return avg;
    }
    std::queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        double sum = 0;
        int count = 0;
        std::queue<Node*> temp;
        while(!q.empty()){
            Node* n = q.front();
            q.pop();
            sum += n->val;
            count++;
            if (n->left != NULL)
                temp.push(n->left);
            if (n->right != NULL)
                temp.push(n->right);
        }
        q = temp;
        avg.push_back((sum*1.00/count / 1.00));
    }
    return avg;
}


// BETTER SOLUTION is to work with a single queue (found this by looking at the faster solutions).
std::vector<double> averageOfLevelsInBinaryTreeSingleQueue(Node *root){
    std::vector<double> avg;
    if(root == nullptr){
        return avg;
    }

    // setup
    std::queue<Node*> q;
    q.push(root);

    while(!q.empty()){
       int count = q.size(); // IMPORTANT: WE CAN USE THE QUEUE SIZE AS AMOUNT OF TIMES WE NEED TO LOOP TO GET COUNT OF BREADTH!!!!
       double sum = 0;
       for(int i=0; i<count;i++) {
           Node *n = q.front(); q.pop();
           if (n->left) q.push(n->left);
           if (n->right) q.push(n->right);
           sum += n->val;
       }
       avg.push_back((double)sum/count);
    }
    return avg;
}