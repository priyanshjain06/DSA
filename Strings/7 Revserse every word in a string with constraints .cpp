#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    void trimSpaces(string &s)
    {
        int n = s.size();
        int i = 0, j = 0;

        // Skip leading spaces
        while (i < n && s[i] == ' ')
            i++;

        // Process rest 
        while (i < n)
        {
            // Copy non-space character
            if (s[i] != ' ')
            {
                s[j++] = s[i++];
            }
            // Handle single space between words
            else if (j > 0 && s[j - 1] != ' ')
            {
                s[j++] = ' ';
                i++;
            }
            else
            {
                i++;
            }
        }

        // Remove trailing space if present
        if (j > 0 && s[j - 1] == ' ')
            j--;

        s.resize(j); // Resize to final trimmed length
    }

    void reverse(string &s, int left, int right)
    {
        while (left < right)
        {
            swap(s[left++], s[right--]);
        }
    }

    string reverseWords(string s)
    {
        trimSpaces(s);

        // Step 2: reverse entire string
        reverse(s, 0, s.size() - 1);

        // Step 3: reverse each word in place
        int start = 0;
        for (int end = 0; end <= s.size(); ++end) //REVIEW ++end 
        {
            if (end == s.size() || s[end] == ' ')
            {
                reverse(s, start, end - 1);
                start = end + 1;
            }
        }

        return s;
    }
};