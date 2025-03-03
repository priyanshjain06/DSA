// NOTE Given an array of integers arr of length n, count the number of contiguous subarrays that contain exactly k distinct integers.

// ANCHOR -  Time Complexity : O(n) and Space Complexity : O(n)

#include <iostream>
#include <unordered_map>
using namespace std;

int countAtMostK(int n, int k, int num[]) // REVIEW -
{
    unordered_map<int, int> freqMap; // REVIEW -
    int left = 0;
    int count = 0;
    int right = 0;

    while (right < n)
    {
        freqMap[num[right]]++;

        while (freqMap.size() > k)
        {
            freqMap[num[left]]--;
            if (freqMap[num[left]] == 0)
            {
                freqMap.erase(num[left]);
            }
            left++;
        }

        count += (right - left + 1); // REVIEW -
        right++;
    }
     return count;
}

int countExactlyK(int n, int k, int num[]) // REVIEW => k -(k-1)
{
    return countAtMostK(n, k, num) - countAtMostK(n, k - 1, num);
}

int main()
{
    int arr[] = {1, 2, 1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    cout << "The number of subarrays with exactly " << k << " distinct integers is: " << countExactlyK(n, k, arr) << "\n";
    return 0;
}
