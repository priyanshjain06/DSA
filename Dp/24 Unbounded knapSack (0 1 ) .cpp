// REVIEW - Recurssion
// Time : Exponential and Space Complexity : O(W)

#include <iostream>
#include <vector>
using namespace std;

// REVIEW -  Memorization
// Time Complexity :  O(N*W) and Space Complexity: O(N*W) + O(N)

int knapsackUtil(vector<int> &wt, vector<int> &val, int ind, int W, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        return (W / wt[0]) * val[0]; // SECTION -
    }

    if (dp[ind][W] != -1)
        return dp[ind][W];

    int notTaken = knapsackUtil(wt, val, ind - 1, W, dp); // SECTION - ind-1

    int taken = INT_MIN;
    if (wt[ind] <= W)
        taken = val[ind] + knapsackUtil(wt, val, ind, W - wt[ind], dp); // SECTION -  same index

    return dp[ind][W] = max(notTaken, taken);
}

// REVIEW Tabulation
//  Time : O(N*W) and Space Complexity : O(N*W)

int unboundedKnapsack(int n, int W, vector<int> &val, vector<int> &wt)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    for (int i = wt[0]; i <= W; i++)
    {
        dp[0][i] = (i / wt[0]) * val[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int cap = 0; cap <= W; cap++)
        {
            int notTaken = dp[ind - 1][cap];
            int taken = INT_MIN;
            if (wt[ind] <= cap)
                taken = val[ind] + dp[ind][cap - wt[ind]];
            dp[ind][cap] = max(notTaken, taken);
        }
    }

    return dp[n - 1][W];
}

// REVIEW Space Optimization
// NOTE using 1 array
//  Time : O(N*W) and Space Complexity : O(W)

int unboundedKnapsack(int n, int W, vector<int> &val, vector<int> &wt)
{
    vector<int> cur(W + 1, 0); // SECTION -  curr is prev here!

    for (int i = wt[0]; i <= W; i++)
    {
        cur[i] = (i / wt[0]) * val[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int cap = 0; cap <= W; cap++)
        {
            int notTaken = cur[cap];
            int taken = INT_MIN;
            if (wt[ind] <= cap)
                taken = val[ind] + cur[cap - wt[ind]];
            cur[cap] = max(notTaken, taken);
        }
    }

    return cur[W];
}

// REVIEW using 2 vector array

int unboundedKnapsack(int n, int W, vector<int> &val, vector<int> &wt)
{
    vector<int> prev(W + 1, 0), cur(W + 1, 0);

    for (int i = wt[0]; i <= W; i++)
    {
        prev[i] = (i / wt[0]) * val[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int cap = 0; cap <= W; cap++)
        {
            int notTaken = prev[cap];
            int taken = INT_MIN;
            if (wt[ind] <= cap)
                taken = val[ind] + cur[cap - wt[ind]];
            cur[cap] = max(notTaken, taken);
        }
        prev = cur;
    }

    return prev[W];
}
