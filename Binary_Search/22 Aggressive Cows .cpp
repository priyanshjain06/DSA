// NOTE -Problem Statement: You are given an array 'arr' of size 'n' which denotes the position of stalls.
// You are also given an integer 'k' which denotes the number of aggressive cows.
// You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.
// Find the maximum possible minimum distance.

// REVIEW - Time Complexity: O(NlogN) + O(N * log(max(stalls[])-min(stalls[]))) and Space Complexity: O(1)

// LINK   leetcode 1552. Magnetic Force Between Two Balls

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canWePlace(vector<int> &stalls, int dist, int cows)
{
    int n = stalls.size(); // size of array
    int cntCows = 1;       // no. of cows placed
    int last = stalls[0];  // position of last placed cow.

    for (int i = 1; i < n; i++) // REVIEW -  start from 1
    {
        if (stalls[i] - last >= dist)
        {
            cntCows++;        // place next cow.
            last = stalls[i]; // update the last location.
        }
        // REVIEW no else
        if (cntCows == cows)
            return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();

    sort(stalls.begin(), stalls.end()); // REVIEW -

    int low = 1, high = stalls[n - 1] - stalls[0]; 
    // REVIEW max -min in array

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (canWePlace(stalls, mid, k) == true)
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return high; // REVIEW - why ? always return oposite polarity from the position where high and low are when the answer is found !
}