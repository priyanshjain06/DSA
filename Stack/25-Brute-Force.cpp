// ANCHOR time complexity : O(n^2) add space complexity : O(1)
//LINK this method is called next greater element or monotonic stack

#include <iostream>
using namespace std;
void printNGE(int arr[], int n)
{
    int next, i, j;
    for (i = 0; i < n; i++)
    {
        next = -1;//REVIEW - 
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                next = arr[j];
                break;
            }
        }
        cout << arr[i] << " --> " << next << endl;
    }
}

int main()
{
    int arr[] = {11, 13, 21, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printNGE(arr, n);
    return 0;
}
