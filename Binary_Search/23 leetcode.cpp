#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    int splitArray(vector<int> &nums, int k)
    {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (canSplit(nums, k, mid))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    bool canSplit(const std::vector<int> &nums, int k, int maxSum)
    {
        int currentSum = 0;
        int splits = 1;
        for (int num : nums)
        {
            if (currentSum + num > maxSum)
            {
                currentSum = num;
                ++splits;
                if (splits > k)
                {
                    return false;
                }
            }
            else
            {
                currentSum += num;
            }
        }
        return true;
    }
};