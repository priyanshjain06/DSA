// NOTE Problem Statement: Given an array of integers heights representing the histogram's bar height where the width of each bar is 1  return the area of the largest rectangle in histogram.

#include <iostream>
#include <climits>
using namespace std;
int largestarea(int arr[], int size)
{
    int maxArea = 0;
    for (int i = 0; i < size; i++)
    {
        int minHeight = INT_MIN;
        for (int j = i; j < size; j++)
        {
            minHeight = min(minHeight, arr[j]);
            maxArea = max(maxArea, minHeight * (j - i + 1)); // REVIEW -
        }
    }
    return maxArea;
}
int main()
{
    int arr[] = {2, 1, 5, 6, 2, 3, 1};
    int n = 7;
    cout << "The largest area in the histogram is " << largestarea(arr, n); // Printing the largest rectangle area
    return 0;
}