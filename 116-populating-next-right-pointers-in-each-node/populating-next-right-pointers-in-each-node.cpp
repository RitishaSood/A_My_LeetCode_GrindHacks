/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        Node* leftmost = root;
        while (leftmost->left) {  // since it's a perfect binary tree
            Node* head = leftmost;
            while (head) {
                // Connect left child to right child
                head->left->next = head->right;
                // Connect right child to next node's left child
                if (head->next) {
                    head->right->next = head->next->left;
                }
                head = head->next;
            }
            // Move to the next level
            leftmost = leftmost->left;
        }
        return root;
    }
};
