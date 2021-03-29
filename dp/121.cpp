/*
 * @Author: Gtylcara.
 * @Date: 2021-03-24 22:20:45
 * @LastEditors: Gtylcara.
 * @LastEditTime: 2021-03-24 22:36:59
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <array>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    if (n < 2)
        return 0;
    int dp[n][2];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            dp[i][j] = 0;

    dp[0][0] = 0;
    dp[0][1] = -prices[0];

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = max(dp[i - 1][1], -prices[i]);
    }
    return dp[n - 1][0];
}