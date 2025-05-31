// NOTE : Example 1:
// Input: s = "(()())(())"
// Output: "()()()"
// Explanation:
// The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
// After removing outer parentheses of each part, this is "()()" + "()" = "()()()".

// NOTE Input: s = "(()())(())(()(()))"
//  Output: "()()()()(())"
//  Explanation:
//  The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
//  After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".

// NOTE Example 3:
//  Input: s = "()()"
//  Output: ""
//  Explanation:
//  The input string is "()()", with primitive decomposition "()" + "()".
//  After removing outer parentheses of each part, this is "" + "" = "".

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        int balance = 0;
        string result = "";

        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '(')
            {
                if (balance > 0)
                {
                    result += s[i]; // Append only if we are inside a valid primitive string
                }
                balance++;
            }
            else
            {
                balance--;
                if (balance > 0)
                {
                    result += s[i]; // Append only if we are inside a valid primitive string
                }
            }
        }

        return result;
    }
};