#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// NOTE the array is not sorted here !
int findPeakElement(vector<int> &arr)
{
    int n = arr.size();
    1;

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

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int ans = findPeakElement(arr);
    cout << "The peak is at index: " << ans << "\n";
    return 0;
}
