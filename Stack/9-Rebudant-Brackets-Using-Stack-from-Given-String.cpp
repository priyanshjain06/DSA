// LINK : rebudant means the useless bracket eg ((a+b)) is redundant

// REVIEW : The Logic is to find the  operator between first closing and last opening bracket , If no operator is found then it is redundant

// NOTE - 2 edge cases :
//   remove the opening bracket at the start if the stack is not empty at the end
//  if still redundant is true for any loop then return true !

#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    int checkRedundancy(string s)
    {
        stack<char> st;

        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];

            // Push opening bracket & operators onto stack
            if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
            {
                st.push(ch);
            }
            else
            {
                // If closing bracket encountered
                if (ch == ')')
                {
                    bool isRedundant = true;

                    // Check if there is an operator inside the parenthesis
                    while (!st.empty() && st.top() != '(')
                    {
                        char top = st.top();
                        if (top == '+' || top == '-' || top == '*' || top == '/')
                        {
                            isRedundant = false;
                        }
                        st.pop();
                    }

                    // Pop the opening '('
                    if (!st.empty())
                    {
                        st.pop();
                    }

                    // If no operator found, it's redundant
                    if (isRedundant)
                    {
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
};
