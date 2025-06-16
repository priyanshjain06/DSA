#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices)
        {
            minPrice = min(minPrice, price);              // Track the lowest price so far
            maxProfit = max(maxProfit, price - minPrice); // Maximize profit
        }

        return maxProfit;
    }
};
