

// ANCHOR -  Time complexity : O(2n) and Space complexity : O(1)

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int atMostSum(vector<int> &nums, int goal)
    {
        if (goal < 0)
            return 0; // Edge case: If goal is negative, return 0

        int l = 0, sum = 0, count = 0;

        for (int r = 0; r < nums.size(); r++)
        {
            sum += (nums[r] % 2); //REVIEW - // Convert odd to 1, even to 0 **on the fly**

            while (sum > goal)
            {
                sum -= (nums[l] % 2); //REVIEW -  // Convert while shrinking window
                l++;
            }

            count += (r - l + 1); // Count subarrays ending at r
        }
        return count;
    }

    int numberOfSubarrays(vector<int> &nums, int k)
    {
        return atMostSum(nums, k) - atMostSum(nums, k - 1); // Use the modified function directly
    }
};

int main()
{
    vector<int> nums = {1, 1, 2, 1, 1}; // Example test case
    int k = 3;

    Solution sol;
    int result = sol.numberOfSubarrays(nums, k);

    cout << "Number of nice subarrays: " << result << endl;

    return 0;
}
