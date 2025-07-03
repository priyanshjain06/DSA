// NOTE - Problem Statement: You are given 'N’ roses and you are also given an array 'arr'  where 'arr[i]'  denotes that the 'ith' rose will bloom on the 'arr[i]th' day.
//  You can only pick already bloomed roses that are adjacent to make a bouquet. You are also told that you require exactly 'k' adjacent bloomed roses to make a single bouquet.
//  Find the minimum number of days required to make at least ‘m' bouquets each containing 'k' roses. Return -1 if it is not possible.

// LINK - Example 1:
//  Input Format:
//   N = 8, arr[] = {7, 7, 7, 7, 13, 11, 12, 7}, m = 2, k = 3
//  Result:
//   12
//  Explanation:
//   On the 12th the first 4 flowers and the last 3 flowers would have already bloomed. So, we can easily make 2 bouquets, one with the first 3 and another with the last 3 flowers.

// ANCHOR - : O(log(max(arr[])-min(arr[])+1) * N),

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool possible(vector<int> &arr, int day, int m, int k)
{
    int n = arr.size();
    int cnt = 0;
    int noOfB = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= day)
        {
            cnt++;
        }
        else
        {
            noOfB += (cnt / k);
            cnt = 0;
        }
    }
    noOfB += (cnt / k);
    return noOfB >= m; // REVIEW -
}
int roseGarden(vector<int> arr, int k, int m)
{
    long long val = m * 1ll * k * 1ll;
    int n = arr.size();
    if (val > n)
        return -1; // impossible case.

    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }

    int low = mini, high = maxi;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (possible(arr, mid, m, k))
            high = mid - 1;
        // NOTE because we want minimum so we eliminate right side from mid
        else
            low = mid + 1;
    }

    return low; // NOTE why low ? becuase we want to return the minimum
}
