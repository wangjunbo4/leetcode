/*
 * @Author: Gtylcara.
 * @Date: 2021-03-24 21:22:12
 * @LastEditors: Gtylcara.
 * @LastEditTime: 2021-03-24 21:57:42
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

int longestSubsequence(vector<int> &arr, int difference)
{
    int n = arr.size();
    map<int, int> m;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]] = max(m[arr[i] - difference] + 1, m[arr[i]]);
        m[arr[i]] = max(m[arr[i]], 1);
        ans = max(m[arr[i]], ans);
    }
    return ans;
}