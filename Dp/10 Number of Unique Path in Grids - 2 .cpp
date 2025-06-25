// REVIEW Memorization :
#include <iostream>
#include <vector>
using namespace std;

int mazeObstaclesUtil(int i, int j, vector<vector<int>> &maze, vector<vector<int>> &dp)
{
    // Base cases
    if (i > 0 && j > 0 && maze[i][j] == -1) // SECTION - -1 is blocked cell
        return 0;
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int up = mazeObstaclesUtil(i - 1, j, maze, dp);
    int left = mazeObstaclesUtil(i, j - 1, maze, dp);

    return dp[i][j] = up + left;
}

int mazeObstacles(int n, int m, vector<vector<int>> &maze)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return mazeObstaclesUtil(n - 1, m - 1, maze, dp);
}

// REVIEW Tabulation :
//! SECTION

int mazeObstaclesUtil(int n, int m, vector<vector<int>> &maze, vector<vector<int>> &dp)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (i > 0 && j > 0 && maze[i][j] == -1) // SECTION -
            {
                dp[i][j] = 0;
                continue;
            }
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
                continue;
            }

            int up = 0;
            int left = 0;

            if (i > 0)
                up = dp[i - 1][j];
            if (j > 0)
                left = dp[i][j - 1];

            dp[i][j] = up + left;
        }
    }

    return dp[n - 1][m - 1];
}

// REVIEW Space Optimization

using namespace std;

int mazeObstacles(int n, int m, vector<vector<int>> &maze)
{
    vector<int> prev(m, 0); // SECTION column size jitna
    for (int i = 0; i < n; i++)
    {
        vector<int> temp(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (i > 0 && j > 0 && maze[i][j] == -1)
            // SECTION -  for leetcode no need to check i and j here >0
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
            temp[j] = up + left;
        }
        prev = temp;
    }

    return prev[m - 1];
}
