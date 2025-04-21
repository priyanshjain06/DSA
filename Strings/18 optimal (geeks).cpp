#include <string>
using namespace std;

class Solution
{
public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2)
    {
        // If lengths are not equal, they cannot be rotations of each other
        if (s1.length() != s2.length())
            return false;

        // Check if s2 is a substring of s1 + s1
        return (s1 + s1).find(s2) != string::npos;
    }
};

//REVIEW time and space complexity is O(n) both 
