#ifndef INTERSECTION_OF_TWO_LINKED_LISTS_HPP
#define INTERSECTION_OF_TWO_LINKED_LISTS_HPP


struct Node {
    int val;
    Node *next;
    Node (int x): val(x), next(nullptr){}
};

struct VisitedNode {
    int val;
    bool visited;
    VisitedNode *next;
    VisitedNode(int x): val(x), next(nullptr), visited(false){}
};

class Solution {
public:
    Node* getIntersectionNode(Node *headA, Node *headB);
    Node* getIntersectionNodeWithVisited(VisitedNode *headA, VisitedNode);
private:
    int getLength(Node *head);
};

#endif
