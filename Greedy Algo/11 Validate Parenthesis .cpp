#include <iostream>
using namespace std;

class Solution
{
public:
    bool checkValidString(string s)
    {
        int low = 0, high = 0;

        for (char c : s)
        {
            if (c == '(')
            {
                low++;  // '(' increases min open count
                high++; // '(' increases max open count
            }
            else if (c == ')')
            {
                low--;  // ')' decreases min open count
                high--; // ')' decreases max open count
            }
            else
            {           // '*' can be '(', ')' or ''
                low--;  // '*' as ')'
                high++; // '*' as '('
            }

            if (low < 0)
                low = 0; // Ensure min open count never goes negative

            // If max open count is negative, too many ')' -> invalid
            if (high < 0)
                return false;
        }
        if (low == 0)
            return 1;
        return 0;
    }
};

// Driver code for testing
int main()
{
    Solution sol;
    string s;
    cout << "Enter a string: ";
    cin >> s;

    if (sol.checkValidString(s))
        cout << "Valid Parenthesis String\n";
    else
        cout << "Invalid Parenthesis String\n";

    return 0;
}
