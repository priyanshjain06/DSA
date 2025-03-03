// ANCHOR Time complexity : O(n) and Space Complexity: O(1)

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int NumberOFSubstring(string s)
{
    int lastseen[3] = {-1, -1, -1}; // REVIEW use array here
    int count = 0;
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a' || s[i] == 'b' || s[i] == 'c')
            lastseen[s[i] - 'a'] = i;

        if (lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1) // NOTE even if you dont use this if here answer will be same !
        {
            count = count + (1 + min(lastseen[0], min(lastseen[1], lastseen[2]))); //FIXME
        }
    }
    return count;
}

int main()
{
    string s = "abcbabacab";
    cout << "The number of substrings containing at least 'a', 'b', and 'c' is: " << NumberOFSubstring(s) << "\n";
    return 0;
}
