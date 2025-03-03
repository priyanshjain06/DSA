#include <iostream>
#include <vector>

using namespace std;

int atMostSum(vector<int> &arr, int goal)
{
    if (goal < 0) // REVIEW -
        return 0; // Edge case: If goal is negative, return 0

    int l = 0, r = 0, sum = 0, count = 0;

    while (r < arr.size())
    {
        sum += arr[r];

        while (sum > goal)
        { // Shrink window if sum exceeds goal
            sum -= arr[l];
            l++;
        }

        count =count+ (r - l + 1); // Count subarrays ending at r
        r++;
    }
    return count;
}

int numberOfSubarrays(vector<int> &arr, int goal)
{
    return atMostSum(arr, goal) - atMostSum(arr, goal - 1); // REVIEW -
}

int main()
{
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;

    cout << "Number of subarrays with sum equal to " << goal << " is: " << numberOfSubarrays(nums, goal) << endl;
    return 0;
}
