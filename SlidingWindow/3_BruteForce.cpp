// NOTE -

// ANCHOR -  Time Complexity : O(n ^2) and Space Complexity : O(1)

#include <iostream>
#include <vector>
using namespace std;

int Max(int num[], int K, int n)
{
    int len = 0;

    for (int i = 0; i < n; i++)
    {
        int ZeroCount = 0;
        for (int j = i; j < n; j++)
        {
            if (num[j] == 0)
            {
                ZeroCount++;
            }

            if (ZeroCount <= K)
            {
                len = max(len, j - i + 1);
            }
            
            else
            {
                break;
            }
        }
    }
}