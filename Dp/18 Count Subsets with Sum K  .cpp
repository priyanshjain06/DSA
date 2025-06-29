// REVIEW Memorization
// Time :  O(N*K) and Space Complexity : O(N*K)+O(N)

#include <iostream>
#include <vector>
using namespace std;

int findWaysUtil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return 1;

    if (ind == 0)
        return (arr[0] == target) ? 1 : 0;

    if (dp[ind][target] != -1)
        return dp[ind][target];

    int notTaken = findWaysUtil(ind - 1, target, arr, dp);

    int taken = 0;
    if (arr[ind] <= target)
        taken = findWaysUtil(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = notTaken + taken; // SECTION -
}

int findWays(vector<int> &num, int k)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return findWaysUtil(n - 1, k, num, dp);
}

// REVIEW Tabulation
// Time :  O(N*K) and Space Complexity : O(N*K)

int findWays(vector<int> &num, int k)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }

    if (num[0] <= k)
    {
        dp[0][num[0]] = 1;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            int notTaken = dp[ind - 1][target];
            int taken = 0;
            if (num[ind] <= target)
            {
                taken = dp[ind - 1][target - num[ind]];
            }
            dp[ind][target] = notTaken + taken;
        }
    }

    return dp[n - 1][k];
}

// REVIEW Space optimization
// NOTE : for constraint 1<= num[i]<=1000

int findWays(vector<int> &num, int k)
{
    int n = num.size();

    vector<int> prev(k + 1, 0);

    prev[0] = 1;

    if (num[0] <= k)
    {
        prev[num[0]] = 1;
    }

    for (int ind = 1; ind < n; ind++)
    {

        vector<int> cur(k + 1, 0);

        cur[0] = 1;

        for (int target = 1; target <= k; target++)
        {
            int notTaken = prev[target];

            int taken = 0;
            if (num[ind] <= target)
            {
                taken = prev[target - num[ind]];
            }

            cur[target] = notTaken + taken;
        }

        prev = cur;
    }

    return prev[k];
}

//  REVIEW Space Optimization
//   Time : O(N*K) and Space : O(K)
// NOTE : for constraint 0 <= num[i] <= 1000
// NOTE : use this for coding ninja and gfg !

class Solution
{
public:
    int perfectSum(vector<int> &arr, int target)
    {
        int n = arr.size();
        int MOD = 1e9 + 7; // SECTION -
        vector<int> prev(target + 1, 0);

        prev[0] = 1;
        if (arr[0] <= target)
            prev[arr[0]] += 1; // SECTION -
        if (arr[0] == 0)       // SECTION -
            prev[0] = 2;       // count two ways for zero: pick or not pick

        for (int ind = 1; ind < n; ind++)
        {
            vector<int> cur(target + 1, 0);
            for (int t = 0; t <= target; t++)
            {
                int notTaken = prev[t];
                int taken = 0;
                if (arr[ind] <= t)
                    taken = prev[t - arr[ind]];
                cur[t] = (notTaken + taken) % MOD; // SECTION -
            }
            prev = cur;
        }

        return prev[target];
    }
};
