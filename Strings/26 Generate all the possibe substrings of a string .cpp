// NOTE Time complexity : O(n^2) and space complexity : O(n) => most optimal
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> generateSubstrings(const string &s)
{
    vector<string> substrings;
    int n = s.length();

    // Outer loop: Fix the starting index of the substring
    for (int i = 0; i < n; i++)
    {
        string current = ""; // Temporary string to hold the substring

        // Inner loop: Extend the substring
        for (int j = i; j < n; j++)
        {
            current += s[j];               // Append character to current substring
            substrings.push_back(current); // Store the substring
        }
    }

    return substrings;
}

