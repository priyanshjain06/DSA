#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        sort(citations.begin(), citations.end());
        // Sort citations in ascending order

        int n = citations.size();

        for (int i = 0; i < n; ++i)
        {
            int h = n - i;
            // Number of papers with at least citations[i] citations

            if (citations[i] >= h)
            {
                return h;
            }
        }

        return 0;
    }
};
// REVIEW -  dry run :Example:
//  Input: [3, 0, 6, 1, 5]
//  Sorted: [0, 1, 3, 5, 6]

// Try:

// i = 0 → h = 5 → 0 ≥ 5 ❌

// i = 1 → h = 4 → 1 ≥ 4 ❌

// i = 2 → h = 3 → 3 ≥ 3 ✅
// → ✅ Return 3