// REVIEW
//  1) reverse the given infix
//  2) now infix to postfix apply
//  3) now reverse the postix which is your prefix

#include <iostream>
#include <stack>
#include <cctype>
#include <string>
#include <algorithm> //REVIEW -  for reverse

using namespace std;

bool isOperator(char c)
{
    return (!isalpha(c) && !isdigit(c)); // REVIEW -
}

int getPriority(char c)
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

string infixToPostfix(string infix)
{
    infix = '(' + infix + ')';
    int l = infix.size(); //REVIEW - 
    stack<char> char_stack;
    string output;

    for (int i = 0; i < l; i++)
    {

        // If the scanned character is an
        // operand, add it to output.
        if (isalpha(infix[i]) || isdigit(infix[i]))
            output += infix[i];

        // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if (infix[i] == '(')
            char_stack.push('(');

        // If the scanned character is an
        // ‘)’, pop and output from the stack
        // until an ‘(‘ is encountered.
        else if (infix[i] == ')')
        {
            while (char_stack.top() != '(')
            {
                output += char_stack.top();
                char_stack.pop();
            }

            // Remove '(' from the stack
            char_stack.pop();
        }

        // Operator found
        else
        {
            if (isOperator(char_stack.top()))
            {
                if (infix[i] == '^') // REVIEW -
                {
                    while (getPriority(infix[i]) <= getPriority(char_stack.top())) // REVIEW - <= note this
                    {
                        output += char_stack.top();
                        char_stack.pop();
                    }
                }
                else
                {
                    while (getPriority(infix[i]) < getPriority(char_stack.top())) // REVIEW  < note this
                    {
                        output += char_stack.top();
                        char_stack.pop();
                    }
                }

                // Push current Operator on stack
                char_stack.push(infix[i]);
            }
        }
    }
    while (!char_stack.empty())
    {
        output += char_stack.top();
        char_stack.pop();
    }
    return output;
}

string infixToPrefix(string infix) // REVIEW
{
    /* Reverse String
     * Replace ( with ) and vice versa
     * Get Postfix
     * Reverse Postfix  *  */
    int l = infix.size();

    // Reverse infix
    reverse(infix.begin(), infix.end());

    // Replace ( with ) and vice versa
    for (int i = 0; i < l; i++)
    {

        if (infix[i] == '(')
        {
            infix[i] = ')';
            i++;
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
            i++;
        }
    }

    string prefix = infixToPostfix(infix);

    // Reverse postfix
    reverse(prefix.begin(), prefix.end());

    return prefix;
}

int main()
{
    string s = ("(p+q)*(c-d)");
    cout << "Infix expression: " << s << endl;
    cout << "Prefix Expression: " << infixToPrefix(s) << endl;
    return 0;
}
