// ANCHOR  Time Complexity :
#include <iostream>
#include <vector>
using namespace std;
int upperBound(vector<int> &arr, int x, int n)
{
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high)
    {
        int mid = low + ((high - low) / 2); //REVIEW - 
        if (arr[mid] > x) //REVIEW - 
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {3, 5, 8, 9, 15, 19};
    int n = 6, x = 9;
    int ind = upperBound(arr, x, n);
    cout << "The upper bound is the index: " << ind << "\n";
    return 0;
}
