#include <unordered_map>
#include <climits>
using namespace std;

pair<int, int> MinimumLengthOfSubstring(int arr[], int n, int t[], int m)
{
    int min_length = INT_MAX;
    int start_index = -1;

    for (int i = 0; i < n; i++)
    {
        unordered_map<int, int> hashmap;
        int count = 0;

        for (int j = 0; j < m; j++)
        {
            hashmap[t[j]]++; 
        }

        for (int j = i; j < n; j++) 
        {
            if (hashmap[arr[j]] > 0)
            {
                count = count + 1;
            }
            hashmap[arr[j]]--;

            if (count == m)
            {
                int current_length = j - i + 1;
                if (current_length < min_length)
                {
                    min_length = current_length;
                    start_index = i;
                    break; // REVIEW -
                }
            }
        }
    }

    if (min_length == INT_MAX)
    {
        return {-1, 0}; // No valid substring found
    }

    return {start_index, min_length}; // Fix: Return as a pair
}