#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int factorial(int n)
{
    int res = 1;
    while (n > 1)
        res *= n--;
    return res;
}

int countDistinctVowelStrings(string s)
{
    unordered_map<char, int> freq;
    string vowels = "aeiou";

    // Count vowel frequencies
    for (char ch : s)
    {
        if (vowels.find(ch) != string::npos)
            freq[ch]++;
    }

    int waysToChoose = 1;
    int uniqueVowels = freq.size();
    if (uniqueVowels == 0)
        return 0; // REVIEW edge case

    for (auto &[vowel, count] : freq)
    {
        waysToChoose *= count;
    }

    return waysToChoose * factorial(uniqueVowels);
}

int main()
{
    cout << countDistinctVowelStrings("aeiou") << endl;  // 120
    cout << countDistinctVowelStrings("ae") << endl;     // 2
    cout << countDistinctVowelStrings("aacidf") << endl; // 4
}
