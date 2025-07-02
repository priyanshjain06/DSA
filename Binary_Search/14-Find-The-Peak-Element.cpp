#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// NOTE the array is not sorted here !

int findPeakElement(vector<int> &arr)
{
    int n = arr.size();

    if (n == 1)
        return arr[0];
    if (arr[0] != arr[1])
        return arr[0]; 
    if (arr[n - 1] != arr[n - 2])
        return arr[n - 1];

    int low = 1, high = n - 2; // REVIEW 
    while (low < high)         // NOTE < not <=
    {
        int mid = (low + high) / 2;

        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            return mid;

        if (arr[mid] > arr[mid + 1])
            high = mid; // REVIEW not mid -1  // Move left (mid may be the peak)
        else
            low = mid + 1;
    }
    return low; // REVIEW or return high  as per question !
}
