// REVIEW Tabulation
// Time : O(n*m) and Space : O(n*m)

// NOTE what is substring and Subsequence

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int lcs(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int ans = 0;

    // REVIEW no base case for tabulation !

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                int val = 1 + dp[i - 1][j - 1]; // Take , call for diagonal
                dp[i][j] = val;
                ans = max(ans, val);
            }
            else
            {
                dp[i][j] = 0; // SECTION not Take
            }
        }
    }

    return ans;
}

// REVIEW Space Optimization
// Time : O(n*m) and Space : O(m)

int lcs(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<int> prev(m + 1, 0); // SECTION -
    vector<int> cur(m + 1, 0);  // SECTION -
    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                int val = 1 + prev[j - 1];
                cur[j] = val;
                ans = max(ans, val);
            }
            else
            {
                cur[j] = 0;
            }
        }
        prev = cur;
    }

    return ans;
}
