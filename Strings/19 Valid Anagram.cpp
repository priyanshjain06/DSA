#include <iostream>
#include <unordered_map>

using namespace std;
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        unordered_map<char, int> countMap;  //REVIEW 

        for (int i = 0; i < s.size(); i++)
        {
            countMap[s[i]]++;
            countMap[t[i]]--;
        }

        for (auto &pair : countMap)
        {
            if (pair.second != 0)
            {
                return false;
            }
        }
        return true;
    }
};