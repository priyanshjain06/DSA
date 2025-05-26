#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        if (s.length() != goal.length())
            return false;

        for (int i = 0; i < s.length(); ++i) //REVIEW ++i
        {
            // Try rotating the string `s` and compare with `goal`
            string rotated = s.substr(i) + s.substr(0, i); //FIXME 
            if (rotated == goal)
            {
                return true;
            }
        }
        return false;
    }
};
// REVIEW substr(i) from i to end

// REVIEW time : O(n^2) and Space : O(n)
