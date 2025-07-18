// NOTE read the question !

#include <iostream>
#include <vector>
using namespace std;

// REVIEW -
//  return 1, if == m:
//  return 0, if < m:
//  return 2, if > m:

int func(int mid, int n, int m)
{
    long long ans = 1;
    for (int i = 1; i <= n; i++) // REVIEW -  it will not make complexity o(n)
    {
        ans = ans * mid;
        if (ans > m)
            return 2;
    }
    if (ans == m)
        return 1;
    else
        return 0;
}

int NthRoot(int n, int m)
{
    int low = 1, high = m; // REVIEW -
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int midN = func(mid, n, m);
        if (midN == 1)
        {
            return mid;
        }
        else if (midN == 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}