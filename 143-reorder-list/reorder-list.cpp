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
    void reorderList(ListNode* head) {
       ListNode *slow = head;
       ListNode *fast = head;
        //find the mid of list
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;  
        }
        //it separates second from first because prev->null
        ListNode *prev = NULL;
        ListNode *curr = slow->next;
        ListNode *next = NULL;
        //revers it
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        // now separate the first list 
        slow->next = NULL;

        ListNode *left = head;
        ListNode *right = prev;
        //reordering
        while(right!=NULL &&  left!=NULL){
            ListNode *t1 = left->next;
            ListNode *t2 = right->next;

            left->next = right;
            right->next = t1;

            left = t1;
            right = t2;
        }
    }
};