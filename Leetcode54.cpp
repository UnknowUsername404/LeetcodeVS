#include <iostream>
#include <vector>

using namespace std;
/*
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

*/

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

/*
由于已经给出了矩阵，可以通过给遍历过的值赋INT_MAX的方式来表示此位置已经被遍历过，然后通过getNext方法获得下一个数字
getNext采用顺时针顺序查找元素，但是需要注意，右>下>左>上这种顺序会出现一个问题，当既可以向上也可以向右的时候会选择向右，需要特殊判断
*/

class Solution {
public:
    int getNext(vector<vector<int>>& matrix, int &x, int &y, int m, int n) {
        int res = INT_MAX;
        if (x + 1 < n && matrix[y][x + 1] != INT_MAX) {
            if (y - 1 >= 0 && matrix[y - 1][x] != INT_MAX) {//向右的时候如果也可以向上则向上走
                res = matrix[y - 1][x];
                matrix[y - 1][x] = INT_MAX;
                --y;
                return res;
            }
            res = matrix[y][x + 1];
            matrix[y][x + 1] = INT_MAX;
            ++x;
        }
        else if (y + 1 < m && matrix[y + 1][x] != INT_MAX) {
            res = matrix[y + 1][x];
            matrix[y + 1][x] = INT_MAX;
            ++y;
        }
        else if (x - 1 >= 0 && matrix[y][x - 1] != INT_MAX) {
            res = matrix[y][x - 1];
            matrix[y][x - 1] = INT_MAX;
            --x;
        }
        else if (y - 1 >= 0 && matrix[y - 1][x] != INT_MAX) {
            res = matrix[y - 1][x];
            matrix[y - 1][x] = INT_MAX;
            --y;
        }
        return res;
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int num = 1;
        int maxNum = n * m;
        vector<int> res;
        if(m == 0 || n == 0) return res;
        int x = 0;
        int y = 0;
        res.push_back(matrix[0][0]);
        matrix[0][0] = INT_MAX;
        
        while (true) {
            int temp = getNext(matrix, x, y, m, n);
            if (temp != INT_MAX) res.push_back(temp);
            else break;
        }
        return res;
    }
};