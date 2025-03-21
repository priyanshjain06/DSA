#include <iostream>
#include <vector>

class Solution
{
public:
    int longestNiceSubarray(vector<int> &nums)
    {
        int left = 0, bit_mask = 0, max_len = 0;

        for (int right = 0; right < nums.size(); right++)
        {
            while ((bit_mask & nums[right]) != 0)
            {
                bit_mask ^= nums[left];
                left++;
            }

            bit_mask |= nums[right];
            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};
