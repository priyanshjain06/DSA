#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int totalSum = 0;
        int maxSum = nums[0], curMax = 0;
        int minSum = nums[0], curMin = 0;

        for (int num : nums)
        {
            curMax = max(num, curMax + num);
            maxSum = max(maxSum, curMax);

            curMin = min(num, curMin + num);
            minSum = min(minSum, curMin);

            totalSum += num;
        }

        // If all numbers are negative, return the max one (non-empty subarray)
        if (maxSum < 0)
            return maxSum;

        // Otherwise, return max of: non-wrapped maxSum and wrapped (total - min)
        return max(maxSum, totalSum - minSum);
    }
};
