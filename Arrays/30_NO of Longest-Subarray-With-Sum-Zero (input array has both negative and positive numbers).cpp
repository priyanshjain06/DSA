// NOTE - : Given an array containing both positive and negative integers, we have to find the length of the longest subarray with the sum of all elements equal to zero.

// ANCHOR time complexity : O(n) and space complexity : O(n)

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int maxLen(int A[], int n)
{
    // Your code here
    unordered_map<int, int> mpp;
    int maxi = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
        if (sum == 0)
        {
            maxi = i + 1;
        }
        else
        {
            if (mpp.find(sum) != mpp.end())
            {
                maxi = max(maxi, i - mpp[sum]); //REVIEW - 
            }
            else
            {
                mpp[sum] = i;
            }
        }
    }

    return maxi;
}