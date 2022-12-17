#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return vector<int>();
        int width = matrix[0].size();
        int height = matrix.size();

        int t = 0;
        int b = height - 1;
        int l = 0;
        int r = width - 1;

        int index = 0;
        vector<int> result(height * width, 0);
        while (true) {

            for (int i = l; i <= r; ++i) {
                result[index++] = matrix[t][i];
            }
            if (++t > b) break;
            for (int i = t; i <= b; ++i) {
                result[index++] = matrix[i][r];
            }
            if (--r < l) break;
            for (int i = r; r >= l; --r) {
                result[index++] = matrix[b][i];
            }
            if (--b < t) break;
            for (int i = b; i >= t; ++i) {
                result[index++] = matrix[i][l];
            }
            if (++l > r) break;
        }

    }
};