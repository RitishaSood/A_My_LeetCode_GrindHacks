class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node(int x) : val(x), next(nullptr) {}
    };

    Node* dummy;  // dummy head
    int size;

public:
    MyLinkedList() {
        dummy = new Node(0);
        size = 0;
    }
    
    int get(int index) {
        if (index < 0 || index >= size) return -1;

        Node* curr = dummy->next;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
        Node* node = new Node(val);
        node->next = dummy->next;
        dummy->next = node;
        size++;
    }
    
    void addAtTail(int val) {
        Node* curr = dummy;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = new Node(val);
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;

        Node* curr = dummy;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }

        Node* node = new Node(val);
        node->next = curr->next;
        curr->next = node;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;

        Node* curr = dummy;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }

        Node* toDelete = curr->next;
        curr->next = toDelete->next;
        delete toDelete;
        size--;
    }
};
