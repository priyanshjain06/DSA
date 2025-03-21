#include <iostream>
#include <stack>
using namespace std;

string removeKdigits(string num, int k)
{
    int n = num.size();
    stack<char> mystack; // REVIEW -
    for (char c : num)
    {
        while (!mystack.empty() && k > 0 && mystack.top() > c)
        {
            mystack.pop();
            k--;
        }

        if (!mystack.empty() || c != '0') // REVIEW -  for leading zero
            mystack.push(c);              // REVIEW It will push the value in the stack if stack is empty
    }

    // Now remove the largest values from the top of the
    // stack
    // REVIEW -  for 123456
    while (!mystack.empty() && k--)
        mystack.pop();

    // REVIEW - 0000 or no value in the stack is left example :1111111
    if (mystack.empty())
        return "0";

    // Now retrieve the number from stack into a string
    // (reusing num)
    while (!mystack.empty())
    {
        num[n - 1] = mystack.top(); // REVIEW -  reverse order
        mystack.pop();
        n--;
    }
    return num.substr(n);
}

int main()
{
    string str = "765028321";
    int k = 5;
    cout << removeKdigits(str, k);
    return 0;
}
