// NOTE -  Problem Statement: You are given an array of integers 'arr' and an integer i.e. a threshold value 'limit'. Your task is to find the smallest positive integer divisor, such that upon dividing all the elements of the given array by it, the sum of the division's result is less than or equal to the given threshold value.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int smallestDivisor(vector<int> &arr, int limit)
{
    int n = arr.size();
    int maxi = *max_element(arr.begin(), arr.end()); //REVIEW - use algo library for this

    for (int d = 1; d <= maxi; d++) // REVIEW see screenshot to understand this loop
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += ceil((double)(arr[i]) / (double)(d)); // REVIEW use ceil

        if (sum <= limit)
            return d;
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int limit = 8;
    int ans = smallestDivisor(arr, limit);
    cout << "The minimum divisor is: " << ans << "\n";
    return 0;
}
