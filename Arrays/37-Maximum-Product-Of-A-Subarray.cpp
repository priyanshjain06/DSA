// NOTE Maximum Product Subarray in an Array
//  Problem Statement: Given an array that contains both negative and positive integers, find the maximum product subarray.

// ANCHOR -  Remember the cases here :- see screenshot

// LINK  Time Complexity : O(n) and Space Complexity : O(1)

#include <iostream>
#include <vector>
using namespace std;
int maxProductSubArray(vector<int> &arr)
{
    int n = arr.size(); // size of array.

    int pre = 1, suff = 1;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (pre == 0)
            pre = 1;
        if (suff == 0)
            suff = 1;
        pre *= arr[i];
        suff *= arr[n - i - 1]; // REVIEW
        ans = max(ans, max(pre, suff));
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, -3, 0, -4, -5};
    cout << "The maximum product subarray is: "
         << maxProductSubArray(arr) << "\n";
    return 0;
}
