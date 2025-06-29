// REVIEW Recurrsion
// Time : O(2^n) and Space : O(n)
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int solve(int index, int W, vector<int> &val, vector<int> &wt)
    {
        if (index == 0)
        {
            if (wt[0] <= W)
                return val[0];
            else
                return 0;
        }

        int notPick = solve(index - 1, W, val, wt);

        int pick = INT_MIN;
        if (wt[index] <= W)
            pick = val[index] + solve(index - 1, W - wt[index], val, wt);
        return max(pick, notPick);
    }
};

// REVIEW  Memorization
// Time : O(n * W) and Space : O(n * W)

class Solution
{
public:
    int solve(int index, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp)
    {
        if (index == 0)
        {
            if (wt[0] <= W)
                return val[0];
            else
                return 0;
        }

        if (dp[index][W] != -1)
            return dp[index][W];

        int notPick = solve(index - 1, W, val, wt, dp);

        int pick = INT_MIN;
        if (wt[index] <= W)
            pick = val[index] + solve(index - 1, W - wt[index], val, wt, dp);

        return dp[index][W] = max(pick, notPick);
    }
};

// REVIEW Tabulation
// Time : O(n * W) and Space : O(n * W)

class Solution
{
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, 0)); // SECTION - W+1

        for (int cap = wt[0]; cap <= W; ++cap) // SECTION -  till cap <= W
            dp[0][cap] = val[0];

        for (int i = 1; i < n; ++i)
        {
            for (int cap = 0; cap <= W; ++cap) // SECTION -  till <=W
            {
                int notPick = dp[i - 1][cap];
                int pick = INT_MIN;
                if (wt[i] <= cap)
                    pick = val[i] + dp[i - 1][cap - wt[i]];
                dp[i][cap] = max(pick, notPick);
            }
        }

        return dp[n - 1][W];
    }
};

// REVIEW space Optimization
// Time : and Space :

int knapsack(vector<int> wt, vector<int> val, int n, int maxWeight)
{
    vector<int> prev(maxWeight + 1, 0), cur(maxWeight + 1, 0);

    for (int W = wt[0]; W <= maxWeight; W++)
        prev[W] = val[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int W = 0; W <= maxWeight; W++)
        {
            int notTake = prev[W];
            int take = INT_MIN;

            if (wt[ind] <= W)
            {
                take = val[ind] + prev[W - wt[ind]];
            }

            cur[W] = max(take, notTake);
        }
        prev = cur;
    }

    return prev[maxWeight];
}

// REVIEW Space Optimization
// NOTE using only 1 prev vector and scaninng right to left instead of left to right and 2 vector
// Time Complexity : O(n * maxWeight) and Space Complexity ; O(maxWeight)

int knapsack(vector<int> wt, vector<int> val, int n, int maxWeight)
{
    vector<int> prev(maxWeight + 1, 0);

    for (int W = wt[0]; W <= maxWeight; W++)
        prev[W] = val[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int W = maxWeight; W >= 0; W--) // SECTION -  reverse loop
        {
            int notTake = prev[W];
            int take = INT_MIN;

            if (wt[ind] <= W)
            {
                take = val[ind] + prev[W - wt[ind]];
            }

            prev[W] = max(take, notTake);
        }
    }

    return prev[maxWeight];
}
