#include <iostream>

using namespace std;



 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* current = head;
        ListNode* front = new ListNode();
        front->next = head;
        head = front;
        while (current) {
            if (current->val == val) {
                front->next = current->next;
                current = current->next;
            }
            else {
                front = front->next;
                current = current->next;
            }

        }
        return head->next;
    }
};