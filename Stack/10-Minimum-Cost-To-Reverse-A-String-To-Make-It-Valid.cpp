// NOTE This question is also called as minimum bracket reversal

// REVIEW -  Follow these 3 steps :
//  1) If brackets are odd then return -1
//  2) Then remove the valid part of the string : eg : ' {{{ }} ' then remove {{}} and then push the remaning part of the string in the stack [ '{' this will be pushed]
//  3) Then count the number of open and closed bracketes , and use the  formula  (a + 1) / 2 + (b + 1) / 2  to find the minimum cost

#include <stack>
#include <iostream>
using namespace std;
int findMinimumCost(string str)
{
    // odd condition:
    if (str.length() % 2 == 1)
    {
        return -1;
    }

    stack<char> s;
    
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if (ch == '{')
            s.push(ch);
        else
        {
            // ch is closed brace
            if (!s.empty() && s.top() == '{')
            {
                s.pop();
            }
            else
            // REVIEW when no corresponding bracket is found example :{{}
            {
                s.push(ch);
            }
        }
    }

    // stack contains invalid expression
    int a = 0, b = 0;    while (!s.empty())

    {
        if (s.top() == '{')
        {
            b++;
        }
        else
        {
            a++;
        }
        s.pop();
    }

    int ans = (a + 1) / 2 + (b + 1) / 2; // REVIEW -
    return ans;
}