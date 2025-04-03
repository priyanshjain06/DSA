#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    int calculateTotalHours(vector<int> &piles, int k)
    {
        int totalH = 0;
        for (int bananas : piles)
            totalH += ceil((double)bananas / k);
        return totalH;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        int low = 1, high = *max(piles.begin(), piles.end());
        // REVIEW use *max
        while (low < high)
        {
            int mid = (low + high) / 2;
            if (calculateTotalHours(piles, mid) <= h)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};
