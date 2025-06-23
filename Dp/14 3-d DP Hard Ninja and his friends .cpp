// REVIEW - Recurssion
// Time : O(3^N* 3^N) and Space Complexity : O(N*N)+ O(n)
#include <iostream>
#include <vector>
using namespace std;

int maxChocoUtil(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid)
{
    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        return -1e9;

    if (i == n - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }

    int maxi = INT_MIN;
    for (int di = -1; di <= 1; di++)
    {
        for (int dj = -1; dj <= 1; dj++)
        {
            int ans;
            if (j1 == j2)
                ans = grid[i][j1] + maxChocoUtil(i + 1, j1 + di, j2 + dj, n, m, grid);
            else
                ans = grid[i][j1] + grid[i][j2] + maxChocoUtil(i + 1, j1 + di, j2 + dj, n, m, grid);
            maxi = max(maxi, ans);
        }
    }

    return maxi;
}

int maximumChocolates(int n, int m, vector<vector<int>> &grid)
{
    return maxChocoUtil(0, 0, m - 1, n, m, grid);
}

// REVIEW Memorization:
// Time :O(N*M*M) * 9 and Space Complexity : O(N) + O(N*M*M)

int maxChocoUtil(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        return -1e9;

    if (i == n - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }

    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    int maxi = INT_MIN;
    for (int di = -1; di <= 1; di++)
    {
        for (int dj = -1; dj <= 1; dj++)
        {
            int ans;
            if (j1 == j2)
                ans = grid[i][j1] + maxChocoUtil(i + 1, j1 + di, j2 + dj, n, m, grid, dp);
            else
                ans = grid[i][j1] + grid[i][j2] + maxChocoUtil(i + 1, j1 + di, j2 + dj, n, m, grid, dp);
            maxi = max(maxi, ans);
        }
    }

    return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int n, int m, vector<vector<int>> &grid)
{
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    return maxChocoUtil(0, 0, m - 1, n, m, grid, dp);
}

// REVIEW Tabulization :
// Time :  O(N*M*M)*9 and Space : O(N*M*M)

int maximumChocolates(int n, int m, vector<vector<int>> &grid)
{
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
                dp[n - 1][j1][j2] = grid[n - 1][j1];
            else
                dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int maxi = INT_MIN;

                for (int di = -1; di <= 1; di++)
                {
                    for (int dj = -1; dj <= 1; dj++)
                    {
                        int ans;

                        if (j1 == j2)
                            ans = grid[i][j1];
                        else
                            ans = grid[i][j1] + grid[i][j2];

                        if ((j1 + di < 0 || j1 + di >= m) || (j2 + dj < 0 || j2 + dj >= m))
                            ans += -1e9;
                        else
                            ans += dp[i + 1][j1 + di][j2 + dj];

                        maxi = max(ans, maxi);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }

    return dp[0][0][m - 1];
}

// REVIEW -  space optimization
// NOTE -  Use a 2d  dp array is used here since it it is 3d dp
//  Time : O(N*M*M)*9 and Space : O(M*M)

int maximumChocolates(int n, int m, vector<vector<int>> &grid)
{
    vector<vector<int>> front(m, vector<int>(m, 0));
    vector<vector<int>> cur(m, vector<int>(m, 0));

    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
                front[j1][j2] = grid[n - 1][j1];
            else
                front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int maxi = INT_MIN;
                for (int di = -1; di <= 1; di++)
                {
                    for (int dj = -1; dj <= 1; dj++)
                    {
                        int ans;
                        if (j1 == j2)
                            ans = grid[i][j1];
                        else
                            ans = grid[i][j1] + grid[i][j2];

                        if ((j1 + di < 0 || j1 + di >= m) || (j2 + dj < 0 || j2 + dj >= m))
                            ans += -1e9;
                        else
                            ans += front[j1 + di][j2 + dj];

                        maxi = max(ans, maxi);
                    }
                }
                cur[j1][j2] = maxi;
            }
        }
        front = cur;
    }

    return front[0][m - 1];
}
