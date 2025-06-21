// REVIEW  Recurssive Solution :
// TIme :  O(2^n) and space : n

#include <vector>
using namespace std;
class Solution
{
public:
    int solve(int i, vector<int> &arr)
    {
        if (i == 0)
            return arr[0];
        if (i < 0)
            return 0; // REVIEW

        int pick = arr[i] + solve(i - 2, arr);
        int notPick = solve(i - 1, arr);

        return max(pick, notPick);
    }

    int findMaxSum(vector<int> &arr)
    {
        int n = arr.size();
        return solve(n - 1, arr);
    }
};

// REVIEW memorization
// TIme :  O(n) and space : n +n = n

int solveUtil(int ind, vector<int> &arr, vector<int> &dp)
{
    if (dp[ind] != -1)
        return dp[ind];

    if (ind == 0)
        return arr[ind];
    if (ind < 0)
        return 0;

    int pick = arr[ind] + solveUtil(ind - 2, arr, dp);
    int nonPick = 0 + solveUtil(ind - 1, arr, dp);

    return dp[ind] = max(pick, nonPick);
}

// REVIEW Tabulation : Time: n and Space Complexity :  n

int solveUtil(int n, vector<int> &arr, vector<int> &dp)
{
    dp[0] = arr[0];

    for (int i = 1; i < n; i++)
    {

        int pick = arr[i];
        if (i > 1)
            pick += dp[i - 2]; // compound operator , edge case
        int nonPick = dp[i - 1];

        dp[i] = max(pick, nonPick);
    }

    return dp[n - 1]; // REVIEW -
}

// REVIEW Space Optimization:
//  time : n and space : 1

int solve(int n, vector<int> &arr)
{

    if (n == 0) // REVIEW
        return 0;
    if (n == 1)
        return arr[0];

    int prev = arr[0]; // REVIEW dp[i-1]
    int prev2 = 0;     // dp[i-2]

    for (int i = 1; i < n; i++)
    {
        int pick = arr[i];
        if (i > 1)
            pick += prev2;

        int nonPick = 0 + prev;

        int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev = cur_i;
    }

    return prev; // REVIEW why ?  in tabulation we return dp[n-1] but here the ans will be at index i-1 which is prev
}
