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


class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        int total = 0;
        for (char it : t) {
            ++need[it];
            ++total;
        }
        int left = 0, right = s.size() - 1;
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            
            if (need.find(s[i]) != need.end()) {
                while (need[s[i]] <= 0) {
                    if (need.find(s[j]) != need.end()) {
                        ++need[s[j]];
                        ++j;
                        ++total;
                    }
                }
                --need[s[i]];
                --total;
                if(total == 0 && i - j < right - left){
                    right = i;
                    left = j;
                }
                
            }
        }
        return s.substr(left, right - left + 1);
    }
};