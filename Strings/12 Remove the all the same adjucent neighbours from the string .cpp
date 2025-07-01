#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    string removeUtil(string &s)
    {
        int n = s.length();

        string temp = "";

        // Remove adjacent duplicates in one pass
        for (int i = 0; i < n; ++i) // REVIEW - ++i
        {
            if (!temp.empty() && temp.back() == s[i])
            {
                temp.pop_back(); // Remove duplicate
            }
            else
            {
                temp.push_back(s[i]);
            }
        }

        return temp; // Return result
    }
};