#include <iostream>
#include <stack>
#include <string>
class Solution
{
public:
    int calculate(string s)
    {
        int result = 0, sign = 1;
        stack<int> stk; // REVIEW -
        int n = s.size();
        int i = 0;

        while (i < n)
        {
            char c = s[i];
            if (isdigit(c))
            {
                int num = 0;
                while (i < n && isdigit(s[i]))
                {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                result += sign * num;
                continue; // REVIEW  continue because we already moved i
            }
            else if (c == '+')
            {
                sign = 1;
            }
            else if (c == '-')
            {
                sign = -1;
            }
            else if (c == '(')
            {
                // Push current result and sign to stack for later
                stk.push(result);
                stk.push(sign);
                // Reset result and sign for new sub-expression
                result = 0;
                sign = 1;
            }
            else if (c == ')')
            {
                //REVIEW first sign and then result 
                int prevSign = stk.top();
                stk.pop();
                int prevResult = stk.top();
                stk.pop();
                result = prevResult + prevSign * result;
            }
            i++;
        }
        return result; // REVIEW
    }
};
