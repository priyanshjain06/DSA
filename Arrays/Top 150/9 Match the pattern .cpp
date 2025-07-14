#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> pToWord;
        unordered_map<string, char> wordToP;

        istringstream iss(s);
        string word;
        int i = 0;

        while (iss >> word)
        {
            if (i >= pattern.size())
                return false;

            char c = pattern[i];

            // Check char-to-word mapping
            if (pToWord.count(c))
            {
                if (pToWord[c] != word)
                    return false;
            }
            else
            {
                pToWord[c] = word;
            }

            // Check word-to-char mapping
            if (wordToP.count(word))
            {
                if (wordToP[word] != c)
                    return false;
            }
            else
            {
                wordToP[word] = c;
            }

            i++;
        }

        // If pattern has more characters left
        return i == pattern.size();
    }
};
