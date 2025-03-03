// NOTE Problem Statement: Given an array of integers arr, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

// ANCHOR - Time Complexity: O(N)

// FIXME - MONOTONIC stack is of two types - 1) monotonic increasing stack 2) monotonic decreasing stack

// REVIEW -  use a dequeue (monotonic stack) for this approach ! and Remember the edge cases:
// 1) elements in dequeue should be in descending order
// 2)

// LINK Example : nums = [1,3,-1,-3,5,3,6,7], k = 3

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    
    deque<int> dq;
    vector<int> ans;
    
    for (int i = 0; i < nums.size(); i++)
    {
        // out of bond
        if (!dq.empty() && dq.front() == i - k) // when i is  4 , val is 5
            dq.pop_front();

        // if no decreasing order is maintained
        while (!dq.empty() && nums[dq.back()] < nums[i]) // when i is  4 , val is 5
            dq.pop_back();

        dq.push_back(i);

        if (i >= k - 1)
            ans.push_back(nums[dq.front()]);
    }
    return ans;
}
int main()
{
    int i, j, n, k = 3, x;
    vector<int> arr{4, 0, -1, 3, 5, 3, 6, 8};
    vector<int> ans;
    ans = maxSlidingWindow(arr, k);
    cout << "Maximum element in every " << k << " window " << endl;
    for (i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}