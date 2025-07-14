#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> anagramMap;
        
        for (string s : strs)
        {
            string key = s;
            sort(key.begin(), key.end()); // sorted string is the key
            anagramMap[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto &pair : anagramMap)
        {
            result.push_back(pair.second);
        }

        return result;
    }
};
