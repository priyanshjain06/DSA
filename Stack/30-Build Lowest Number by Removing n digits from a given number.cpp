// NOTE Given a string ‘str’ of digits and an integer ‘n’, build the lowest possible number by removing ‘n’ digits from the string and not changing the order of input digits.

// LINK : edge cases to handle : 11111 and 00000 and 00001 and 123456 and k==n

// REVIEW this question doesnt mention that we change the order so we need to maintain the order !

#include <iostream>
using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        string result = ""; // Acts as a stack

        for (char c : num)
        {
            // Remove larger digits when a smaller digit is encountered
            while (!result.empty() && k > 0 && result.back() > c)
            {
                result.pop_back(); // Acts like stack.pop()
                k--;
            }

            // Avoid leading zeros
            if (!result.empty() || c != '0')
            {
                result.push_back(c);
            }
        }

        // Remove remaining digits if k is still greater than 0
        while (!result.empty() && k > 0)
        {
            result.pop_back();
            k--;
        }

        // If result is empty, return "0"
        return result.empty() ? "0" : result;
    }
};
