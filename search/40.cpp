/*
 * @Author: Gtylcara.
 * @Date: 2021-05-26 08:10:18
 * @LastEditors: Gtylcara.
 * @LastEditTime: 2021-05-26 08:10:49
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <array>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> candidates;
    vector<int> saved;

    void dfs(int target, int index)
    {

        if (target == 0)
        {
            // sort(saved.begin(), saved.end());
            ans.push_back(saved);
            return;
        }

        for (int i = index; i < candidates.size() && target - candidates[i] >= 0; i++)
        {
            if (i > index && candidates[i] == candidates[i - 1])
                continue;
            saved.push_back(candidates[i]);
            dfs(target - candidates[i], i + 1);
            saved.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {

        this->candidates = candidates;
        sort(this->candidates.begin(), this->candidates.end());

        dfs(target, 0);

        // vector<vector<int>> v;
        // for (auto i : ans)
        //     v.push_back(i.first);
        return ans;
    }
};