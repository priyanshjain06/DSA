// brute force : sort the elements and second last which is not eqaul to last element . O(nlogn)
// better : find largest and then find second largest by comapring
// optimal :

#include <iostream>
#include <climits>
using namespace std;

int findSecondLargest(int arr[], int n)
{
    int largest = INT_MIN, secondLargest = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] != largest)
        {
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}

int main()
{
    int arr[] = {10, 20, 5, 15, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    int secondLargest = findSecondLargest(arr, n);
    cout << "Second largest element: " << (secondLargest == INT_MIN ? -1 : secondLargest) << endl;

    return 0;
}
