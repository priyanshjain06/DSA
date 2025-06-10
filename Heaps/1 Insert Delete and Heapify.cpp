#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Heap
{
public:
    int arr[100];
    int size;

    Heap()
    {
        arr[0] = -1; // REVIEW -
        size = 0;    // REVIEW -
    }

    void insert(int val)
    {
        int index = ++size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent; // REVIEW -
            }
            else    
            {
                return;
            }
        }
    }

    void deleteHeap()
    {
        if (size == 0)
        {
            cout << "Heap is empty!" << endl;
            return;
        }

        arr[1] = arr[size]; // REVIEW
        size--;

        int i = 1;
        while (i < size)
        {
            int leftChild = 2 * i;
            int rightChild = (2 * i) + 1;
            int largest = i;

            if (leftChild <= size && arr[largest] < arr[leftChild])
            {
                largest = leftChild;
            }

            if (rightChild <= size && arr[largest] < arr[rightChild])
            {
                largest = rightChild;
            }

            if (largest == i)
            {
                return;
            }
            else
            {
                swap(arr[i], arr[largest]); 
                i = largest; //REVIEW - 
            }
        }
    }

    void print()
    {
        cout << "Max Heap : ";
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }

    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    { // REVIEW
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

int main()
{
    Heap h;
    h.insert(50);
    h.insert(40);
    h.insert(60);
    h.insert(30);
    h.insert(55);
    h.insert(70);
    h.insert(20);

    h.print();

    h.deleteHeap();
    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n / 2; i > 0; i--)
    { // REVIEW -
        heapify(arr, n, i);
    }

    cout << "Heapified array : ";
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}