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
    ListNode* reverseLL(ListNode* head){
        if (head == nullptr) return head;
        ListNode* prv = nullptr;
        ListNode* front = head->next;
        ListNode* node = head;
        while (front){
            node->next = prv;
            prv = node;
            node = front;
            front = front->next;
        }
        node->next = prv;
        prv = node;
        return prv;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* node = head;
        ListNode* prv = nullptr;
        int ctr = 1;
        while (node){
            if (ctr == k){
                ListNode* nxt = node->next;
                node->next = nullptr;
                ListNode* new_head = reverseLL(temp);
                if (temp == head) head = new_head;
                if (prv) prv->next = new_head;
                prv = temp;
                temp = nxt;
                node = nxt;
                ctr = 1;
            }
            if (node == nullptr) break;
            node = node->next;
            ctr++;
        }
        prv->next = temp;
        return head;
    }
};