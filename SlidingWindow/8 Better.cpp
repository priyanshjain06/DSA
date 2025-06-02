#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solve(string s, int k)
{
    int l = 0, r = 0, max_len = 0, max_freq = 0;
    vector<int> freq(26, 0); //REVIEW - 

    while (r < s.size())
    {
        freq[s[r] - 'A']++;
        max_freq = max(max_freq, freq[s[r] - 'A']);
        r++;

        while ((r - l) - max_freq > k) // r- l is the length
        {
            freq[s[l] - 'A']--;
            max_freq = 0; //REVIEW -  remove this in optimal
            for (int i = 0; i < 26; i++) //REVIEW - remove in optimal
            {
                max_freq = max(max_freq, freq[i]);
            }
            l++;
        }
        max_len = max(max_len, r - l +1 );
    }
    return max_len;
}

int main()
{
    string s;
    int k;

    cout << "Enter the string: ";
    cin >> s;
    cout << "Enter the value of k: ";
    cin >> k;

    int result = solve(s, k);
    cout << "Maximum length: " << result << endl;

    return 0;
}