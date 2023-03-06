#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/*
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> map_t;
        unordered_map<char, int> map;
        int cnt_t = 0;
        for (int i = 0; i < t.size(); ++i) {
            ++map_t[t[i]];
            map[t[i]] = 0;
            ++cnt_t;
        }
        
        int cnt = 0;
        int left = 0;
        int right = 0;
        int len = 0;
        int minLen = s.size();
        int minLeft = 0;
        int minRight = s.size() - 1;
        for (; right < s.size(); ++right) {
            auto it = map_t.find(s[right]);
            if (it != map_t.end()) {
                if (map[s[right]] < map_t[s[right]]) { 
                    ++cnt;
                }
                ++map[s[right]];

                while (cnt >= cnt_t) {
                    auto it = map.find(s[left]);
                    if (it != map.end()) {
                        if (map[s[left]] > map_t[s[left]]) {
                            --map[s[left]];
                        }
                        else {
                            break;
                        }
                    }
                    ++left;
                }

                if (cnt == cnt_t) {
                    len = right - left + 1;
                    //cout << left << " " << right << " len:" << len  << " minLen" << minLen << endl;
                    
                    if (len < minLen) {
                        minLen = len;
                        minLeft = left;
                        minRight = right;
                    }
                }
            }
        }
        //cout << left << " " << right << " " << len << " " << minLen << endl;
        if (cnt == cnt_t)
            return s.substr(minLeft, minRight - minLeft + 1);
        else return "";

    }
};

*/

/*
���们�����ڵ���Ŀ
1��ʹ����������i,j��ʾ���ڵ������߽硣
2��ʹ�ù�ϣ���¼�����ַ����������ͬʱʹ��һ������total��¼�ַ��ܸ�����
3�����Ƚ��б߽�j�����ƶ���ֱ����������Ŀ���ַ���Ȼ���ƶ�i��ֱ��һ��ȥ���󼴲������������ַ�����ϣ��ֵ==0������ʱ�Ĵ��ڼ�һ����ѡ��С���ڡ�
4����ϣ���е�ֵ�������ʾ����Ҫx�����ַ���С�������ʾ��-x������ĸ��ַ�������ϣ���е�ֵ�������ҵ�ǰ�¼�����ַ�Ϊ���ַ�ʱ��total��1������ϣ���е�ֵ���ڵ������ҵ�ǰ�뿪���ڵ��ַ�Ϊ���ַ�ʱ��total+1

�̶��������ڼ�438��
*/

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        int total = 0;
        for (char it : t) {
            ++need[it];
            ++total;
        }
        int left = 0, right = s.size() + 1;
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (need.find(s[i]) != need.end()) {
                need[s[i]]--;
                if (need[s[i]] >= 0) {
                    total--;
                }
                if (total == 0) {
                    while (need.find(s[j]) == need.end()|| (need.find(s[j]) != need.end() && need[s[j]] < 0)) {
                        if(need.find(s[j]) == need.end()){
                            j++;
                        }else{
                            need[s[j]]++;
                            j++;
                        }
                       
                    }
                    if (i - j < right - left) {
                        right = i;
                        left = j;
                    }
                }
            }
            
            
         
        }
        return right == s.size() + 1 ? "" :s.substr(left, right - left + 1);
    }
};