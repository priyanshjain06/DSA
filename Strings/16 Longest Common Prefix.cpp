// NOTE
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs) // FIXME vector of string type not char type !
    {
        if (strs.empty())
            return "";

        // Assume the prefix is the first string
        string prefix = strs[0];

        // Compare prefix with each string
        for (int i = 1; i < strs.size(); i++) // REVIEW -  starts from 1
        {
            // Reduce prefix until it matches the start of strs[i]
            while (strs[i].find(prefix) != 0)
            {
                prefix.pop_back();
                if (prefix == "")
                    return "";
            }
        }
        return prefix;
    }
};
