#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        if (n == 0)
            return "";

        int start = 0, maxLen = 1;

        for (int center = 0; center < n; ++center)
        {
            // Odd length palindrome
            expandAroundCenter(s, center, center, start, maxLen);

            // Even length palindrome
            expandAroundCenter(s, center, center + 1, start, maxLen);
        }

        return s.substr(start, maxLen);
    }

private:
    void expandAroundCenter(const string &s, int left, int right, int &start, int &maxLen)
    {
        while (left >= 0 && right < s.length() && s[left] == s[right])
        {
            if (right - left + 1 > maxLen)
            {
                start = left;
                maxLen = right - left + 1;
            }
            --left;
            ++right;
        }
    }
};
