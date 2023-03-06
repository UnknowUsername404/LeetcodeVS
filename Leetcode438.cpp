#include <iostream>
#include <vector>
#include <array>

using namespace std;

/*
vectorʹ������������ΪԪ�ص�ʱ�򣬳��Ⱥ����ݶ���ȲŻ�ʹ==�ж�Ϊ�棻

���������˴����ǹ̶�����p.size()���ص㣬���ȸ���ʹ������ͳ��p.size��Ԫ�أ����������������ȣ�Ҳ������λ�ʡ�
Ȼ��ʼ�ƶ����ڣ�ÿ�ƶ�һ���ж�һ�Ρ�
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
���û������ڵķ���,���⻬�����ڵ��ص㣺���ڴ�С������Ҳ����ֱ�Ӳ���72��ķ���
����ʹ������72����ͬ�Ļ������ڲ���
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
            if (total == 0) {//û������ж� "aa""bb"�����
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