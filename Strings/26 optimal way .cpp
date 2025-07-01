// O(n) time and O(1) space
// REVIEW using dp


#include <string>
using namespace std;

long long sumSubstrings(string s)
{
    long long result = 0, prev = 0, mod = 1e9 + 7; // mod is used to overflow

    for (int i = 0; i < s.size(); i++)
    {
        int digit = s[i] - '0';                     // string to integer
        prev = (prev * 10 + (i + 1) * digit) % mod; // REVIEW
        result = (result + prev) % mod;
    }

    return result;
}
