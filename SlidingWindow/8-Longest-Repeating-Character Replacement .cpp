#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int characterReplacement(string s, int k)
{
    int left = 0, right = 0, maxLen = 0, maxFreq = 0;
    vector<int> freq(26, 0); // REVIEW -

    while (right < s.size())
    {
        freq[s[right] - 'A']++;
        maxFreq = max(maxFreq, freq[s[right] - 'A']); // Track the max occurring character count

        // If window is invalid, shrink from left
        while ((right - left + 1) - maxFreq > k)
        {
            freq[s[left] - 'A']--;
            left++;
        }

        maxLen = max(maxLen, right - left + 1); // Update max length
        right++;
    }
    return maxLen;
}