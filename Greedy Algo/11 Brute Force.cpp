#include <iostream>
using namespace std;

class Solution
{
public:
    bool backtrack(string &s, int index, int balance)
    {
        // Base case: If we've processed the entire string
        if (index == s.size())
        {
            return balance == 0;
        }

        // If balance goes negative, it's an invalid sequence
        if (balance < 0)
        {
            return false;
        }

        // Recursive cases based on character at current index
        if (s[index] == '(')
        {
            return backtrack(s, index + 1, balance + 1);
        }
        else if (s[index] == ')')
        {
            return backtrack(s, index + 1, balance - 1);
        }
        else
        { // If it's '*', explore all three possibilities
            return backtrack(s, index + 1, balance + 1) || // '*' as '('
                   backtrack(s, index + 1, balance - 1) || // '*' as ')'
                   backtrack(s, index + 1, balance);       // '*' as empty
        }
    }

    bool checkValidString(string s)
    {
        return backtrack(s, 0, 0);
    }
};

// Driver Code for Testing
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
