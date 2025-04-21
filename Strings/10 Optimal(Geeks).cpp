#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    string removeChars(string str1, string str2)
    {
        // Convert str2 to a set for fast lookup
        unordered_set<char> setStr2(str2.begin(), str2.end()); //FIXME 
        string result;

        // Traverse str1 and add characters to result if not in setStr2
        for (char c : str1)
        {
            if (setStr2.find(c) == setStr2.end())
            {
                result.push_back(c); // Only add if it's not in str2
            }
        }

        return result;
    }
};