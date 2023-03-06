#include <iostream>
#include <vector>
using namespace std;

/*
（1）基础解法:
由于只包含小写字母，可以使用数组来作为哈希表。
使用两个哈希表，分别记录s、t字符串中各字符出现的次数。然后对比，如果数量都一样则为异位词

优化：
首先比较s、t的长度，长度不一致则肯定不为异位词。
使用一个哈希表，s加t减，最后哈希表中的数字都为0则表示s、t为异位词。


（2）进阶--包含unicode字符
*/



class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> num_s(26, 0);
        vector<int> num_t(26, 0);

        for (char it : s) {
            num_s[it - 'a']++;
        }

        for (char it : t) {
            num_t[it - 'a']++;
        }

        for (int i = 0; i < 26; ++i) {
            if (num_s[i] != num_t[i]) return false;
        }
        return true;
    }
};