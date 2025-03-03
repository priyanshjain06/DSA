// time complexity : Worst Case : O(n ^2) Other Case : O(nlogn)
#include <vector>
#include <iostream>
using namespace std;

int partition(vector<int> &arr, int low, int high);

void quicksort(vector<int> &arr, int low, int high)
{
    if (low == high)
        return;
    else
    {
        int pivotIndex = partition(arr, low, high);
        quicksort(arr, low, pivotIndex - 1);  // Sort the left side
        quicksort(arr, pivotIndex + 1, high); // Sort the right side
    }
}
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low]; // Choose the pivot as the first element
    int i = low;
    int j = high;

    while (i < j)
    {
        // Find an element grater than the pivot
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }

        // Find an element smaller than the pivot
        while (arr[j] >= pivot && j >= low + 1)
        {
            j--;
        }

        // Swap elements that are on the wrong side of the pivot
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }

    // Swap the pivot element to its correct position
    swap(arr[low], arr[j]);
    // Return the partition index
    return j;
}

int main()
{
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();

    quicksort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}