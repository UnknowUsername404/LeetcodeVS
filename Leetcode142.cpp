#include <unordered_set>
using namespace std;

/*
���������ֽⷨ�������ⷨ�����ù�ϣ������Ϊ����ָ��
*/



//��ϣ��ⷨ��ʹ��Set��¼�Ѿ��������Ľڵ㣬������ظ��ģ���Ϊ���
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