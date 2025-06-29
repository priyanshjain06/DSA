// LINK you can use hasharray also here

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int NumberOfSubstring(string s, int n)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        unordered_map<char, int> hashmap; // REVIEW -

        for (int j = i; j < n; j++)
        {
            hashmap[s[j]] = 1;

            if (hashmap['a'] + hashmap['b'] + hashmap['c'] == 3)
            {
                // All substrings from j to end of s are valid
                count += (n - j); // REVIEW -

                // Break out of the loop since all further substrings are valid
                break; // REVIEW -
            }
        }
    }
    return count;
}
