using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* h = new ListNode();
		while (head) {
			ListNode* temp = head;
			head = head->next;
			temp->next = h->next;
			h->next = temp;
		}
		return h->next;

	}
};