#include <iostream>
#include <stack>
#include <cctype>
using namespace std;
string getInfix(string exp)
{
    stack<string> s; // REVIEW -  STACK TO STORE STRINGS  , use => <string>

    for (int i = 0; i < exp.length(); i++) // REVIEW -
    {
        // Push operands
        if (isalpha(exp[i]) || isdigit(exp[i]))
        {

            // In this code, the stack s is declared as a stack of strings (stack<string>), but exp[i] is a character.
            s.push(string(1, exp[i])); //REVIEW - 
        }

        // We assume that input is
        // a valid postfix and expect
        // an operator.
        else
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push("(" + op2 + exp[i] +
                   op1 + ")"); // REVIEW  carrefully see the op
        }
    }

    // There must be a single element
    // in stack now which is the required
    // infix.
    return s.top(); // REVIEW -
}

// Driver code
int main()
{
    string exp = "ab*c+";
    cout << getInfix(exp);
    return 0;
}
