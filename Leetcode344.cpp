#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;

        while (right >= left) {
            swap(s[left++], s[right--]);

            //可以通过异或的方式实现两个变量交换值而不使用临时变量
        }
    }
};