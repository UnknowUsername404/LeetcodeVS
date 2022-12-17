#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector< vector<int>> result(n, vector<int>(n, 0));
        int num = 1;
        for (int i = n; i > 0; i -= 2) {
            int temp = (n - i) / 2;
            int t = temp;
            int b = n - temp - 1;
            int l = temp;
            int r = n - temp - 1;
            cout << "i:" << i << endl;
            for (int j = 0; j < i - 1; ++j) {
                cout << "i:" << i << endl;
                if (i == 1) {
                    result[t][l] = num;
                    cout << result[t][l] << endl;
                    return result;
                }

                result[t][l + j] = num + j;
                result[t + j][r] = num + i - 1 + j;
                result[b][r - j] = num + 2 * (i - 1) + j;
                result[b - j][l] = num + 3 * (i - 1) + j;
            }
            num += 4 * (i - 1);
        }
        return result;
    }
};