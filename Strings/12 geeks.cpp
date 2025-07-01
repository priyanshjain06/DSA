#include <iostream>
#include <string>
using namespace std;

string removeUtil(string &s)
{
    int len = s.length(); // Get the length of the input string.
    int n = len;          // Store the original length for reference.
    int k = 0;            // Pointer to track where to place non-duplicate characters.

    // Traverse the string
    for (int i = 0; i < n; i++)
    {
        // Skip all adjacent duplicates
        while (i < n - 1 && s[i] == s[i + 1])
        {
            i++;
        }
        // Keep the non-duplicate character
        s[k++] = s[i];
    }

    s.erase(k); // Remove leftover characters after k

    if (k != n)        // REVIEW      // If any duplicates were removed
        removeUtil(s); // Recursively remove duplicates again

    return s; // REVIEW
}