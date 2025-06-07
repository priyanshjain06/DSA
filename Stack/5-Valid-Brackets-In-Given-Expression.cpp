//REVIEW 2 edge cases : closing bracket  at start and if the stack is not empty at the end
#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (char ch : s)
        {
            // If it's an opening bracket, push it onto the stack
            if (ch == '(' || ch == '{' || ch == '[')
            {
                st.push(ch);
            }
            else
            {
                // If the stack is empty, return false (no matching opening bracket)
                if (st.empty())
                    return false;

                // Check if the top element of the stack matches the current closing bracket
                char top = st.top();
                if ((ch == ')' && top == '(') ||
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '['))
                {
                    st.pop(); // Matched, remove the top
                }
                else
                {
                    return false; // Mismatch
                }
            }
        }
        return st.empty(); // If stack is empty, parentheses are balanced
    }
};
