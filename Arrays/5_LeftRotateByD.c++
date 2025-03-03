// NOTE - left rotating the element by d places in an array
// optimize approach !


//ANCHOR - Optimize approach
//NOTE -  time complexity : O(n)
// and space complexity : O(1)

#include <iostream>
#include <algorithm>
using namespace std;

void leftRotate(int arr[], int n, int d)
{
    d = d % n; //REVIEW - 

    reverse(arr, arr + d);

    reverse(arr + d, arr + n);

    reverse(arr, arr + n);
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
