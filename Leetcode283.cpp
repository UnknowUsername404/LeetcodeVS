#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int length = nums.size();
        int left = 0;
        int right = 0;

        while (right < length) {
            if (nums[right] == 0) {
                right++;
            }
            else {
                nums[left++] = nums[right++];
            }
        }
        while (left < length) {
            nums[left++] = 0;
        }

    }
};