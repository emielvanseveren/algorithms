#include "intersectionOfTwoLinkedLists.hpp"
#include "algorithm"
#include "stdlib.h"

/*
 * METHOD 1: just 2 loops (which is n*m)
 * Too slow..
 */

/*  METHOD 2: visitedNodes (which is n+m)
 *  Although this could be an okay solution, Leetcode requires that the nodes must retain their original structure
 *  after the on function returns. Since we change visited flags, it is not ok.
*/
VisitedNode* Solution::getIntersectionNodeWithVisitedNode(VisitedNode *headA, VisitedNode *headB){
    while(headA->next){ // loop over first list and put visited flag on true.
        headA->visited = true;
    }

    while(headB->next){
         if(headB->visited){
             return headB;
         }
    }
    return nullptr; // means they don't intersect.
}

/* METHOD 3: difference in node counts
*/

Node* Solution::getIntersectionNode(Node *headA, Node *headB){

}
