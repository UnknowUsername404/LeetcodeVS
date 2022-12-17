#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        vector<int> cnt(fruits.size(), 0);
        int right = 0;
        int left = 0;
        int max = 0;
        int num = 0;
        for (; right < fruits.size(); ++right) {
            if (cnt[fruits[right]] == 0) {
                ++num; 
            }
            ++cnt[fruits[right]];
            while (num > 2) {
                --cnt[fruits[left]];
                if (cnt[fruits[left]] == 0) {
                    --num;
                }
                ++left;
            } 
            
            max = right - left + 1 > max ? right - left + 1 : max;
        }
        return max;
    }
};