/*
 * @Author: Gtylcara.
 * @Date: 2021-04-14 20:18:49
 * @LastEditors: Gtylcara.
 * @LastEditTime: 2021-05-25 11:11:31
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <array>

using namespace std;

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                int temp = matrix[i + 1][j];
                if (j > 0)
                    temp = min(matrix[i + 1][j - 1], temp);
                if (j < n - 1)
                    temp = min(matrix[i + 1][j + 1], temp);
                matrix[i][j] += temp;
            }
        }
        int ans = 9999999;
        for (auto i : matrix[0])
        {
            ans = min(ans, i);
        }
        return ans;
    }
};
