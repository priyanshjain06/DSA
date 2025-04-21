#include <iostream>
#include <unordered_map>
using namespace std;
int atMostKDistinct(string s, int k)
{
    unordered_map<char, int> count;
    int left = 0, right = 0, unique = 0, total = 0;
    // REVIEW concept of sliding window :-
    while (right < s.length())
    {
        if (count[s[right]] == 0)
            unique++;
        count[s[right]]++;
        right++;

        while (unique > k)
        {
            count[s[left]]--;
            if (count[s[left]] == 0)
                unique--;
            left++;
        }

        total += right - left; // REVIEW
    }

    return total;
}

int substrCount(string s, int k) // REVIEW
{
    return atMostKDistinct(s, k) - atMostKDistinct(s, k - 1);
}
