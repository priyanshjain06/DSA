#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int totalWays(int n, int m, vector<vector<int>> &grid)
    {
        // Code here
        const int MOD = 1e9 + 7; // SECTION -
        vector<int> prev(m, 0);
        for (int i = 0; i < n; i++)
        {
            vector<int> temp(m, 0);
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                // SECTION -  for gfg no need to check i and j here >0
                {
                    temp[j] = 0;
                    continue;
                }
                if (i == 0 && j == 0)
                {
                    temp[j] = 1;
                    continue;
                }

                int up = 0;
                int left = 0;

                if (i > 0)
                    up = prev[j];
                if (j > 0)
                    left = temp[j - 1];
                temp[j] = (up + left) % MOD; // SECTION -
            }
            prev = temp;
        }

        return prev[m - 1];
    }
};