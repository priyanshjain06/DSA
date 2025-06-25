// REVIEW Space Optimization
//  time : O(N*totSum) +O(N) +O(N) and Space : O(totSum)
//  NOTE similar to q 16 concept !

#include <iostream>
#include <vector>
using namespace std;

int minSubsetSumDifference(vector<int> &arr, int n)
{
    int totSum = 0; // SECTION -  same as q 16

    for (int i = 0; i < n; i++)
    {
        totSum += arr[i];
    }

    vector<bool> prev(totSum + 1, false);

    prev[0] = true;

    if (arr[0] <= totSum)
        prev[arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {

        vector<bool> cur(totSum + 1, false);
        cur[0] = true;

        for (int target = 1; target <= totSum; target++)
        {

            bool notTaken = prev[target];

            bool taken = false;
            if (arr[ind] <= target)
                taken = prev[target - arr[ind]];

            cur[target] = notTaken || taken;
        }

        prev = cur;
    }

    // SECTION -  different from the previous question
    int mini = 1e9;
    for (int i = 0; i <= totSum / 2; i++) // SECTION -   totSum/2
    {
        if (prev[i] == true)
        {
            int diff = abs(i - (totSum - i));
            mini = min(mini, diff);
        }
    }
    return mini;
}

// REVIEW tabulation
// Time : O(N*totSum) +O(N) +O(N) and Space : O(N*totSum)

// Function to find the minimum absolute difference between two subset sums
int minSubsetSumDifference(vector<int> &arr, int n)
{
    int totSum = 0;

    for (int i = 0; i < n; i++)
    {
        totSum += arr[i];
    }

    vector<vector<bool>> dp(n, vector<bool>(totSum + 1, false));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    if (arr[0] <= totSum)
        dp[0][totSum] = true;

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= totSum; target++)
        {
            bool notTaken = dp[ind - 1][target];

            bool taken = false;
            if (arr[ind] <= target)
                taken = dp[ind - 1][target - arr[ind]];

            dp[ind][target] = notTaken || taken;
        }
    }

    int mini = 1e9;
    for (int i = 0; i <= totSum / 2; i++)
    {
        if (dp[n - 1][i] == true)
        {
            int diff = abs(i - (totSum - i));
            mini = min(mini, diff);
        }
    }
    return mini;
}
