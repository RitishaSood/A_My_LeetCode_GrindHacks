class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode* toDelete = node->next;
        node->next = node->next->next;
        delete toDelete;
    }
};
