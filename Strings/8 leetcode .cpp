#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void reverseString(string &str, int start, int end)
    {
        while (start < end)
        {
            swap(str[start], str[end]);
            start++;
            end--;
        }
    }

    string reverseOrderWords(string str)
    {
        int n = str.size();

        // Step 1: Reverse the whole string
        reverseString(str, 0, n - 1);

        // Step 2: Reverse each word
        int start = 0;
        for (int i = 0; i <= n; ++i)
        {
            if (i == n || str[i] == ' ')
            {
                reverseString(str, start, i - 1);
                start = i + 1;
            }
        }

        return str;
    }
};