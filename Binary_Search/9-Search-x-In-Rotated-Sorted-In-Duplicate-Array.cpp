// ANCHOR Time complexity : O(logn) and Space complexity : O(1)
#include <iostream>
#include <vector>
using namespace std;
bool searchInARotatedSortedArrayII(vector<int> &arr, int k)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == k)
            return true;
            
        // REVIEW - example : [45123344]
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) // REVIEW -
        {
            low = low + 1;
            high = high - 1;
            continue; //REVIEW - 
        }

        if (arr[low] <= arr[mid])
        {
            if (arr[low] <= k && k <= arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if (arr[mid] <= k && k <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return false;
}

int main()
{
    vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int k = 3;
    bool ans = searchInARotatedSortedArrayII(arr, k);
    if (!ans)
        cout << "Target is not present.\n";
    else
        cout << "Target is present in the array.\n";
    return 0;
}