// NOTE Given an array of N integers, count the inversion of the array (using merge-sort).

// LINK - What is an inversion of an array? Definition: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].

// ANCHOR - Time Complexity: O(N ^2) and Space Complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

int numberOfInversions(vector<int> &a, int n)
{

    // Count the number of pairs:
    int cnt = 0; // REVIEW -
    for (int left = 0; left < n; left++)
    {
        for (int right = left + 1; right < n; right++)
        {
            if (a[left] > a[right])
                cnt++;
        }
    }
    return cnt;
}

int main()
{
    vector<int> a = {5, 4, 3, 2, 1};
    int n = 5;
    int cnt = numberOfInversions(a, n);
    cout << "The number of inversions is: "
         << cnt << endl;
    return 0;
}
