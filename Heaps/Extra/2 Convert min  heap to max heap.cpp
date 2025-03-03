#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void heapify(vector<int> &arr, int N, int i)
    {
        int largest = i;       // Initialize largest as root
        int left = 2 * i + 1;  // Left child
        int right = 2 * i + 2; // Right child

        // If left child is larger than root
        if (left < N && arr[left] > arr[largest])
        {
            largest = left;
        }

        // If right child is larger than largest so far
        if (right < N && arr[right] > arr[largest])
        {
            largest = right;
        }

        // If largest is not root
        if (largest != i)
        {
            swap(arr[i], arr[largest]); // Swap the elements
            heapify(arr, N, largest);   // Recursively heapify the affected subtree
        }
    }

    void convertMinToMaxHeap(vector<int> &arr, int N)
    {
        // Start from the last non-leaf node and heapify each node
        for (int i = N / 2 - 1; i >= 0; i--)
        {
            heapify(arr, N, i);
        }
    }
};