#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int sum = 1, i = 1, n = ratings.size();
        while (i < n)
        {
            if (ratings[i] == ratings[i - 1])
            {
                sum += 1;
                i++;
                continue;
            }

            int peak = 1; // REVIEW -
            while (i < n && ratings[i] > ratings[i - 1])
            {
                peak++;
                sum += peak;
                i++;
            }

            int down = 0; // REVIEW -
            while (i < n && ratings[i] < ratings[i - 1])
            {
                down++;
                sum += down;
                i++;
            }
            down++; // REVIEW -

            if (down > peak) // REVIEW -  not >=
                sum += (down - peak);
        }
        return sum;
    }
};

int main()
{
    // Example 1
    Solution sol;
    vector<int> ratings1 = {1, 0, 2};
    cout << "Minimum candies (Example 1): " << sol.candy(ratings1) << endl; // Expected output: 5

    // Example 2
    vector<int> ratings2 = {1, 2, 2};
    cout << "Minimum candies (Example 2): " << sol.candy(ratings2) << endl; // Expected output: 4

    // Example 3 (Additional case)
    vector<int> ratings3 = {1, 3, 2, 2, 1};
    cout << "Minimum candies (Example 3): " << sol.candy(ratings3) << endl; // Expected output: 7

    return 0;
}
