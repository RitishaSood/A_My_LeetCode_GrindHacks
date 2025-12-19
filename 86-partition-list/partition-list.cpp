/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // Dummy heads for two lists
        ListNode* smallDummy = new ListNode(0);
        ListNode* largeDummy = new ListNode(0);
        ListNode* small = smallDummy;
        ListNode* large = largeDummy;
        // Traverse original list
        while (head != nullptr) {
            if (head->val < x) {
                small->next = head;
                small = small->next;
            } else {
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }
        // Important: end large list
        large->next = nullptr;
        // Connect small list with large list
        small->next = largeDummy->next;
        // New head
        return smallDummy->next;
    }
};
