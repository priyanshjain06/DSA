// ANCHOR : Time Complexity : O(logn) and Space Complexity : O(1)

// LINK lower Bound means the smallest element such that a[mid]>= x

#include <vector>
#include <iostream>
using namespace std;

int lowerBound(vector<int> arr, int n, int x)
{
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high)
    {
        int mid = low + ((high - low) / 2); // REVIEW -
        // maybe an answer
        if (arr[mid] >= x) // REVIEW -
        {
            ans = mid;
            // look for smaller index on the left
            high = mid - 1;
        }
        else
        {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}