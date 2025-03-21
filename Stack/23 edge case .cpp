//{ Driver Code Starts
// Initial Template for C++
#include <iostream>
#include <stack>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution
{
public:
    string postToPre(string post_exp)
    {
        stack<string> s;

        // Process from left to right
        for (int i = 0; i < post_exp.length(); i++)
        {
            char ch = post_exp[i];

            // If operand, push it as a string onto the stack
            if (isalnum(ch))
            {                          // isalnum() checks if ch is a letter or digit
                s.push(string(1, ch)); // Convert char to string and push
            }
            else
            { // Operator case
                if (s.size() < 2)
                    return "Invalid Expression"; // Edge case

                string operand2 = s.top();
                s.pop(); // Right operand
                string operand1 = s.top();
                s.pop(); // Left operand

                // Form the prefix expression
                string newExp = ch + operand1 + operand2;

                // Push back the new expression
                s.push(newExp);
            }
        }

        // The final prefix expression should be the only element in the stack
        return s.top(); // REVIEW
    }
};
