#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map{};
        for (auto it : nums1) {
            map[it]++;
        }
        unordered_map<int, int> temp{};
        for (auto it : nums2) {
            if (map.find(it) != map.end()) {
                if (map[it] > 0) {
                    --map[it];
                    temp[it]++;
                }
            }
        }
        vector<int> result{};
        for (auto it : temp) {
            for (int i = 0; i < it.second; ++i) {
                result.push_back(it.first);
            }
        }
        return result;
    }
};