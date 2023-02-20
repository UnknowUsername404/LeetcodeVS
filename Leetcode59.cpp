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
            if (i == 1) {
                result[t][l] = num;
                cout << result[t][l] << endl;
                return result;
            }
            for (int j = 0; j < i - 1; ++j) {

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

/*

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int length = pow(n, 2);
        vector< vector<int>> matrix(n, vector<int>(n, 0));
        vector< vector<int>> directions = { {0, 1},{1 , 0},{0 , -1},{-1, 0} };
        int direction = 0;
        int x = 0, y = 0;
        for (int i = 1; i <= length; i++) {
            if (matrix[x][y] != 0) return matrix;
            matrix[x][y] = i;
            if (x + directions[direction][0] >= n || x + directions[direction][0] < 0 || y + directions[direction][1] >= n || y + directions[direction][1] < 0 || matrix[x + directions[direction][0]][y + directions[direction][1]] != 0) {
                direction = (direction + 1) % 4;
            }
            x += directions[direction][0];
            y += directions[direction][1];
        }
        return matrix;
    }
};

*/