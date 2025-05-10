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
        return (s1 + s1).find(s2) != string::npos; // REVIEW
    }
};

// REVIEW time : O(n) and Space : O(1)

// REVIEW : If you want to return the index
class Solution
{
public:
    // Returns the starting index of rotation if valid, otherwise -1
    int findRotationIndex(string &s1, string &s2)
    {
        if (s1.length() != s2.length())
            return -1; // Not rotations if lengths differ

        string concatenated = s1 + s1;
        size_t index = concatenated.find(s2);

        // Convert size_t to int (npos becomes -1)
        return (index != string::npos) ? static_cast<int>(index) : -1;
    }
};
