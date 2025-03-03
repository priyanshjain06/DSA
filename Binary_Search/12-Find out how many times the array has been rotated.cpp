// NOTE Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values). Now the array is rotated between 1 to N times which is unknown. Find how many times the array has been rotated.

// ANCHOR Time Complexity : O(logn) and Space Complexity : O(1)

#include <iostream>
#include <vector>
using namespace std;
int findKRotation(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX; // REVIEW -
    int index = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        
        if (arr[low] <= arr[high])
        {
            if (arr[low] < ans)
            {
                index = low;
                ans = arr[low];
            }
            break; // REVIEW -
        }

        // if left part is sorted:
        if (arr[low] <= arr[mid])
        {
            // keep the minimum:
            if (arr[low] < ans)
            {
                index = low;
                ans = arr[low];
            }

            // Eliminate left half:
            low = mid + 1;
        }
        else
        { // if right part is sorted:

            // keep the minimum:
            if (arr[mid] < ans) //REVIEW - 
            {
                index = mid;
                ans = arr[mid];
            }

            // Eliminate right half:
            high = mid - 1;
        }
    }
    return index;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = findKRotation(arr);
    cout << "The array is rotated " << ans << " times.\n";
    return 0;
}
