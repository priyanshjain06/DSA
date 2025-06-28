
// LINK  array should be in sorted order
// ANCHOR time complexity : O(logn)=>
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0, high = n - 1; 

    while (low <= high)
    {
        int mid = low + (high - low) / 2; // REVIEW -  always use this to avoid overflow
        if (nums[mid] == target)
            return mid;
        else if (target > nums[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
