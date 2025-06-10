#include <iostream>
#include <algorithm>
using namespace std;

int countPlatforms(int n, int arr[], int dep[])
{
    sort(arr, arr + n);
    sort(dep, dep + n);

    int ans = 1;
    int count = 1;    // REVIEW -
    int i = 1, j = 0; // REVIEW -  i represents the index for arrivals and starts from 1 because the first train (at index 0) has already been counted as requiring a platform.

    while (i < n && j < n)
    {
        
      if (arr[i] <= dep[j]) // one more platform needed
        {
            count++;
            i++;
        }  else // one platform can be reduced
        {
            count--;
            j++;
        }
        ans = max(ans, count); // updating the value with the current maximum
    }
    return ans;
}

int main()
{
    int arr[] = {900, 945, 955, 1100, 1500, 1800};
    int dep[] = {920, 1200, 1130, 1150, 1900, 2000};
    int n = sizeof(dep) / sizeof(dep[0]);
    cout << "Minimum number of Platforms required " << countPlatforms(n, arr, dep) << endl;
}