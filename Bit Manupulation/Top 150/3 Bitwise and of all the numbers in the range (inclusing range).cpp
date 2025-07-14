// REVIEW Dry Run :
//   left = 5 → 2 → 1
//  right = 7 → 3 → 1
//  shift = 2

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int shift = 0;

        // Find the common left-most bits
        while (left < right)
        {
            left >>= 1;
            right >>= 1;
            shift++;
        }

        return left << shift;
    }
};
