#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        vector<int> left(n, 1); // Left pass array

        // Left pass
        for (int i = 1; i < n; i++)
            if (ratings[i] > ratings[i - 1])
                left[i] = left[i - 1] + 1;

        // Right pass in maxCandies using current variable
        int totalCandies = 0, current = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (i < n - 1 && ratings[i] > ratings[i + 1])
                current++;
            else
                current = 1; //REVIEW - 

            totalCandies += max(left[i], current);
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
