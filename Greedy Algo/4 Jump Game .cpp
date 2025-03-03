
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// Function to determine if
// you can reach the last index
bool canJump(vector<int> &nums)
{
    // Initialize the maximum
    // index that can be reached
    int maxIndex = 0;

    // Iterate through each
    // index of the array
    for (int i = 0; i < nums.size(); i++)
    {
        // If the current index is greater
        // than the maximum reachable index
        // it means we cannot move forward
        // and should return false
        if (i > maxIndex)
        {
            return false;
        }

        // Update the maximum index
        // that can be reached by comparing
        // the current maxIndex with the sum of
        // the current index and the
        // maximum jump from that index
        maxIndex = max(maxIndex, i + nums[i]);
    }

    // If we complete the loop,
    // it means we can reach the
    // last index
    return true;
}

int main()
{
    vector<int> nums = {4, 3, 7, 1, 2};

    cout << "Array representing maximum jump from each index: ";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    bool ans = canJump(nums);

    if (ans)
    {
        cout << "It is possible to reach the last index." << endl;
    }
    else
    {
        cout << "It is not possible to reach the last index." << endl;
    }

    return 0;
}
