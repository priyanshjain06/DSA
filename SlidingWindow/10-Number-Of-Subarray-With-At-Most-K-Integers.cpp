// NOTE Given an array of integers arr of length n, count the number of contiguous subarrays that contain at most k distinct integers.

// ANCHOR -  Time Complexity : O(n) and Space Complexity : O(k)

#include <iostream>
#include <map>
using namespace std;

int Max(int n, int k, int num[])
{
    int maxlen = 0;
    int left = 0;
    int right = 0;

    map<int, int> map; // REVIEW -
    int count = 0;

    while (right < n)
    {
        map[num[right]]++;

        // REVIEW use the while loop here
        while (map.size() > k)
        {
            map[num[left]]--;
            if (map[num[left]] == 0)
            {
                map.erase(num[left]);
            }
            left++;
        }

        // REVIEW no if condition
        count = count + (right - left + 1);

        right++;
    }
    return count;
}