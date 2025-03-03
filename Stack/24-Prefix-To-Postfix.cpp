#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;
string preToPost(string pre_exp)
{
    stack<string> s;

    // reading from right to left //REVIEW -
    for (int i = pre_exp.length() - 1; i >= 0; i--)
    {
        if (isalpha(pre_exp[i]) || isdigit(pre_exp[i]))
        {

            s.push(string(1, pre_exp[i]));
        }
        else
        {
            // pop two operands from stack
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();

            // concat the operands and operator
            string temp = op1 + op2 + pre_exp[i]; 
            // REVIEW - just reverse abc => cba

            s.push(temp);
        }

        // if symbol is an operand
    }

    return s.top(); // REVIEW -
}
int main()
{
    string pre_exp = "*-A/BC-/AKL";
    cout << "Postfix : " << preToPost(pre_exp);
    return 0;
}
