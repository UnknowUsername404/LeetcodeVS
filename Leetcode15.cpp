#include <vector>
#include <algorithm>

using namespace std;

/*
由于不能包含重复元素，使用哈希表实现时会面临复杂的去重问题。
这里采用双指针法。

双指针法需要对原数组进行排序，本题没有要求返回下标，所以可以使用。两数之和那道题由于需要返回下标，所以无法使用。

1、首先将数组排序
2、使用i从第一个元素开始遍历，使用left=i+1、right=nums.size - 1遍历后面的元素
3、nums[i] + nums[left] + nums[right] 小于target则右移left，大于target则左移right
4、需要进行去重，这里有一个问题，是判断 nums[i] 与 nums[i + 1]是否相同，还是判断 nums[i] 与 nums[i-1] 是否相同。
采用前一种方式会出现一些问题（见代码随想录），这种去重顺序的问题是比较通用的。
*/

//内存消耗问题

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size() - 2; ++i) {
            //减枝：排序后第一个数字是最小的，如果nums[i]>0那么三数之和不可能等于0
            if (nums[i] > 0) break;

            if (i > 0 && nums[i] == nums[i - 1]) continue;//对i去重
            int right = nums.size() - 1;
            int left = i + 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum > 0) {
                    --right;//这里不用专门去重
                }
                else if (sum < 0) {
                    ++left;
                }
                else {
                    //vector<int> temp{nums[i],nums[left],nums[right]};//使用这种方法会多消耗2MB内存
                    ans.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    --right;
                    ++left; 
                    while (left < right && nums[right] == nums[right + 1]) --right;
                    while (left < right&& nums[left] == nums[left - 1]) ++left;
                }
               
            }
        }
        return ans;
    }
};