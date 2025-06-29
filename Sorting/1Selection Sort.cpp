// Time Complexity for all cases is : O(n^2)

// REVIEW  concept  is to select the min  in the array and campare to start of the array  if condition fails then swap the places

#include <iostream> 
using namespace std;
void selection_sort(int arr[], int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        int mini = i;
        for (int j = i; j <= n - 1; j++)
        {
            if (arr[j] < arr[mini])
            {
                mini = j;
            }
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
}
