#include <iostream>
#include <vector>
#include <array>

using namespace std;

/*
vector使用内置类型作为元素的时候，长度和内容都相等才会使==判断为真；

这里利用了窗口是固定长度p.size()的特点，首先各自使用容器统计p.size个元素，如果这两个容器相等，也即是异位词。
然后开始移动窗口，每移动一格判断一次。
*/
/*
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.size(), pLen = p.size();

        if (sLen < pLen) {
            return vector<int>();
        }

        vector<int> ans;
        vector<int> sCount(26);
        vector<int> pCount(26);
        for (int i = 0; i < pLen; ++i) {
            ++sCount[s[i] - 'a'];
            ++pCount[p[i] - 'a'];
        }

        if (sCount == pCount) {
            ans.emplace_back(0);
        }

        for (int i = 0; i < sLen - pLen; ++i) {
            --sCount[s[i] - 'a'];
            ++sCount[s[i + pLen] - 'a'];

            if (sCount == pCount) {
                ans.emplace_back(i + 1);
            }
        }

        return ans;
    }
};
 */


/*
采用滑动窗口的方法,本题滑动窗口的特点：窗口大小定长。也可以直接采用72题的方法
这里使用了与72题相同的滑动窗口策略
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (s.size() < p.size()) return ans;

        vector<int> need(26, INT_MAX);
        int total = 0;
        for (char it : p) {
            if (need[it - 'a'] == INT_MAX) need[it - 'a'] = 0;
            ++need[it - 'a'];
            ++total;
        }

        int left = 0;
        for (int right = 0; right < s.size(); ++right) {
            if (need[s[right] - 'a'] != INT_MAX) {
                --need[s[right] - 'a'];
                total -= need[s[right] - 'a'] < 0 ? 0 : 1;
            }
            if (total == 0) {//没有这个判断 "aa""bb"会出错
                while (need[s[left] - 'a'] == INT_MAX || need[s[left] - 'a'] < 0) {
                    if (need[s[left] - 'a'] != INT_MAX) ++need[s[left] - 'a'];
                    ++left;
                }
                if (right - left + 1 == p.size()) {
                    ans.push_back(left);
                }
            }
            
            
        }
        return ans;
    }
};