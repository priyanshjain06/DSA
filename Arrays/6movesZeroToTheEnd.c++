// NOTE : we need to move zero to the end of the array
// ANCHOR -  optimal approach
//  use the concept of two pointer approach like removing duplicates elements

#include <iostream>
#include <vector>
using namespace std;

// j will always point to the last zero element
// while i will point to the non-zero element

vector<int> moveZeros(int n, vector<int> a)
{
    int j = -1;
    // place the pointer j:
    for (int i = 0; i <= n - 1; i++)
    {
        if (a[i] == 0)
        {
            j = i;
            break;
        }
    }

    // no non-zero elements:
    if (j == -1)
        return a;

    // Move the pointers i and j
    // and swap accordingly:
    for (int i = j + 1; i <= n - 1; i++)
    {
        if (a[i] != 0)
        {
            swap(a[i], a[j]);
            j++;
        }
    }
    return a;
}

