#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return vector<int>();
        int height = matrix.size();
        int width = matrix[0].size();

        vector<int> result(height * width, 0);
        int index = 0;
        int resInt = 0;
        for (int h = height, w = width; h > 0 && w > 0; h -= 2, w -= 2) {
            int t = index;
            int b = height - index - 1;
            int l = index;
            int r = width - index - 1;
            //cout << "h:" << h << " w:" << w << endl;
            //cout << t << " " << b << " " << r << " " << l << endl;

            if (h == 1 || w == 1) {
                if (h == 1 && w == 1) {
                    result[resInt] = matrix[t][l];
                }
                else if (h == 1) {
                    for (int i = 0; i <= w - 1; ++i) {
                        result[resInt++] = matrix[t][l + i];
                    }
                }
                else {
                    for (int i = 0; i <= h - 1; ++i) {
                        result[resInt++] = matrix[t + i][l];
                    }
                }
                return result;
            }

            for (int i = 0; i < w - 1; ++i) {
                result[resInt++] = matrix[t][l + i];
                //cout << index << " " <<  t << " " << l + i << endl;
            }
            for (int i = 0; i < h - 1; ++i) {
                result[resInt++] = matrix[t + i][r];
                //cout << index << " " << t + i << " " << r << endl;
            }
            for (int i = 0; i < w - 1; ++i) {
                result[resInt++] = matrix[b][r - i];
                //cout << index << " " << b << " " << r - i << endl;
            }
            for (int i = 0; i < h - 1; ++i) {
                result[resInt++] = matrix[b - i][l];
                //cout << index << " " << b - i << " " << l << endl;
            }
            
            ++index;
        }
        
        return result;
    }
    
};
/*

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> ans;
        if (matrix.empty()) return ans; //若数组为空，直接返回答案
        int u = 0; //赋值上下左右边界
        int d = matrix.size() - 1;
        int l = 0;
        int r = matrix[0].size() - 1;
        while (true)
        {
            for (int i = l; i <= r; ++i) ans.push_back(matrix[u][i]); //向右移动直到最右
            if (++u > d) break; //重新设定上边界，若上边界大于下边界，则遍历遍历完成，下同
            for (int i = u; i <= d; ++i) ans.push_back(matrix[i][r]); //向下
            if (--r < l) break; //重新设定有边界
            for (int i = r; i >= l; --i) ans.push_back(matrix[d][i]); //向左
            if (--d < u) break; //重新设定下边界
            for (int i = d; i >= u; --i) ans.push_back(matrix[i][l]); //向上
            if (++l > r) break; //重新设定左边界
        }
        return ans;
    }
};

*/


