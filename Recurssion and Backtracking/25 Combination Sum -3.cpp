#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void backtrack(int start, int k, int n, int sum, vector<int> &combination, vector<vector<int>> &res)
    {
        if (k == 0)
        { // If we've picked k numbers
            if (sum == n)
                res.push_back(combination);
            return;
        }

        for (int i = start; i <= 9; i++) //REVIEW
        {
            if (sum + i > n) //REVIEW 
                break; // Stop if sum exceeds target
            combination.push_back(i);
            backtrack(i + 1, k - 1, n, sum + i, combination, res); // Reduce k
            combination.pop_back();                                // Backtrack
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> res;
        vector<int> combination;
        backtrack(1, k, n, 0, combination, res); // Start with sum = 0
        return res;
    }
};

int main()
{
    Solution sol;
    int k = 3, n = 7;
    vector<vector<int>> result = sol.combinationSum3(k, n);

    // Print the result
    for (const auto &comb : result)
    {
        cout << "[ ";
        for (int num : comb)
            cout << num << " ";
        cout << "]\n";
    }
    return 0;
}
