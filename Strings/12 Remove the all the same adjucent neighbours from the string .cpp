// NOTE :1047. Remove All Adjacent Duplicates In String

// Example - Input: s = "abbaca"
// Output: "ca"
// Explanation:
// For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    string removeDuplicates(string s)
    {
        int n = s.length();
        int i = 0; // Index for the next character to place
        int j = 0;
        while (j < n)
        {
            if (i > 0 && s[j] == s[i - 1])
            {
                // If duplicate, "remove" the previous character by decrementing the index
                i--;
            }
            else
            {
                // Place the current character at the next available position
                s[i] = s[j];
                i++;
            }
            j++;
        }

        // Construct the final string using the first `i` characters
        return s.substr(0, i); // REVIEW -
    }
};
