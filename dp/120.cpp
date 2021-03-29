/*
 * @Author: Gtylcara.
 * @Date: 2021-03-29 20:18:13
 * @LastEditors: Gtylcara.
 * @LastEditTime: 2021-03-29 20:18:24
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <array>

using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int m = triangle.size();
        int n = triangle[m - 1].size();

        vector<vector<int>> dp(m, vector<int>(n));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                if (j == 0)
                {
                    if (i > 0)
                        dp[i][j] = dp[i - 1][j] + triangle[i][j];
                    else if (i == 0)
                        dp[i][j] = triangle[i][j];
                }
                else if (j == triangle[i].size() - 1)
                {
                    if (i > 0)
                        dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                    else if (i == 0)
                        dp[i][j] = triangle[i][j];
                }
                else
                {
                    if (i > 0)
                        dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
                    else if (i == 0)
                        dp[i][j] = triangle[i][j];
                }
            }
        }
        int res = INT_MAX;
        for (auto i : dp[m - 1])
        {
            res = min(res, i);
        }
        return res;
    }
};