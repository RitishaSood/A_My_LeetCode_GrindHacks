class Solution {
public:
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // min-heap
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        // push first node of each list
        for (auto node : lists) {
            if (node != nullptr) pq.push(node);
        }

        ListNode dummy;
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* top = pq.top();
            pq.pop();

            tail->next = top;
            tail = tail->next;

            if (top->next != nullptr) {
                pq.push(top->next);
            }
        }

        return dummy.next;
    }
};
