// NOTE -  Problem Statement: You are given an array of integers 'arr' and an integer i.e. a threshold value 'limit'. Your task is to find the smallest positive integer divisor, such that upon dividing all the elements of the given array by it, the sum of the division's result is less than or equal to the given threshold value.

// ANCHOR Time Complexity : O(logn) and Space Complexity : O(1)

#include <vector>
#include <iostream>
#include <algorithm> //REVIEW -
using namespace std;
int sumByD(vector<int> &arr, int div)
{
    int n = arr.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += ceil((double)(arr[i]) / (double)(div));
    }
    return sum;
}

int smallestDivisor(vector<int> &arr, int limit)
{
    int n = arr.size();
    if (n > limit) // REVIEW this is the edge case here !
        return -1;
    // REVIEW -
    int low = 1, high = *max_element(arr.begin(), arr.end()); // REVIEW -

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (sumByD(arr, mid) <= limit)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}