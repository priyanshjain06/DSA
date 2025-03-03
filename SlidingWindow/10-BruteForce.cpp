// NOTE Given an array of integers arr of length n, count the number of contiguous subarrays that contain exactly k distinct integers.

// ANCHOR -  Time Complexity : O(n^2) and Space Complexity : O(n)

#include <iostream>
#include <unordered_map>
using namespace std;

int NumberOfSubarrays(int arr[], int n, int k)
{
    int count = 0;

    for (int i = 0; i <= n; i++)
    {
        unordered_map<int, int> hashmap;

        for (int j = i; j < n; j++)
        {
            hashmap[arr[j]]++;
            if (hashmap.size() == k)
                count++;
            if (hashmap.size() > k) // or use else 
                break;
        }
    }
    return count;
}
