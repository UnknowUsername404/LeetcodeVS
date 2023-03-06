#include <unordered_set>
using namespace std;

/*
本题有两种解法，基础解法即采用哈希表，进阶为快慢指针
*/



//哈希表解法，使用Set记录已经遍历过的节点，如果有重复的，即为入口
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        unordered_set<ListNode*> visited;

        while (head) {
            if (visited.count(head)) {
                return head;
            }
            visited.insert(head);
            head = head->next;
        }
        return head;
    }
};