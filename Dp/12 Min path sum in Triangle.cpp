// REVIEW REcurssison
//  Time : O(2^n) and Space : O(n*n)+O(n*n)

#include <iostream>
#include <vector>
using namespace std;

int minimumPathSumUtil(int i, int j, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp)
{

    // SECTION here we start from 0 go to  till last row reverse of conventonal recurssion
    if (i == n - 1)
        return triangle[i][j];

    int down = triangle[i][j] + minimumPathSumUtil(i + 1, j, triangle, n, dp);
    int diagonal = triangle[i][j] + minimumPathSumUtil(i + 1, j + 1, triangle, n, dp); // SECTION -  for both we use Triangle[i][j]

    return min(down, diagonal);
}

int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return minimumPathSumUtil(0, 0, triangle, n, dp);
}

// REVIEW -
// MEMEORIZATION:
// TIME : O(n*n) and Space : O(n*n)+O(n*n)
int minimumPathSumUtil(int i, int j, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp)
{
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i == n - 1)
        return triangle[i][j];

    int down = triangle[i][j] + minimumPathSumUtil(i + 1, j, triangle, n, dp);
    int diagonal = triangle[i][j] + minimumPathSumUtil(i + 1, j + 1, triangle, n, dp);

    return dp[i][j] = min(down, diagonal);
}

int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return minimumPathSumUtil(0, 0, triangle, n, dp);
}

// REVIEW -  Space Optimization :
//  TIME : O(n*n) and Space : O(n*n)

int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // SECTION -  here we are starting from last row and go to 0the row
    // SECTION bottom to down instead of top to down (the conventional tabulation)
    // SECTION appraoch is reverse of recurssion (top to down ) so we take bottom to up

    for (int j = 0; j < n; j++) // last row
    {
        dp[n - 1][j] = triangle[n - 1][j];
    }

    // SECTION -  why two loops ? coz row number  =  elements (i.e no. of  columns) eg 1st row = 1 elmenent which is 1st column
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(down, diagonal);
        }
    }

    return dp[0][0];
}

// REVIEW space Optimization
// TIME : O(n*n) and Space : O(n)

int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<int> front(n, 0); // SECTION -

    for (int j = 0; j < n; j++)
    {
        front[j] = triangle[n - 1][j];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        vector<int> cur(n, 0); // SECTION -

        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + front[j];
            int diagonal = triangle[i][j] + front[j + 1];
            cur[j] = min(down, diagonal); // SECTION -
        }
        front = cur; // SECTION -
    }

    return front[0]; // SECTION -
}
