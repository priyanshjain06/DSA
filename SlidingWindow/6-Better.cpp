#include <iostream>
#include <map>
using namespace std;

int Max(int n, int k, int num[])
{
    int maxlen = 0;
    int left = 0;
    int right = 0;

    map<int, int> map;

    while (right < n)
    {
        map[num[right]]++;

        while (map.size() > k)
        {
            map[num[left]]--;
            if (map[num[left]] == 0)
            {
                map.erase(num[left]);
            }
            left++;
        }

        if (map.size() <= k)
        {
            maxlen = max(maxlen, right - left + 1);
        }
        right++;
    }
    return maxlen;
}