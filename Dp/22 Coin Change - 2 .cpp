// REVIEW Recurssion
// Time : exponential and space : O(n)

#include <iostream>
#include <vector>
using namespace std;

long countWaysToMakeChangeUtil(vector<int> &arr, int ind, int T)
{
    if (ind == 0)
    {
        return (T % arr[0] == 0);
    }

    long notTaken = countWaysToMakeChangeUtil(arr, ind - 1, T);
    long taken = 0;
    if (arr[ind] <= T)
        taken = countWaysToMakeChangeUtil(arr, ind, T - arr[ind]);

    return notTaken + taken;
}

long countWaysToMakeChange(vector<int> &arr, int n, int T)
{
    return countWaysToMakeChangeUtil(arr, n - 1, T);
}

// REVIEW  Memoization
//  Time : O(N*T) and Space :O(N*T) + O(N)
long countWaysToMakeChangeUtil(vector<int> &arr, int ind, int T, vector<vector<long>> &dp)
{
    if (ind == 0)
    {
        return (T % arr[0] == 0);
    }

    if (dp[ind][T] != -1)
        return dp[ind][T];

    long notTaken = countWaysToMakeChangeUtil(arr, ind - 1, T, dp);
    long taken = 0;
    if (arr[ind] <= T)
        taken = countWaysToMakeChangeUtil(arr, ind, T - arr[ind], dp);

    return dp[ind][T] = notTaken + taken;
}

long countWaysToMakeChange(vector<int> &arr, int n, int T)
{
    vector<vector<long>> dp(n, vector<long>(T + 1, -1));
    return countWaysToMakeChangeUtil(arr, n - 1, T, dp);
}

// REVIEW -  Tabulation
// Time : O(N*T) and Space :O(N*T)

long countWaysToMakeChange(vector<int> &arr, int n, int T)
{
    vector<vector<long>> dp(n, vector<long>(T + 1, 0));

    for (int i = 0; i <= T; i++)
    {
        if (i % arr[0] == 0)
            dp[0][i] = 1;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= T; target++)
        {
            long notTaken = dp[ind - 1][target];
            long taken = 0;
            if (arr[ind] <= target)
                taken = dp[ind][target - arr[ind]];
            dp[ind][target] = notTaken + taken;
        }
    }

    return dp[n - 1][T];
}

// REVIEW Space Optimization
//  Time : O(N*T) and Space : O(T)
// NOTE using only 1 vector of prev  , 2 vector is also possible!

long countWaysToMakeChange(vector<int> &arr, int n, int T)
{
    vector<long> prev(T + 1, 0);

    for (int i = 0; i <= T; i++)
    {
        if (i % arr[0] == 0)
            prev[i] = 1;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = arr[ind]; target <= T; target++) // SECTION -
        {
            prev[target] += prev[target - arr[ind]];
        }
    }

    return prev[T];
}