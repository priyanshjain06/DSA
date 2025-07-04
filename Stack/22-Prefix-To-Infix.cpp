// REVIEW This code will automatically handles the reverse of the elements in the stack when  we add operators
#include <iostream>
#include <stack>
#include <cctype>
using namespace std;
string preToInfix(string pre_exp)
{
    stack<string> s;

    for (int i = pre_exp.length() - 1; i >= 0; i--) // REVIEW -
    {

        if (isalpha(pre_exp[i]) || isdigit(pre_exp[i]))
        {
            s.push(string(1, pre_exp[i])); // REVIEW
        }
        else
        {
            if (s.size() < 2)
                return "Invalid Expression";

            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();

            string temp = "(" + op1 + pre_exp[i] + op2 + ")";

            s.push(temp);
        }
    }
    return s.top(); // REVIEW -
}