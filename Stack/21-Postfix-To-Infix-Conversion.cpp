// REVIEW The reason for using a stack of strings (stack<string>) instead of a stack of characters (stack<char>) is because we need to build and store entire subexpressions as strings.

#include <iostream>
#include <stack>
#include <cctype>
using namespace std;
string getInfix(string exp)
{
    stack<string> s; // REVIEW -  STACK TO STORE STRINGS  , use => <string>

    for (int i = 0; i < exp.length(); i++) // REVIEW -
    {
        if (isalpha(exp[i]) || isdigit(exp[i]))
        {

            // In this code, the stack s is declared as a stack of strings (stack<string>), but exp[i] is a character.

            // is used to convert a single character (exp[i]) into a string and push it onto the stack.

            s.push(string(1, exp[i])); // REVIEW -
        }

        else
        {
            if (s.size() < 2)
                return "Invalid Expression"; // REVIEW  Edge case

            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push("(" + op2 + exp[i] +
                   op1 + ")"); // REVIEW  carrefully see the op
        }
    }
    return s.top(); // REVIEW this will contain the final entire string
}