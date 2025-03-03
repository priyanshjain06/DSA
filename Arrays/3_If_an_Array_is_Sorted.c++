// NOTE check if the array is sorted or not

#include <iostream>
#include <vector>
using namespace std;

int sorted(int n, vector<int> a)
{
    for (int i = 1; i < n; i++)
    {
        if (a[i] >= a[i - 1])
        {
            continue;
        }
        else
            return false;
    }
    return true;
}