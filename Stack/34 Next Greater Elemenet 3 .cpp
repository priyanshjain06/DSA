#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int nextGreaterElement(int n)
    {
        string s = to_string(n);
        int i = s.length() - 2; // REVIEW

        // Step 1: Find the pivot
        // The pivot is the first digit from the right that is smaller than its next digit.

        while (i >= 0 && s[i] >= s[i + 1])
        {
            i--;
        }

        // If no pivot is found, return -1
        if (i < 0)
            return -1;

        // Step 2: Find the successor
        int j = s.length() - 1;
        while (s[j] <= s[i])
        {
            j--;
        }

        // Step 3: Swap pivot and successor
        swap(s[i], s[j]);

        // Step 4: Reverse the suffix
        reverse(s.begin() + i + 1, s.end());

        // Step 5: Convert back to integer and check range
        long ans = stoi(s);
        return (ans > INT_MAX) ? -1 : static_cast<int>(ans); // REVIEW
    }
};