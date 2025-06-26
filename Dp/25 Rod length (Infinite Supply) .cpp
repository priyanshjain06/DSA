#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int f(int ind, int length, vector<int> &price)
    {
        if (ind == 0)
        {
            return (length / 1) * price[0]; // SECTION
        }

        int notPick = f(ind - 1, length, price);
        int pick = INT_MIN;
        int rodLen = ind + 1; // SECTION
        if (rodLen <= length)
            pick = price[ind] + f(ind, length - rodLen, price);

        return max(pick, notPick);
    }

    int cutRod(vector<int> &price)
    {
        int n = price.size();
        return f(n - 1, n, price);
    }
};

class Solution
{
public:
    int f(int ind, int length, vector<int> &price, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            return (length / 1) * price[0];
        }

        if (dp[ind][length] != -1)
            return dp[ind][length];

        int notPick = f(ind - 1, length, price, dp);
        int pick = INT_MIN;
        int rodLen = ind + 1;
        if (rodLen <= length)
            pick = price[ind] + f(ind, length - rodLen, price, dp);

        return dp[ind][length] = max(pick, notPick);
    }

    int cutRod(vector<int> &price)
    {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(n - 1, n, price, dp);
    }
};

class Solution
{
public:
    int cutRod(vector<int> &price)
    {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        for (int length = 0; length <= n; length++)
        {
            dp[0][length] = length * price[0]; 
        }

        for (int ind = 1; ind < n; ind++)
        {
            for (int length = 0; length <= n; length++)
            {
                int notPick = dp[ind - 1][length];
                int pick = INT_MIN;
                int rodLen = ind + 1;
                if (rodLen <= length)
                    pick = price[ind] + dp[ind][length - rodLen];

                dp[ind][length] = max(pick, notPick);
            }
        }

        return dp[n - 1][n];
    }
};

class Solution
{
public:
    int cutRod(vector<int> &price)
    {
        int n = price.size();
        vector<int> dp(n + 1, 0);

        for (int length = 0; length <= n; length++)
        {
            dp[length] = length * price[0];
        }

        for (int ind = 1; ind < n; ind++)
        {
            for (int length = 0; length <= n; length++)
            {
                int notPick = dp[length];
                int pick = INT_MIN;
                int rodLen = ind + 1;
                if (rodLen <= length)
                    pick = price[ind] + dp[length - rodLen];

                dp[length] = max(pick, notPick);
            }
        }

        return dp[n];
    }
};
