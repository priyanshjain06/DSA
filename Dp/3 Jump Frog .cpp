// REVIEW Recurssion : Time: n^2 and Space Complexity :  n

#include <vector>
#include <climits>
#include <iostream>
using namespace std;

int frogJump(int i, vector<int> &height)
{
    if (i == 0)
        return 0;

    int jumpOne = frogJump(i - 1, height) + abs(height[i] - height[i - 1]);

    int jumpTwo = INT_MAX;
    if (i > 1)
        jumpTwo = frogJump(i - 2, height) + abs(height[i] - height[i - 2]);

    return min(jumpOne, jumpTwo);
}

// REVIEW - memoization : Time: n and Space Complexity :  n

using namespace std;

int solve(int ind, vector<int> &height, vector<int> &dp)
{
    if (ind == 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int jumpTwo = INT_MAX;
    int jumpOne = solve(ind - 1, height, dp) + abs(height[ind] - height[ind - 1]);
    if (ind > 1)
        jumpTwo = solve(ind - 2, height, dp) + abs(height[ind] - height[ind - 2]);

    return dp[ind] = min(jumpOne, jumpTwo);
}

// REVIEW Tabulation : Time: n and Space Complexity :  n

int main()
{

    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    vector<int> dp(n, -1);
    dp[0] = 0; //REVIEW - 
    for (int ind = 1; ind < n; ind++)
    {
        int jumpTwo = INT_MAX;
        int jumpOne = dp[ind - 1] + abs(height[ind] - height[ind - 1]);
        if (ind > 1)
            jumpTwo = dp[ind - 2] + abs(height[ind] - height[ind - 2]);

        dp[ind] = min(jumpOne, jumpTwo);
    }
    cout << dp[n - 1];
}

// REVIEW -  space optimization : Time: n and Space Complexity :  1

int main()
{

    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    int prev = 0;
    int prev2 = 0;
    for (int i = 1; i < n; i++)
    {

        int jumpTwo = INT_MAX;
        int jumpOne = prev + abs(height[i] - height[i - 1]);
        if (i > 1)
            jumpTwo = prev2 + abs(height[i] - height[i - 2]);

        int cur_i = min(jumpOne, jumpTwo);
        prev2 = prev;
        prev = cur_i;
    }
    cout << prev;
}