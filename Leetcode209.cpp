#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = INT_MAX;
        int left = 0;
        int right = 0;
        int sum = 0;
        
        for (right = 0; right < nums.size(); ++right) {
            sum += nums[right];
            while(sum >= target){
                minLen = minLen < right - left + 1 ? minLen : right - left + 1;
                sum -= nums[left];
                ++left;
            }
        }

        return minLen == INT_MAX ? 0 : minLen;
    }
};