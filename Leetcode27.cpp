#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length = nums.size();
        int left = 0;
        int right = 0;

        while (right < length) {
            if (nums[right] == val) {
                right++;
            }
            else {
                nums[left++] = nums[right++];
            }
        }
        return left;

    }
    
};