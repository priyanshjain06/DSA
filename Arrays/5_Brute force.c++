#include <iostream>
using namespace std;

// Function to rotate array elements to the left by one place
//time complexity : O(n*d)
void leftRotateByOne(int arr[], int n)
{
    int temp = arr[0];
    for (int i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[n - 1] = temp;
}

// Function to rotate array elements to the left by `d` places
void leftRotate(int arr[], int n, int d)
{
    for (int i = 0; i < d; i++)
    {
        leftRotateByOne(arr, n);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 2;

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    leftRotate(arr, n, d);

    cout << "Array after left rotation by " << d << " places: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
