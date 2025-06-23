// REVIEW Recurssion :
// Time:  O(3^N*N) and Space Complexity : O(N*N)+ O(n)

#include <iostream>
#include <vector>
using namespace std;

int getMaxUtil(int i, int j, int m, vector<vector<int>> &matrix)
{
    if (j < 0 || j >= m)
        return -1e9;
    if (i == 0)
        return matrix[0][j];

    int up = matrix[i][j] + getMaxUtil(i - 1, j, m, matrix);
    int leftDiagonal = matrix[i][j] + getMaxUtil(i - 1, j - 1, m, matrix);
    int rightDiagonal = matrix[i][j] + getMaxUtil(i - 1, j + 1, m, matrix);

    return max(up, max(leftDiagonal, rightDiagonal));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int maxi = INT_MIN;

    for (int j = 0; j < m; j++)
    {
        int ans = getMaxUtil(n - 1, j, m, matrix);
        maxi = max(maxi, ans);
    }

    return maxi;
}

// REVIEW -  Memorization :
//  TIME : O(N*N) and Space Complexity : O(N) + O(N*M)

int getMaxUtil(int i, int j, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    if (j < 0 || j >= m)
        return -1e9;
    if (i == 0)
        return matrix[0][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = matrix[i][j] + getMaxUtil(i - 1, j, m, matrix, dp);
    int leftDiagonal = matrix[i][j] + getMaxUtil(i - 1, j - 1, m, matrix, dp);
    int rightDiagonal = matrix[i][j] + getMaxUtil(i - 1, j + 1, m, matrix, dp);

    return dp[i][j] = max(up, max(leftDiagonal, rightDiagonal));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    int maxi = INT_MIN;

    for (int j = 0; j < m; j++)
    {
        int ans = getMaxUtil(n - 1, j, m, matrix, dp);
        maxi = max(maxi, ans);
    }

    return maxi;
}

// REVIEW Tabulation
// Time :  O(N*M) and Space Complexity :O(N*M)

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int j = 0; j < m; j++)
    {
        dp[0][j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int up = matrix[i][j] + dp[i - 1][j];

            int leftDiagonal = matrix[i][j];
            if (j - 1 >= 0)
            {
                leftDiagonal += dp[i - 1][j - 1];
            }
            else
            {
                leftDiagonal += -1e9;
            }

            int rightDiagonal = matrix[i][j];
            if (j + 1 < m)
            {
                rightDiagonal += dp[i - 1][j + 1];
            }
            else
            {
                rightDiagonal += -1e9;
            }

            dp[i][j] = max(up, max(leftDiagonal, rightDiagonal));
        }
    }

    int maxi = INT_MIN; //SECTION - 
    for (int j = 0; j < m; j++)
    {
        maxi = max(maxi, dp[n - 1][j]);
    }

    return maxi;
}

// REVIEW  Space Optimization
// Time : O(N*M) and Space :O(M)

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    // vector<int> prev(m, 0);// SECTION if  we copy directly then dont declare it here if loop is used then it will work
    vector<int> cur(m, 0);

    vector<int> prev(matrix[0]);
    // SECTION or use a loop like previous question
    // SECTION -  initialize with first row

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int up = matrix[i][j] + prev[j];
            // SECTION cannot go out of bound

            int leftDiagonal = matrix[i][j];
            if (j - 1 >= 0)
            {
                leftDiagonal += prev[j - 1];
            }
            else
            {
                leftDiagonal += -1e9;
            }

            int rightDiagonal = matrix[i][j];
            if (j + 1 < m)
            {
                rightDiagonal += prev[j + 1];
            }
            else
            {
                rightDiagonal += -1e9;
            }

            cur[j] = max(up, max(leftDiagonal, rightDiagonal));
        }

        prev = cur;
    }

    int maxi = INT_MIN;
    for (int j = 0; j < m; j++)
    {
        maxi = max(maxi, prev[j]);
    }

    return maxi;
}
