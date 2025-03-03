// NOTE Maximum Product Subarray in an Array
//  Problem Statement: Given an array that contains both negative and positive integers, find the maximum product subarray.

// LINK  Time Complexity : O(n^3) and Space Complexity : O(1)

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxProductSubArray(vector<int> &nums)
{
    int result = INT_MIN;
    for (int i = 0; i < nums.size() - 1; i++) // REVIEW -
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            int prod = 1;
            for (int k = i; k <= j; k++)
                prod *= nums[k];
            result = max(result, prod);
        }
    }
    return result;
}

int main()
{
    vector<int> nums = {1, 2, -3, 0, -4, -5};
    cout << "The maximum product subarray: " << maxProductSubArray(nums);
    return 0;
}
