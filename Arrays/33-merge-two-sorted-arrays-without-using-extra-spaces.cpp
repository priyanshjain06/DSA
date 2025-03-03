// NOTE - Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

// ANCHOR - Time Complexity: O(min(n, m)) + O(n*logn) + O(m*logm) and spcace complexity : O(1)

#include <iostream>
#include <algorithm>

using namespace std;

void merge(long long arr1[], long long arr2[], int n, int m)
{

    // Declare 2 pointers:
    int left = n - 1; //REVIEW - 
    int right = 0;

    // Swap the elements until arr1[left] is
    //  smaller than arr2[right]:
    while (left >= 0 && right < m)
    {
        if (arr1[left] > arr2[right])
        {
            swap(arr1[left], arr2[right]);
            left--, right++;
        }
        else
        {
            break; //REVIEW - 
        }
    }

    // Sort arr1[] and arr2[] individually:
    sort(arr1, arr1 + n); //REVIEW - 
    sort(arr2, arr2 + m);
}

int main()
{
    long long arr1[] = {1, 4, 8, 10};
    long long arr2[] = {2, 3, 9};
    int n = 4, m = 3;
    merge(arr1, arr2, n, m);
    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}
