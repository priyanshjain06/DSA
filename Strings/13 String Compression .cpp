// NOTE Example Input : chars = [ "a", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b" ] Output : Return 4, and the first 4 characters of the input array should be : [ "a", "b", "1", "2" ].Explanation : The groups are "a" and "bbbbbbbbbbbb".This compresses to "ab12".

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int n = chars.size();
        int write = 0; // index to write compressed result
        int read = 0;  // index to read original array

        while (read < n)
        {
            char current = chars[read];
            int count = 0;

            // Count consecutive duplicates
            while (read < n && chars[read] == current)
            {
                read++;
                count++;
            }

            // Write the character
            chars[write++] = current;

            // Write the count if more than 1
            if (count > 1)
            {
                string cntStr = to_string(count);
                for (char c : cntStr)
                {
                    chars[write++] = c;
                }
            }
        }

        return write;
    }
};
