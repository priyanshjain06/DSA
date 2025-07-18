// Time : O(n*m) and Space : O(n*m)

#include <iostream>
#include <vector>
#include <string>
#include <string>
using namespace std;

string shortestSupersequence(string s1, string s2)
{

    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }

    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            else
                dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
        }
    }

    int len = dp[n][m];
    int i = n;
    int j = m;

    int index = len - 1;
    string ans = ""; // SECTION - not dummy but empty string !

    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans += s1[i - 1];
            index--;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            ans += s1[i - 1];
            i--;
        }
        else
        {
            ans += s2[j - 1];
            j--;
        }
    }

    // SECTION -  the above will produce reverse string !

    //  Adding Remaing Characters - Only one of the below two while loops will run EXAMPLE : (0,1) or (1,0)

    while (i > 0)
    {
        ans += s1[i - 1];
        i--;
    }
    while (j > 0)
    {
        ans += s2[j - 1];
        j--;
    }

    reverse(ans.begin(), ans.end()); // SECTION -

    return ans; // SECTION -  may be asked to return the length here !
}

// SECTION if only lenght is asked then !
// NOTE used in gfg

class Solution
{
public:
    int shortestCommonSupersequence(string &s1, string &s2)
    {
        int n = s1.size();
        int m = s2.size();

        // SECTION -  no base case in needed

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

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

        int lcsLength = dp[n][m]; // SECTION -

        return n + m - lcsLength; // SECTION -
    }
};
