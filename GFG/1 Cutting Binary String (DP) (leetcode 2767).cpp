// LINK https://www.geeksforgeeks.org/problems/cutting-binary-string1342/1

#include <iostream>
#include <unordered_set>
#include <string>
#include <climits>
using namespace std;

// REVIEW Using recurssion

class Solution
{
private:
    unordered_set<string> power5;

    void precompute()
    {
        for (long long p = 1; p <= (1LL << 30); p *= 5)
        {
            string bin = "";
            long long x = p;
            while (x > 0) // REVIEW binary to decimal
            {
                bin = (x % 2 ? "1" : "0") + bin;
                x /= 2;
            }
            power5.insert(bin);
        }
    }

    void backtrack(string &s, int index, int count, int &minCuts)
    {
        if (index == s.size())
        {
            minCuts = min(minCuts, count);
            return;
        }

        string curr = "";
        for (int j = index; j < s.size(); ++j)
        {
            curr += s[j];
            if (curr[0] == '0')
                break; // leading zero not allowed
            if (power5.count(curr))
            {
                backtrack(s, j + 1, count + 1, minCuts);
            }
        }
    }

public:
    int cuts(string s)
    {
        precompute();
        int minCuts = INT_MAX;
        backtrack(s, 0, 0, minCuts);
        return minCuts == INT_MAX ? -1 : minCuts;
    }
};

// Space Optimization using dp

// int minCuts(string s) {
//     unordered_set<string> power5;
//     // precompute...
//     vector<int> dp(s.size() + 1, INT_MAX);
//     dp[0] = 0;

//     for (int i = 1; i <= s.size(); ++i) {
//         for (int j = 0; j < i; ++j) {
//             string sub = s.substr(j, i - j);
//             if (sub[0] != '0' && power5.count(sub)) {
//                 if (dp[j] != INT_MAX)
//                     dp[i] = min(dp[i], dp[j] + 1);
//             }
//         }
//     }

//     return dp[s.size()] == INT_MAX ? -1 : dp[s.size()];
// }
