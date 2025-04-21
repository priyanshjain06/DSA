// NOTE Atoi means to convert the string to integer following some rules

#include <iostream>
#include <string>
#include <climits> // for INT_MAX and INT_MIN
using namespace std;
class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0, n = s.length();
        // Step 1: Ignore leading whitespaces
        while (i < n && isspace(s[i])) // REVIEW
        {
            i++;
        }

        // Step 2: Check sign :
        int sign = 1;
        if (i < n && (s[i] == '-' || s[i] == '+'))
        {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Convert digits to integer
        long long result = 0;
        while (i < n && isdigit(s[i]))
        {
            result = result * 10 + (s[i] - '0');
            // E.g., "123" becomes:
            // result = 0 → 0 * 10 + 1 = 1
            // result = 1 → 1 * 10 + 2 = 12
            // result = 12 → 12 * 10 + 3 = 123

            // Step 4: Handle overflow
            if (result * sign > INT_MAX)
                return INT_MAX;
            if (result * sign < INT_MIN)
                return INT_MIN;
            i++;
        }
        return result * sign; // REVIEW -
    }
};
