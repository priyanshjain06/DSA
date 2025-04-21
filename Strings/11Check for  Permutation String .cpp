// NOTE Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.                                                                           //In other words,
//  return true if one of s1's permutations is the substring of s2.
// EXAMPLE :
//  s1 = "ab" s2 = "eidbaooo" => true

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 > n2)
            return false;

        // Frequency arrays for characters in 'a' to 'z'
        vector<int> freq1(26, 0), freq2(26, 0);

        // Populate frequency array for s1
        for (char c : s1)
            freq1[c - 'a']++;

        // Initialize the first window in s2
        for (int i = 0; i < n1; i++)
            freq2[s2[i] - 'a']++;

        // Check for permutation in the first window
        if (freq1 == freq2)
            return true;

        // Slide the window over s2
        for (int i = n1; i < n2; i++)
        {
            freq2[s2[i] - 'a']++;      // Add the current character to the window
            freq2[s2[i - n1] - 'a']--; // Remove the first character of the previous window

            if (freq1 == freq2)
                return true; // Check if the current window matches
        }

        return false; // No permutation found
    }
};
