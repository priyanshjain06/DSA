#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> ans;
    for (int i = 0; i <= nums.size() - k; i++)
    {
        int maxi = nums[i];

        for (int j = i + 1; j < i + k; j++) // REVIEW -
        {
            maxi = max(maxi, nums[j]);
        }

        ans.push_back(maxi);
    }

    // Return the list of maximums for all sliding windows
    return ans;
}
int main()
{
    int i, j, n, k = 3, x;
    vector<int> arr{
        4, 0,
        -1,
        3,
        5,
        3,
        6,
        8};
    vector<int> ans;
    ans = maxSlidingWindow(arr, k);
    cout << "Maximum element in every " << k << " window " << endl;
    for (i = 0; i < ans.size(); i++)
        cout << ans[i] << "  ";
    return 0;
}