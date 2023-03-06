#include <vector>
#include <algorithm>

using namespace std;

/*
���ڲ��ܰ����ظ�Ԫ�أ�ʹ�ù�ϣ��ʵ��ʱ�����ٸ��ӵ�ȥ�����⡣
�������˫ָ�뷨��

˫ָ�뷨��Ҫ��ԭ����������򣬱���û��Ҫ�󷵻��±꣬���Կ���ʹ�á�����֮���ǵ���������Ҫ�����±꣬�����޷�ʹ�á�

1�����Ƚ���������
2��ʹ��i�ӵ�һ��Ԫ�ؿ�ʼ������ʹ��left=i+1��right=nums.size - 1���������Ԫ��
3��nums[i] + nums[left] + nums[right] С��target������left������target������right
4����Ҫ����ȥ�أ�������һ�����⣬���ж� nums[i] �� nums[i + 1]�Ƿ���ͬ�������ж� nums[i] �� nums[i-1] �Ƿ���ͬ��
����ǰһ�ַ�ʽ�����һЩ���⣨����������¼��������ȥ��˳��������ǱȽ�ͨ�õġ�
*/

//�ڴ���������

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size() - 2; ++i) {
            //��֦��������һ����������С�ģ����nums[i]>0��ô����֮�Ͳ����ܵ���0
            if (nums[i] > 0) break;

            if (i > 0 && nums[i] == nums[i - 1]) continue;//��iȥ��
            int right = nums.size() - 1;
            int left = i + 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum > 0) {
                    --right;//���ﲻ��ר��ȥ��
                }
                else if (sum < 0) {
                    ++left;
                }
                else {
                    //vector<int> temp{nums[i],nums[left],nums[right]};//ʹ�����ַ����������2MB�ڴ�
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