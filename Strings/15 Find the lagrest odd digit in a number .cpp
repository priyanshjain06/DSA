// NOTE Example 2:
//  Input: num = "4206"
//  Output: ""
//  Explanation: There are no odd numbers in "4206".
//  Example 3:

// Input: num = "35427"
// Output: "35427"
// Explanation: "35427" is already an odd number.

#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    string largestOddNumber(string num)
    {
        for (int i = num.length() - 1; i >= 0; i--)
        {
            if ((num[i]) % 2 != 0)
            {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};