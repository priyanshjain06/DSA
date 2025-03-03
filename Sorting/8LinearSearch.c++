// Time complexity : O(1): Best case and other cases : O(n)

#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i; // Return index of target
        }
    }
    return -1; // Target not found
}
