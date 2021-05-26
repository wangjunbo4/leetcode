/*
 * @Author: Gtylcara.
 * @Date: 2021-04-14 19:21:00
 * @LastEditors: Gtylcara.
 * @LastEditTime: 2021-04-14 20:18:28
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <array>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        if(dungeon[m - 1][n - 1] > 0) dungeon[m - 1][n - 1] = 0;
        
        for (int i = m - 2; i >= 0; i--)
        {
            dungeon[i][n - 1] = dungeon[i + 1][n - 1] + dungeon[i][n - 1] > 0 ? 0 : dungeon[i + 1][n - 1] + dungeon[i][n - 1];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            dungeon[m - 1][i] = dungeon[m - 1][i + 1] + dungeon[m - 1][i] > 0 ? 0 : dungeon[m - 1][i + 1] + dungeon[m - 1][i];
        }

        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = n - 2; j >= 0; j--)
            {
                int h = max(dungeon[i][j + 1], dungeon[i + 1][j]);
                dungeon[i][j] = dungeon[i][j] + h > 0 ? 0 : dungeon[i][j] + h;
            }
        }

        return -dungeon[0][0] + 1;
    }
};