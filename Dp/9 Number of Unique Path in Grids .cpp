// REVIEW -  Recurssion :
//  Time : O(2^n) * k where k=  total number of subsets
//   and Space Complexity : O(k)*n

#include <iostream>
#include <vector>
using namespace std;

int countWaysUtil(int i, int j)
{
    if (i == 0 && j == 0)
        return 1;

    if (i < 0 || j < 0)
        return 0;

    int up = countWaysUtil(i - 1, j);
    int left = countWaysUtil(i, j - 1);

    return up + left;
}

int countWays(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));

    return countWaysUtil(m - 1, n - 1);
}

// REVIEW -  Memorization :
// TIME : O(m*n) and Space Complexity : O(m*n) + O(n-1 + m-1)

int countWaysUtil(int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return 1;

    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1) // SECTION -
        return dp[i][j];

    int up = countWaysUtil(i - 1, j, dp);
    int left = countWaysUtil(i, j - 1, dp);

    return dp[i][j] = up + left; // SECTION
}

int countWays(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));

    return countWaysUtil(m - 1, n - 1, dp);
}

// REVIEW Tabulization :
//  TIME : O(m*n) and Space Complexity : O(m*n)

int countWaysUtil(int m, int n, vector<vector<int>> &dp)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {

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

    return dp[m - 1][n - 1];
}

int countWays(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));

    return countWaysUtil(m, n, dp);
}

// REVIEW Space Optimization :
//  TIME : O(m*n) and Space Complexity : O(n)

int countWays(int m, int n)
{
    vector<int> prev(n, 0); //SECTION - 

    for (int i = 0; i < m; i++)
    {
        vector<int> temp(n, 0); //SECTION -  not a 2d array

        for (int j = 0; j < n; j++)
        {
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

            temp[j] = up + left; // SECTION -
        }

        prev = temp; // SECTION -
    }

    return prev[n - 1]; //SECTION - 
}
