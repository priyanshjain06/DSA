class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<unsigned long long> prev(amount + 1, 0);

        // Base case: Using only the first coin
        for (int i = 0; i <= amount; i++)
        {
            if (i % coins[0] == 0)
                prev[i] = 1;
        }

        // Process other coins
        for (int ind = 1; ind < n; ind++)
        {
            for (int target = coins[ind]; target <= amount; target++)
            {
                unsigned long long sum = prev[target] + prev[target - coins[ind]]; // SECTION prev{target} + prev{target-coins[ind]}
                prev[target] = (sum > INT_MAX) ? INT_MAX : sum;
            }
        }

        return (int)prev[amount]; // SECTION -  return the answer in int
    }
};
