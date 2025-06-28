#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 1);

        // First loop: prefix product left to right !
        for (int i = 1; i < n; ++i)
        {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        // Second loop: suffix product (from right to left)
        int suffix = 1;
        for (int i = n - 1; i >= 0; --i) // REVIEW -
        {
            ans[i] *= suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};
