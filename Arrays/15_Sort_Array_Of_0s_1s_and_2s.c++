// LINK -  the approach is called as  Dutch National Flag Algo
//   the concept it to use 3 pointer and sort the array

// NOTE  time complexit is O(n) and space complexity is O(1)

#include <iostream>
#include <vector>

using namespace std;

void sortArray(vector<int> &arr, int n)
{

    int low = 0, mid = 0, high = n - 1; // 3 pointers

    while (mid <= high)
    {
        if (arr[mid] == 0) // FIXME  Dutch National Flag Algo
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--; //REVIEW - 
        }
    }
}

int main()
{
    int n = 6;
    vector<int> arr = {0, 2, 1, 2, 0, 1};
    sortArray(arr, n);
    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}