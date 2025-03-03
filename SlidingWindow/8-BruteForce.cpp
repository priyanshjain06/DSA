// NOTE Given a string s consisting of lowercase English letters and an integer k, find the length of the longest contiguous substring where you can make at most k changes to make all characters in the substring identical

// NOTE Input: s = "aabccbb", k = 2
//  Output: 5
//  Explanation: You can replace two characters in the substring "aabccbb" to get "aaaaa", which is the longest substring with identical characters.

// LINK use unordered_map

// ANCHOR time complexity : O(n*n) and space complexity : O(1)

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int MaxLen(string s, int k)
{
    int maxLen = 0;

    for (int i = 0; i < s.length(); i++)
    {
        unordered_map<char, int> hashmap;
        int maxFreq = 0;

        for (int j = i; j < s.length(); j++)
        {
            hashmap[s[j] - 'a']++;
            maxFreq = max(maxFreq, hashmap[s[j]]);

            // Calculate the number of changes needed
            int changes = (j - i + 1) - maxFreq;

            if (changes <= k)
                maxLen = max(maxLen, j - i + 1);
            else
                break;
        }
    }

    return maxLen;
}

int main()
{
    string s = "aabccbb";
    int k = 2;
    cout << "The maximum length of substring with at most " << k << " changes is: " << MaxLen(s, k) << "\n";
    return 0;
}
