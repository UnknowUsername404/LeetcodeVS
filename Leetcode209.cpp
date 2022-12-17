#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int sum = 0;
        int minLen = INT_MAX;
        while (right < nums.size()) {
            sum += nums[right];
            if (sum == target) {
                minLen = minLen > (right - left + 1) ? right - left + 1 : minLen;
                sum -= nums[left];
                ++left;
            }
            else if (sum < target) {
                ++right;
            }
            else {
                sum -= nums[left];
                ++left;
            }
        }
    }
};