// REVIEW  O(4^n/root of n) and Space Complexity : O(n)
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Helper function to generate the well-formed parentheses combinations
    void generateParenthesisHelper(int n, int open, int close, string current, vector<string> &result)
    {
        // Base case: when the current string is of length 2*n, we have a valid combination
        if (current.length() == 2 * n)
        {
            result.push_back(current);
            return;
        }

        // If we can add an opening parenthesis
        if (open < n)
        {
            generateParenthesisHelper(n, open + 1, close, current + '(', result);
        }

        // If we can add a closing parenthesis
        if (close < open)
        {
            generateParenthesisHelper(n, open, close + 1, current + ')', result);
        }
    }

    // Main function to generate all combinations of well-formed parentheses
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        generateParenthesisHelper(n, 0, 0, "", result); // Start with an empty string
        return result;
    }
};

int main()
{
    Solution sol;
    int n;
    cout << "Enter the number of pairs of parentheses: ";
    cin >> n;

    vector<string> result = sol.generateParenthesis(n);

    // Print the result
    cout << "Well-formed parentheses combinations of " << n << " pairs:\n";
    for (const string &s : result)
    {
        cout << s << endl;
    }

    return 0;
}
