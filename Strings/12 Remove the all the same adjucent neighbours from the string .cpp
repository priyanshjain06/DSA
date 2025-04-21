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
    string removeUtil(string &s)
    {
        int n = s.length();
        bool changed = false; // Flag to track if changes were made

        string temp = "";

        // Remove adjacent duplicates in one pass
        for (int i = 0; i < n; ++i)
        {
            if (!temp.empty() && temp.back() == s[i])
            {
                temp.pop_back(); // Remove duplicate
                changed = true;
            }
            else
            {
                temp.push_back(s[i]);
            }
        }

        return temp; // Return result
    }
};
