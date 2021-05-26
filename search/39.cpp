/*
 * @Author: Gtylcara.
 * @Date: 2021-05-25 14:08:51
 * @LastEditors: Gtylcara.
 * @LastEditTime: 2021-05-25 14:09:04
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <array>

using namespace std;

class Solution
{
public:
    void dfs(vector<int> &candidates, int target, int index, vector<int> &saved, vector<vector<int>> &ans)
    {
        if (index >= candidates.size())
            return;

        if (target == 0)
        {
            ans.push_back(saved);
            return;
        }

        dfs(candidates, target, index + 1, saved, ans);
        if (target - candidates[index] >= 0)
        {
            saved.push_back(candidates[index]);
            dfs(candidates, target - candidates[index], index, saved, ans);
            saved.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> saved;

        dfs(candidates, target, 0, saved, ans);

        return ans;
    }
};