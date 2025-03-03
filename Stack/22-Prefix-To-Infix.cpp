//REVIEW This code will automatically handles the reverse of the elements in the stack when  we add operators 
#include <iostream>
#include <stack>
#include <cctype>
using namespace std;
string preToInfix(string pre_exp)
{
    stack<string> s;

    // reading from right to left
    for (int i = pre_exp.length() - 1; i >= 0; i--) //REVIEW - 
    {

        // check if symbol is operator
        if (isalpha(pre_exp[i]) || isdigit(pre_exp[i]))
        {
            s.push(string(1, pre_exp[i])); //REVIEW
        }
        // If the character is not an operand, it is an operator
        else
        {
            // Pop two operands from the stack
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();

            // Concatenate the operands and the operator
            string temp = "(" + op1 + pre_exp[i] + op2 + ")";

            // Push the concatenated result back to the stack
            s.push(temp);
        }
    }

    // The stack now contains the final infix expression
    return s.top(); //REVIEW - 
}

int main()
{
    string pre_exp = "*-A/BC-/AKL";
    cout << "Infix : " << preToInfix(pre_exp);
    return 0;
}
