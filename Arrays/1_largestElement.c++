// NOTE -  Find the largest element in the array
//  3 appraches :
//   brute force : sort the array where the last element will be the largest element  which has complexity of O(n log n)
//  optimal :

#include <iostream>
using namespace std;
int findLargestElement(int arr[], int n)
{
    int largest = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    return largest;
}

int main()
{
    int arr[] = {10, 20, 5, 15, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    int largest = findLargestElement(arr, n);
    cout << "Largest element in the array: " << largest << endl;

    return 0;
}
