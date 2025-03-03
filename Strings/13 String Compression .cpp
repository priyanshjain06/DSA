// NOTE Example Input : chars = [ "a", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b" ] Output : Return 4, and the first 4 characters of the input array should be : [ "a", "b", "1", "2" ].Explanation : The groups are "a" and "bbbbbbbbbbbb".This compresses to "ab12".

#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    string compress(string s)
    {
        int n = s.length();
        if (n == 0)
            return s;

        int i = 0, count = 0;
        string result = "";

        while (i < n)
        {
            char current = s[i];
            count = 0;

            // Count consecutive characters
            while (i < n && s[i] == current)
            {
                count++;
                i++;
            }

            // Append the character and its count (if > 1)
            result += current;
            if (count > 1)
            {
                result += to_string(count);
            }
        }

        return result.length() < n ? result : s; // Return compressed string only if it's smaller
    }
};