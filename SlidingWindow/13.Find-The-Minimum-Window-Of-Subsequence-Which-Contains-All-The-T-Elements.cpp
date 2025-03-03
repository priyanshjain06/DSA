#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;
pair<int, int> minSubsequenceWindow(int arr[], int n, int t[], int m)
{
    int min_length = INT_MAX;
    int start_index = -1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == t[0])
        {
            int length = 1;
            int k = 1;     // to check for rest of elements  in the t array
            int j = i + 1; // to traverse for the rest of the array

            while (j < n && k < m)
            {
                if (arr[j] == t[k])
                {
                    k++;
                }
                length++;
                j++;
            }

            if (k == m && length < min_length)
            {
                min_length = length;
                start_index = i;
            }
        }
    }
    return start_index == -1 ? make_pair(-1, -1) : make_pair(min_length, start_index);
}
