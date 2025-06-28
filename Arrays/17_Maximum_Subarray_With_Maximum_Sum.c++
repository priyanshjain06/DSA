// NOTE - the problem is to find the maximum subarray sum in an array
//  LINK - Kadane's Algorithm: Maximum Subarray Sum in an Array
// NOTE - time complexity : O(n) and space complexity : O(1)

#include <iostream>
#include <climits>
using namespace std;

long long maxSubarraySum(int arr[], int n)
{
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;
    
    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++)
    {
        if (sum == 0)
            start = i; // starting index

        sum += arr[i];

        if (sum > maxi)
        {
            maxi = sum;

            ansStart = start;
            ansEnd = i;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0)
        {
            sum = 0;
        }
    }
    // REVIEW -
    if (maxi < 0)
        maxi = 0; // for empty array in case of all negative

    return maxi;
}