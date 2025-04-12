// NOTE : Example : part to remove abc
//  string : daabcabc => daabc=> da
// NOTE Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

#include <iostream>
#include <string>
using namespace std;

string removeOccurrences(string s, string part)
{
    string result;
    int partLen = part.size();

    for (char c : s)
    {
        result.push_back(c);

        if (result.size() >= partLen && result.substr(result.size() - partLen) == part)
        {
            result.erase(result.end() - partLen, result.end());
        }
    }

    return result;
}
