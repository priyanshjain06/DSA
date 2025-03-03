// NOTE - : Given an array containing both positive and negative integers, we have to find the length of the longest subarray with the sum of all elements equal to zero.

// ANCHOR time complexity : O(n^2) and space complexity : O(n)

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int solve(vector<int> &a)
{
    int maxLen = 0;
    unordered_map<int, int> sumIndexMap;
    int sum = 0;

    for (int i = 0; i < a.size(); i++)
    {
        sum += a[i];

        if (sum == 0)
        {
            maxLen = i + 1;
        }
        else if (sumIndexMap.find(sum) != sumIndexMap.end())
        {
            maxLen = max(maxLen, i - sumIndexMap[sum]);
        }
        else
        {
            sumIndexMap[sum] = i;
        }
    }

    return maxLen;
}

int main()
{
    vector<int> a = {9, -3, 3, -1, 6, -5};
    cout << solve(a) << endl;

    return 0;
}
