// NOTE -  Example "Jain" "Niaj"

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string str = "babbar";

    stack<char> stack;

    for (int i = 0; i < str.length(); i++) // REVIEW -
    {
        char ch = str[i];
        stack.push(ch);
    }

    // LINK this is not the ideal way to reverse a string it is not optimal

    string ans = ""; // REVIEW -

    while (!stack.empty())
    {
        char ch = stack.top();
        ans.push_back(ch); // REVIEW -

        stack.pop();
    }

    cout << "answer is: " << ans << endl;

    return 0;
}