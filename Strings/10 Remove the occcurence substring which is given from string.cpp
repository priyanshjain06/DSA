// NOTE : Example : part to remove abc
//  string : daabcabc => daabc=> da
// NOTE Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        string result;
        int partLen = part.size();

        // Iterate through the string character by character
        for (char c : s)
        {
            result.push_back(c);

            // If the last 'partLen' characters in the result match 'part', remove them
            if (result.size() >= partLen && result.substr(result.size() - partLen) == part)
            {
                result.erase(result.size() - partLen); // Remove last 'partLen' characters
            }
        }
        return result;
    }
};
