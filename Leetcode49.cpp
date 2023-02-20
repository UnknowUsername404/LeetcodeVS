#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>
#include <array>

using namespace std;


/*
class Solution {
public:
    bool jug(vector<vector<int>>& cnt, int i, int j) {
        for (int h = 0; h < cnt[i].size(); ++h) {
            if (cnt[i][h] != cnt[j][h]) return false;
        }
        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<int>> cnt;
        vector<bool> flg(strs.size(), true);
        for (auto it : strs) {
            vector<int> temp(26, 0);
            for (auto ch : it) {
                ++temp[ch - 'a'];
            }
            cnt.push_back(temp);
        }
        vector<vector<string>> result;
        for (int i = 0; i < strs.size(); ++i) {
            
            if (flg[i]) {
                vector<string> temp;
                temp.push_back(strs[i]);
                flg[i] = false;
                for (int j = i + 1; j < strs.size(); ++j) {
                    if (strs[j].size() != strs[i].size()) continue;
                    if (jug(cnt, i, j)) {
                        temp.push_back(strs[j]);
                        flg[j] = false;
                    }
                }
                result.push_back(temp);
            }

        }
        return result;
    }
};
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 自定义对 array<int, 26> 类型的哈希函数
        auto arrayHash = [fn = hash<int>{}](const array<int, 26>& arr)->size_t {
            return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
                return (acc << 1) ^ fn(num);
                });
        };

        unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);
        for (string& str : strs) {
            array<int, 26> counts{};
            int length = str.length();
            for (int i = 0; i < length; ++i) {
                counts[str[i] - 'a'] ++;
            }
            mp[counts].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};

//https://blog.csdn.net/y109y/article/details/82669620
//https://blog.nowcoder.net/n/7bf869602b73482fa1dcbe340ea8dc59