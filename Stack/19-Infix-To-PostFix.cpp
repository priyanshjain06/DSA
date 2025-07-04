#include <iostream>
#include <stack>
#include <cctype> //REVIEW
using namespace std;
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
void infixToPostfix(string s)
{

    stack<char> st; // REVIEW - character stack
    string result;
    for (int i = 0; i < s.length(); i++) // REVIEW .length for string
    {
        char c = s[i];

        // If the scanned character is
        // an operand, add it to output string.
        if (isalpha(c) || isdigit(c))
            result += c;

        // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if (c == '(')
            st.push('(');

        // If the scanned character is an ‘)’,
        // pop and to output string from the stack
        // until an ‘(‘ is encountered.
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }

        // If an operator is scanned
        else
        {
            while (!st.empty() && prec(s[i]) <= prec(st.top()))
            // REVIEW - <= note this
            {
                result += st.top();
                st.pop();
            }
            st.push(c); // REVIEW -
        }
    }

    // Pop all the remaining elements from the stack
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    cout << "Prefix expression: " << result << endl;
}

int main()
{
    string exp = "(p+q)*(m-n)";
    cout << "Infix expression: " << exp << endl;
    infixToPostfix(exp);
    return 0;
}