#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1, 0);

        for (int i = 1; i <= n; ++i)
        {
            // Apply the dynamic programming formula:
            // ans[i] = ans[i / 2] + (i % 2);  // Equivalent to the bitwise operations
            ans[i] = ans[i >> 1] + (i & 1); // Optimal bitwise version
        }

        return ans;
    }
};