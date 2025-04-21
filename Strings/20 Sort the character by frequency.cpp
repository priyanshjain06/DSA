#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    string frequencySort(string s)
    {
        // Step 1: Count character frequencies
        unordered_map<char, int> freq; // REVIEW

        for (char c : s)
            freq[c]++;

        // Step 2: Sort characters by frequency and lexicographical order
        sort(s.begin(), s.end(), [&](char a, char b) // FIXME
             {
                 if (freq[a] == freq[b])
                     return a < b; // If equal frequency, sort lexicographically (a before b)

                 return freq[a] > freq[b]; // Otherwise, sort by frequency (higher first)
             });

        return s; // Return the sorted string
    }
};
