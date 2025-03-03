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
        unordered_map<char, int> freq;
        
        for (char c : s)
            freq[c]++;

        // Step 2: Sort characters by frequency and lexicographical order
        sort(s.begin(), s.end(), [&](char a, char b)
             {
                 if (freq[a] == freq[b])
                     return a < b;         // Natural order for equal frequencies
                 return freq[a] > freq[b]; // Descending frequency order
             });

        return s; // Return the sorted string
    }
};
