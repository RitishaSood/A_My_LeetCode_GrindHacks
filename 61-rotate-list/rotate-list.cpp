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
    ListNode* rotateRight(ListNode* head, int k) {
        // Edge cases
        if (!head || !head->next || k == 0)
            return head;
        // Step 1-Find length and tail
        int length = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail =tail->next;
            length++;
        }
        //Normalize k
        k = k % length;
        if (k ==0)
            return head;
        //Make the list circular
        tail->next= head;
        //Find new tail (length - k - 1)
        ListNode* newTail = head;
        for (int i= 0; i < length - k- 1; i++) {
            newTail = newTail->next;
        }
        // Step 5: Break the circle
        ListNode* newHead= newTail->next;
        newTail->next =nullptr;
        return newHead;
    }
};
