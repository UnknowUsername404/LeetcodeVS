using namespace std;

class MyLinkedList {

private:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
    };

    int length;
    ListNode* head;

public:
    MyLinkedList() {
        length = 0;
        head = new ListNode();
    }

    int get(int index) {
        if (index >= length) return -1;
        ListNode* temp = head;
        for (int i = 0; i <= index; ++i) {
            temp = temp->next;
        }
        return temp->val;
    }

    void addAtHead(int val) {
        ListNode* temp = new ListNode(val);
        temp->next = head->next;
        head->next = temp;
        ++length;
    }

    void addAtTail(int val) {
        ListNode* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        ListNode* tail = new ListNode(val);
        temp->next = tail;
        ++length;
    }

    void addAtIndex(int index, int val) {
        if (index >= length + 1) return;
        ListNode* newNode = new ListNode(val);
        ListNode* temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        ++length;
    }

    void deleteAtIndex(int index) {
        if (index >= length) return;
        ListNode* temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        ListNode* t = temp->next;
        temp->next = t->next;
        delete(t);
        --length;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */