// NOTE Problem Statement: Given an array of non-negative integers representation elevation of ground. Your task is to find the water that can be trapped after rain.

// LINK Time Complexity : O(n) and Space Complexity : O(n)

#include <iostream>
#include <vector>
using namespace std;
int trap(vector<int> &height)
{
    int n = height.size();
    int left = 0, right = n - 1;
    int res = 0;
    int maxLeft = 0, maxRight = 0;

    if (n == 0)   // REVIEW
        return 0; // Edge case: empty array

    while (left <= right)
    {
        if (height[left] <= height[right])
        {
            if (height[left] >= maxLeft)
            {
                maxLeft = height[left];
            }
            else
            {
                res += maxLeft - height[left];
            }
            left++;
        }
        else
        {
            if (height[right] >= maxRight)
            {
                maxRight = height[right];
            }
            else
            {
                res += maxRight - height[right];
            }
            right--;
        }
    }
    return res;
}

int main()
{
    vector<int> arr;
    arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "The water that can be trapped is " << trap(arr) << endl;
}