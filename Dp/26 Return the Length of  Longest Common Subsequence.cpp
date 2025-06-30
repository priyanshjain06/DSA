#include <iostream>
#include <string>
#include <vector>
using namespace std;

// REVIEW recurssion :
// Time : Exponential around O(2^(n + m))
int lcsRecursive(string &s1, string &s2, int i, int j)
{
    if (i < 0 || j < 0)
        return 0;

    if (s1[i] == s2[j])
        return 1 + lcsRecursive(s1, s2, i - 1, j - 1);
    else
        return max(
            lcsRecursive(s1, s2, i - 1, j),
            lcsRecursive(s1, s2, i, j - 1));
}

// REVIEW memorization :
// TIme :O(n * m) and Space Complexity : O(n * m) + O(n + m)

int lcsUtil(string &s1, string &s2, int ind1, int ind2, vector<vector<int>> &dp)
{
    if (ind1 < 0 || ind2 < 0)
        return 0;

    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    if (s1[ind1] == s2[ind2])
        return dp[ind1][ind2] = 1 + lcsUtil(s1, s2, ind1 - 1, ind2 - 1, dp);
    else
        return dp[ind1][ind2] = max(lcsUtil(s1, s2, ind1, ind2 - 1, dp), lcsUtil(s1, s2, ind1 - 1, ind2, dp));
}

// REVIEW tabulation
// Time : O(n * m) and Space Complexity : O(n * m)

int lcs(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    // SECTION -  here index -1 means index 1 and index n means index n-1 so take dp size n+1 and m+1 because we can mark out of bond for index -1

    for (int ind1 = 0; ind1 <= n; ind1++)
        dp[ind1][0] = 0;
    for (int ind2 = 0; ind2 <= m; ind2++)
        dp[0][ind2] = 0;

    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            else
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
        }
    }

    return dp[n][m];
}

// REVIEW Space optimization
// Time : O(n * m) and Space Complexity : O(m)

int lcs(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<int> prev(m + 1, 0), cur(m + 1, 0); // SECTION -

    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        // SECTION -  start from 1 to avoid out of bound
        {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                cur[ind2] = 1 + prev[ind2 - 1]; // SECTION -  only index 2
            else
                cur[ind2] = max(prev[ind2], cur[ind2 - 1]);
        }
        prev = cur;
    }

    return prev[m];
}
