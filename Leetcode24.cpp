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
	ListNode* swapPairs(ListNode* head) {
		ListNode* h = new ListNode();
		h->next = head;
		head = h;
		while (h->next && h->next->next) {
			ListNode* first = h->next;
			ListNode* second = first->next;
			first->next = second->next;
			second->next = first;
			h->next = second;
			h = first;
		}
		return head->next;
	}
};