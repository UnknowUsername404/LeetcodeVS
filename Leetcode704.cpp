#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int length = nums.size();
		if (length < 1) return 0;

		int right = length - 1;
		int left = 0;
		int mid = (right + left) / 2;
		while (right >= left) {
			if (nums[mid] == target) {
				return mid;
			}
			else if (target > nums[mid]) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
			mid = (right + left) / 2;
		}
		return -1;
	}
};