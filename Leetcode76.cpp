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
经典滑动窗口的题目
1、使用两个变量i,j表示窗口的两个边界。
2、使用哈希表记录所需字符及其个数，同时使用一个变量total记录字符总个数。
3、首先将有边界j向右移动，直到包含所有目标字符。然后移动i，直到一个去掉后即不满足条件的字符（哈希表值==0），此时的窗口即一个候选最小窗口。
4、哈希表中的值大于零表示还需要x个该字符，小于零则表示有-x个多余的该字符。当哈希表中的值大于零且当前新加入的字符为该字符时，total减1。当哈希表中的值大于等于零且当前离开窗口的字符为该字符时，total+1

固定滑动窗口见438题
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