// REVIEW Recurssion !
//  Time : O(2^N) and Space Complexity : O(N)

#include <iostream>
#include <vector>
using namespace std;

bool subsetSumRecursive(int ind, int target, vector<int> &arr)
{
    if (target == 0)
        return true;

    if (ind == 0)
        return arr[0] == target; 

    bool notTaken = subsetSumRecursive(ind - 1, target, arr);

    bool taken = false;
    if (arr[ind] <= target)
        taken = subsetSumRecursive(ind - 1, target - arr[ind], arr);

    return notTaken || taken;
}

// REVIEW -  Memorization
//  Time :  O(N*K) and Space Complexity : O(N*K)+O(N)

bool subsetSumUtil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;

    if (ind == 0)
        return arr[0] == target;

    if (dp[ind][target] != -1)
        return dp[ind][target];

    bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);

    bool taken = false;
    if (arr[ind] <= target)
        taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = notTaken || taken;
}

// REVIEW  Tabulation :
// Time : O(N*K) and Space Complexity : O(N*K)

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false)); //  SECTION -  k+1 , 1 based indexing and bool type

    // SECTION - base case
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    // SECTION -  base case
    if (arr[0] <= k)
    {
        dp[0][arr[0]] = true;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {

            bool notTaken = dp[ind - 1][target]; 

            bool taken = false;
            if (arr[ind] <= target)
            {
                taken = dp[ind - 1][target - arr[ind]];
            }

            dp[ind][target] = notTaken || taken; 
        }
    }

    return dp[n - 1][k]; // SECTION -
}

// REVIEW -  Space Optimization
//  Time : O(N*K) and Space Complexity : O(K)

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<bool> prev(k + 1, false);
    prev[0] = true; // SECTION -

    if (arr[0] <= k) // SECTION why if ? for constraints
    {
        prev[arr[0]] = true;
    }

    for (int ind = 1; ind < n; ind++)
    {
        vector<bool> cur(k + 1, false);
        cur[0] = true; // SECTION - make the first element true

        for (int target = 1; target <= k; target++)
        {
            bool notTaken = prev[target];
            bool taken = false;
            if (arr[ind] <= target)
            {
                taken = prev[target - arr[ind]];
            }
            cur[target] = notTaken || taken;
        }

        prev = cur;
    }

    return prev[k]; // SECTION -
}
