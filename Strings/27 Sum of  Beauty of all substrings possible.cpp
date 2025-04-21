#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;
int beautySum(string s)
{
    int n = s.length();
    int totalBeauty = 0;

    for (int i = 0; i < n; i++)
    {
        vector<int> freq(26, 0); // REVIEW

        for (int j = i; j < n; j++)
        {
            freq[s[j] - 'a']++;

            int maxFreq = 0, minFreq = INT_MAX; // REVIEW maxfreq is 0 to ignore zero in the input

            for (int f = 0; f < 26; f++)
            {
                if (f > 0)
                {
                    maxFreq = max(maxFreq, f);
                    minFreq = min(minFreq, f);
                }
            }

            totalBeauty += (maxFreq - minFreq); // REVIEW -  compund operator
        }
    }
    return totalBeauty;
}
