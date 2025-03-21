#include <iostream>
#include <stack>
#include <algorithm> // For reverse function
#include <cctype>    // For isalpha and isdigit

using namespace std;

// Function to check precedence of operators
int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    return -1;
}

// Function to convert infix to postfix
string infixToPostfix(string s)
{
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        // If the character is an operand, add it to the output string.
        if (isalnum(c)) // REVIEW isalnum means  is alpha or digit
            result += c;

        // If the character is '(', push it onto the stack.
        else if (c == '(')
            st.push(c);

        // If the character is ')', pop from stack to output until '(' is encountered.
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop(); // Remove '(' from the stack.
        }

        // If an operator is encountered.
        else
        {
            while (!st.empty() && precedence(st.top()) >= precedence(c))
            {
                // Handle right-associative '^' properly.
                if (c == '^' && st.top() == '^')
                    break;

                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop all remaining operators from the stack
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    return result;
}