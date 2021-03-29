/*
 * @Author: Gtylcara.
 * @Date: 2021-03-24 21:07:26
 * @LastEditors: Gtylcara.
 * @LastEditTime: 2021-03-24 21:21:20
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int tribonacci(int n)
{
    if (n < 2)
        return n;
    if (n < 3)
        return 1;
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    return dp[n];
}