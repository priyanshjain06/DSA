// NOTE Given a string s consisting only of lowercase English letters, count the number of contiguous substrings that contain at least one occurrence of each of the characters 'a', 'b', and 'c'.

//  ANCHOR Time Complexity : O(n^2) and Space Complexity : O(3)

// LINK use unordered_map (conecpt of hashmap) use can also use hash array

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int NumberOfSubstring(string s, int n)
{
    int count = 0;

    unordered_map<char, int> hashmap; // REVIEW -

    for (int i = 0; i < n; i++)
    {
        hashmap[3] = 0;

        for (int j = i; j < n; j++)
        {
            hashmap[s[j]] = 1;

            if (hashmap['a'] + hashmap['b'] + hashmap['c'] == 3)
            {
                count = count++;
                break; // REVIEW -
            }
        }
    }
    return count;
}

int main()
{
    string s = "abcbabacab";
    int n = s.size();
    cout << "The number of substrings containing at least 'a', 'b', and 'c' is: " << NumberOfSubstring(s, n) << "\n";
    return 0;
}
