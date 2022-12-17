#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


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
                ++len;
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
                    --len;
                }

                if (cnt == cnt_t) {
                    if (len < minLen) {
                        minLen = len;
                        minLeft = left;
                        minRight = right;
                    }
                }
            }
        }
        if (cnt == cnt_t)
            return s.substr(left, right - left + 1);
        else return "";

    }
};

/* 
这个子串是和顺序有关的！
输入：
"cabwefgewcwaefgcf"
"cae"
输出：
"aefgc"
预期
"cwae"
*/