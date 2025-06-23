// REVIEW -  Tabulation :

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int minPathSum(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Initialize bottom row
        for (int j = 0; j < n; j++)
        {
            dp[n - 1][j] = triangle[n - 1][j];
        }

        // Bottom-up DP
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j <= i; j++)
            {
                int down = triangle[i][j] + dp[i + 1][j];     // SECTION -
                int diag = triangle[i][j] + dp[i + 1][j + 1]; // SECTION -
                dp[i][j] = min(down, diag);
            }
        }

        return dp[0][0];
    }
};
// REVIEW space Optimization

class Solution
{
public:
    int minPathSum(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<int> front(triangle[n - 1]); // SECTION copy the value  last row as base
        vector<int> cur(n, 0);

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j <= i; j++)
            {
                int down = triangle[i][j] + front[j];
                int diag = triangle[i][j] + front[j + 1];
                cur[j] = min(down, diag);
            }
            front = cur;
        }

        return front[0];
    }
};
