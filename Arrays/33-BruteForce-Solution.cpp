// NOTE - Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

// ANCHOR - Time Complexity: O(min(n, m)) + O(n*logn) + O(m*logm) and spcace complexity : O(n)

// LINK Here we are using extra space :

#include <iostream>
#include <algorithm>

using namespace std;

void merge(long long arr1[], long long arr2[], int n, int m)
{
    int total = n + m;
    // Declare a 3rd array and 2 pointers:
    long long arr3[total];
    int left = 0;
    int right = 0;

    int index = 0;

    // Insert the elements from the 2 arrays
    //  into the 3rd array using left and right
    //  pointers:

    while (left < n && right < m)
    {
        if (arr1[left] <= arr2[right])
        {
            arr3[index] = arr1[left];
            left++, index++;
        }
        else
        {
            arr3[index] = arr2[right];
            right++, index++;
        }
    }

    // If right pointer reaches the end:
    while (left < n)
    {
        arr3[index++] = arr1[left++];
    }

    // If left pointer reaches the end:
    while (right < m)
    {
        arr3[index++] = arr2[right++];
    }

    // Fill back the elements from arr3[]
    // to arr1[] and arr2[]:
    for (int i = 0; i < n + m; i++)
    {
        if (i < n)
            arr1[i] = arr3[i];
        else
            arr2[i - n] = arr3[i];
    }
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
