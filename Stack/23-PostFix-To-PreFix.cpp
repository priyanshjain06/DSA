// LINK another way to solve this will be convert postfix to infix and infix to prefix
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;
string postToPre(string post_exp)
{
    stack<string> s; // REVIEW
    for (int i = 0; i < post_exp.length(); i++)
    {
        if (isalpha(post_exp[i]) || isdigit(post_exp[i]))
        {
            s.push(string(1, post_exp[i]));
        }
        else
        {
            if (s.size() < 2)
                return "Invalid Expression"; // Edge case

            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();

            string temp = post_exp[i] + op2 + op1; // REVIEW - no brackets

            s.push(temp);
        }
    }

    string ans = ""; // REVIEW

    while (!s.empty()) // REVIEW
    {
        ans += s.top();
        s.pop();
    }
    return ans;
}

int main()
{
    string post_exp = "ABC/-AK/L-*";

    cout << "Prefix : " << postToPre(post_exp);
    return 0;
}
