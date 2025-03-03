// NOTE Maximum Product Subarray in an Array
//  Problem Statement: Given an array that contains both negative and positive integers, find the maximum product subarray.

// LINK  Time Complexity : O(n^2) and Space Complexity : O(1)

#include <iostream>
#include <vector>
using namespace std;

int maxProductSubArray(vector<int> &nums)
{
    int result = nums[0];
    for (int i = 0; i < nums.size() - 1; i++)
    {
        int p = nums[i];
        for (int j = i + 1; j < nums.size(); j++)
        {
            result = max(result, p); //REVIEW - 
            p *= nums[j];
        }
        result = max(result, p); // manages (n-1)th term
        //REVIEW - 
    }
    return result;
}

int main()
{
    vector<int> nums = {1, 2, -3, 0, -4, -5};
    cout << "The maximum product subarray: " << maxProductSubArray(nums);
    return 0;
}
