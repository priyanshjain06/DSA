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

        if (map.size() > k) // REVIEW -
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

// // REVIEW for leetcode !  k is not given here so take  2 !

// class Solution
// {
// public:
//     int totalFruit(vector<int> &fruits)
//     {
//         int n = fruits.size();
//         int maxlen = 0;
//         int left = 0;
//         int right = 0;

//         map<int, int> map;

//         while (right < n)
//         {
//             map[fruits[right]]++;

//             if (map.size() > 2) // REVIEW -
//             {
//                 map[fruits[left]]--;
//                 if (map[fruits[left]] == 0)
//                 {
//                     map.erase(fruits[left]);
//                 }
//                 left++;
//             }
//             if (map.size() <= 2)
//             {
//                 maxlen = max(maxlen, right - left + 1);
//             }
//             right++;
//         }
//         return maxlen;
//     }
// };