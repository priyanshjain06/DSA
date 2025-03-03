#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        vector<int> left(n, 1), right(n, 1), maxCandies(n, 1); //REVIEW - 

        // Left pass
        for (int i = 1; i < n; i++)
            if (ratings[i] > ratings[i - 1])
                left[i] = left[i - 1] + 1;

        // Right pass
        for (int i = n - 2; i >= 0; i--)
            if (ratings[i] > ratings[i + 1])
                right[i] = right[i + 1] + 1;

        // Final max pass
        int totalCandies = 0;
        for (int i = 0; i < n; i++)
        {
            maxCandies[i] = max(left[i], right[i]);
            totalCandies += maxCandies[i];
        }

        return totalCandies;
    }
};

// Driver Code
int main()
{
    Solution sol;
    vector<int> ratings = {1, 0, 2};
    cout << "Minimum candies required: " << sol.candy(ratings) << endl;
    return 0;
}
