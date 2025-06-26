// REVIEW -  Recurssion
// Time : O(2^n * T)  and Space : more than O(n)
#include <iostream>
#include < vector>
using namespace std;

int minimumElements(vector<int> &arr, int ind, int T)
{
    if (ind == 0)
    {
        if (T % arr[0] == 0) // SECTION -
            return T / arr[0];
        else
            return 1e9;
    }

    int notTaken = minimumElements(arr, ind - 1, T); // SECTION - ind -1
    int taken = 1e9;                                 // SECTION -
    if (arr[ind] <= T)
        taken = 1 + minimumElements(arr, ind, T - arr[ind]); // SECTION 1+ function(ind)

    return min(notTaken, taken);
}

// REVIEW Memorization
// Time Complexity:O(N*T)  and  Space Complexity:O(N*T) + O(N)

int minimumElementsUtil(vector<int> &arr, int ind, int T, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (T % arr[0] == 0)
            return T / arr[0];
        else
            return 1e9;
    }

    if (dp[ind][T] != -1)
        return dp[ind][T];

    int notTaken = minimumElementsUtil(arr, ind - 1, T, dp);
    int taken = 1e9;
    if (arr[ind] <= T)
        taken = 1 + minimumElementsUtil(arr, ind, T - arr[ind], dp);

    return dp[ind][T] = min(notTaken, taken);
}

// REVIEW Tabulation
// Time : : O(N*T) and Space :O(N*T)

int minimumElements(vector<int> &arr, int T)
{
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(T + 1, 0));

    for (int i = 0; i <= T; i++) // SECTION -  i % arr
    {
        if (i % arr[0] == 0)
            dp[0][i] = i / arr[0];
        else
            dp[0][i] = 1e9;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= T; target++)
        {

            int notTake = dp[ind - 1][target];
            int take = 1e9;

            if (arr[ind] <= target)
                take = 1 + dp[ind][target - arr[ind]];

            dp[ind][target] = min(notTake, take);
        }
    }

    int ans = dp[n - 1][T];

    if (ans >= 1e9) // SECTION -
        return -1;

    return ans;
}

// REVIEW Space Optimization
// Time Complexity:O(N*T)   and  Space Complexity:O(T)

int minimumElements(vector<int> &arr, int T)
{
    int n = arr.size();

    vector<int> prev(T + 1, 0);
    vector<int> cur(T + 1, 0);

    for (int i = 0; i <= T; i++)
    {
        if (i % arr[0] == 0)
            prev[i] = i / arr[0];
        else
            prev[i] = 1e9;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= T; target++)
        {

            int notTake = prev[target]; // SECTION use prev

            int take = 1e9;
            if (arr[ind] <= target)
                take = 1 + cur[target - arr[ind]]; // SECTION -  use curr

            cur[target] = min(notTake, take);
        }

        prev = cur;
    }

    int ans = prev[T]; 

    if (ans >= 1e9) //SECTION - 
        return -1;

    return ans;
}
