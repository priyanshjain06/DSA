#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        // Continue to remove occurrences of 'part' as long as it's found in 's'
        while (s.find(part) <= s.length() && s.length() > 0)
        {
            s.erase(s.find(part), part.length()); // Remove the found 'part'
        }
        return s;
    }
};