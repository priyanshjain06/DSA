// REVIEW Recursion only — Time: O(2^n), Space: O(n)
#include <vector>
#include <iostream>
int climbStairs(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2; // base case: 2 ways to climb 2 steps

    int left = climbStairs(n - 1);
    int right = climbStairs(n - 2);

    return left + right;
}

// Memorization :  TIme Complexity : O(n) and Space Complexity : O(n)

class Solution
{
public:
    int solve(int n, vector<int> &dp)
    {
        if (n <= 1)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }

    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};

// Tabulation : Time Complexity : O(n) and Space Complexity : O(n)

using namespace std;

int main()
{

    int n = 3;
    vector<int> dp(n + 1, -1);

    dp[0] = 1; //REVIEW - 
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n];
    return 0;
}

// REVIEW Space Optimization : TIme Complexity : O(n) and Space Complexity : O(1)

using namespace std;

int main()
{

    int n = 3;

    int prev2 = 1;
    int prev = 1;

    for (int i = 2; i <= n; i++)
    {
        int cur_i = prev2 + prev;
        prev2 = prev;
        prev = cur_i;
    }
    cout << prev;
    return 0;
}