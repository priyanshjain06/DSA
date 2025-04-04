
// REVIEW - Time Complexity: O(N * log(sum(arr[])-max(arr[])+1))

// ANCHOR - leetcode 410

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
int countPartitions(vector<int> &a, int maxSum)
{
    int n = a.size();          // size of array.
    int partitions = 1;        // REVIEW
    long long subarraySum = 0; // REVIEW
    for (int i = 0; i < n; i++)
    {
        if (subarraySum + a[i] <= maxSum)
        {
            // insert element to current subarray
            subarraySum += a[i];
        }
        else
        {
            // insert element to next subarray
            partitions++;
            subarraySum = a[i];
        }
    }
    return partitions;
}

int largestSubarraySumMinimized(vector<int> &a, int k)
{
    int low = *max_element(a.begin(), a.end());
    int high = accumulate(a.begin(), a.end(), 0);
    // Apply binary search:
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int partitions = countPartitions(a, mid);
        if (partitions <= k)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}
int main()
{
    vector<int> a = {10, 20, 30, 40};
    int k = 2;
    int ans = largestSubarraySumMinimized(a, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
