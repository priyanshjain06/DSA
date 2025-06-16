#include <iostream>
#include <vector>
using namespace std;

//REVIEW  uses dp 
//REVIEW -  same as q 7 but here we can buy at most 2 stocks at a time 
class Solution
{
public:
    int maxProfitWithTwoTransactions(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0)
            return 0;

        vector<int> leftProfit(n, 0);  // Max profit from [0...i]
        vector<int> rightProfit(n, 0); // Max profit from [i...n-1]

        // Forward pass: Max profit with one transaction from left
        int minPrice = prices[0];
        for (int i = 1; i < n; ++i)
        {
            minPrice = min(minPrice, prices[i]);
            leftProfit[i] = max(leftProfit[i - 1], prices[i] - minPrice);
        }

        // Backward pass: Max profit with one transaction from right
        int maxPrice = prices[n - 1];
        for (int i = n - 2; i >= 0; --i)
        {
            maxPrice = max(maxPrice, prices[i]);
            rightProfit[i] = max(rightProfit[i + 1], maxPrice - prices[i]);
        }

        // Combine the two profits
        int maxTotalProfit = 0;
        for (int i = 0; i < n; ++i)
        {
            maxTotalProfit = max(maxTotalProfit, leftProfit[i] + rightProfit[i]);
        }

        return maxTotalProfit;
    }
};
