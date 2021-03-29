/*
 * @Author: Gtylcara.
 * @Date: 2021-03-24 22:36:19
 * @LastEditors: Gtylcara.
 * @LastEditTime: 2021-03-25 16:08:17
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <array>

using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int dp[m + 1][n + 1];

        for (int i = 0; i <= m; i++)
            for (int j = 0; j <= n; j++)
                dp[i][j] = 0;

        dp[0][1] = 1;

        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
            {
                if (obstacleGrid[i - 1][j - 1] == 0)
                {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                }
                else
                    dp[i][j] = 0;
            }
        return dp[m][n];
    }
};