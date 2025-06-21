// Memorization :
//  time complexity : O(n) and Space Complexity : O(n)

#include <iostream>
#include <vector>
using namespace std;

int f(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];
    return dp[n] = f(n - 1, dp) + f(n - 2, dp);
}

// REVIEW Tabulaion :
// time complexity : O(n) and Space Complexity : O(n)

using namespace std;

int main()
{

    int n = 5;
    vector<int> dp(n + 1, -1);

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n];
    return 0;
}

// REVIEW space Optimization :
// Time Complexity :  O(N) and Space Complexity :  O(1)

using namespace std;

int main()
{

    int n = 5;

    int prev2 = 0;
    int prev = 1;

    for (int i = 2; i <= n; i++)
    {
        int cur_i = prev2 + prev;
        prev2 = prev;
        prev = cur_i;
    }
    cout << prev;
    return 0;
}
