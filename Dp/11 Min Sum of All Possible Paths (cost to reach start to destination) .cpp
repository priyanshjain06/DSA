#include <vector>
using namespace std;

// REVIEW Recurssive Solution :
// TIME O(2^(m+n)) and Space : O(m+n)
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        return helper(m - 1, n - 1, grid);
    }

    int helper(int i, int j, vector<vector<int>> &grid)
    {
        if (i == 0 && j == 0)
            return grid[0][0]; // SECTION -
        if (i < 0 || j < 0)
            return INT_MAX; // SECTION -

        int up = helper(i - 1, j, grid);   // i-1, j
        int left = helper(i, j - 1, grid); // i,j-1

        return grid[i][j] + min(up, left); // SECTION
    }
};

// REVIEW -  Memorization
//  Time :  O(N*M) and Space :O((M-1)+(N-1)) + O(N*M)

int minSumPathUtil(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return matrix[0][0];
    if (i < 0 || j < 0)
        return INT_MAX;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = matrix[i][j] + minSumPathUtil(i - 1, j, matrix, dp);
    int left = matrix[i][j] + minSumPathUtil(i, j - 1, matrix, dp);

    return dp[i][j] = min(up, left);
}

int minSumPath(int n, int m, vector<vector<int>> &matrix)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return minSumPathUtil(n - 1, m - 1, matrix, dp);
}

// REVIEW Tabulation :
//  Time :  O(N*M) and Space :  O(N*M)

int minSumPath(int n, int m, vector<vector<int>> &matrix)
{
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = matrix[i][j];
            else
            {

                int up = matrix[i][j];
                if (i > 0)
                    up += dp[i - 1][j]; // SECTION -  compound operator
                else
                    up += 1e9; // SECTION -

                int left = matrix[i][j];
                if (j > 0)
                    left += dp[i][j - 1];
                else
                    left += 1e9;

                dp[i][j] = min(up, left);
            }
        }
    }

    return dp[n - 1][m - 1];
}

// REVIEW Space Optimization :
//   Time :  O(N*M) and Space :  O(M)

int minSumPath(int n, int m, vector<vector<int>> &matrix)
{
    vector<int> prev(m, 0); // SECTION -  column jitni size

    for (int i = 0; i < n; i++)
    {
        vector<int> temp(m, 0); // SECTION -
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                temp[j] = matrix[i][j];
            else
            {
                int up = matrix[i][j]; // SECTION - not 0
                if (i > 0)
                    up += prev[j];
                else // SECTION -
                    up += 1e9;

                int left = matrix[i][j];
                if (j > 0)
                    left += temp[j - 1];
                else
                    left += 1e9;

                temp[j] = min(up, left); // SECTION -
            }
        }
        prev = temp; //! SECTION
    }

    return prev[m - 1]; // SECTION -
}