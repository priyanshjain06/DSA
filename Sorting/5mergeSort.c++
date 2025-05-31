// time complexity of all cases is O(n log n )
#include <iostream>
#include <vector>
using namespace std;

// Function to merge two sorted subarrays

// NOTE means that arr is a reference to a vector<int>

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    // Merging the two sorted subarrays
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // If there are remaining elements in the left subarray
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    // If there are remaining elements in the right subarray
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy the merged elements back to the original array
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low]; // NOTE i-low
    }
}

// Function to implement merge sort
void merge_sort(vector<int> &arr, int low, int high)
{
    if (low == high)
        return;
    else
    {
        int mid = low + (high - low) / 2;

        // Sort the first and second halves
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);

        // Merge the sorted halves
        merge(arr, low, mid, high);
    }
}
int main()
{
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    int n = arr.size();

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    merge_sort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
