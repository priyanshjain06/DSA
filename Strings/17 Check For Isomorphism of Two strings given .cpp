#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size()) // REVIEW -
        {
            return false;
        }
        
        unordered_map<char, char> mapS, mapT; //FIXME 

        for (int i = 0; i < s.size(); i++) 
        {
            // If a mapping exists, check if it matches the current character
            if (mapS.count(s[i]) && mapS[s[i]] != t[i]) // REVIEW map.count
            {
                return false; // Mismatch found in s -> t mapping
            }
            mapS[s[i]] = t[i]; // Create or update the mapping from s to t

            if (mapT.count(t[i]) && mapT[t[i]] != s[i])
            {
                return false;
            }
            mapT[t[i]] = s[i];
        }

        return true;
    }
};

// REVIEW Why two maps:-
// For example, if 'a' maps to 'b' and 'b' also maps to 'b', the strings would not be isomorphic because multiple characters from s are being mapped to the same character in t.if (mapT.count(t[i]) && mapT[t[i]] != s[i])