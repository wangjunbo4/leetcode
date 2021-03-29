/*
 * @Author: Gtylcara.
 * @Date: 2021-03-24 20:58:31
 * @LastEditors: Gtylcara.
 * @LastEditTime: 2021-03-24 21:05:57
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int minCostClimbingStairs(vector<int> &cost)
{
    int dp[cost.size() + 1];
    dp[0] = 0;
    dp[1] = 0;

    for (int i = 2; i <= cost.size(); i++)
    {
        dp[i] = min((dp[i - 1] + cost[i - 1]), (dp[i - 2] + cost[i - 2]));
    }
    return dp[cost.size()];
}