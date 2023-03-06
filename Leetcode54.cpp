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
        if (matrix.empty()) return ans; //������Ϊ�գ�ֱ�ӷ��ش�
        int u = 0; //��ֵ�������ұ߽�
        int d = matrix.size() - 1;
        int l = 0;
        int r = matrix[0].size() - 1;
        while (true)
        {
            for (int i = l; i <= r; ++i) ans.push_back(matrix[u][i]); //�����ƶ�ֱ������
            if (++u > d) break; //�����趨�ϱ߽磬���ϱ߽�����±߽磬�����������ɣ���ͬ
            for (int i = u; i <= d; ++i) ans.push_back(matrix[i][r]); //����
            if (--r < l) break; //�����趨�б߽�
            for (int i = r; i >= l; --i) ans.push_back(matrix[d][i]); //����
            if (--d < u) break; //�����趨�±߽�
            for (int i = d; i >= u; --i) ans.push_back(matrix[i][l]); //����
            if (++l > r) break; //�����趨��߽�
        }
        return ans;
    }
};

*/

/*
�����Ѿ������˾��󣬿���ͨ������������ֵ��INT_MAX�ķ�ʽ����ʾ��λ���Ѿ�����������Ȼ��ͨ��getNext���������һ������
getNext����˳ʱ��˳�����Ԫ�أ�������Ҫע�⣬��>��>��>������˳������һ�����⣬���ȿ�������Ҳ�������ҵ�ʱ���ѡ�����ң���Ҫ�����ж�
*/

class Solution {
public:
    int getNext(vector<vector<int>>& matrix, int &x, int &y, int m, int n) {
        int res = INT_MAX;
        if (x + 1 < n && matrix[y][x + 1] != INT_MAX) {
            if (y - 1 >= 0 && matrix[y - 1][x] != INT_MAX) {//���ҵ�ʱ�����Ҳ����������������
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