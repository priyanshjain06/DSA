// REVIEW Difference between 6 and 7 is that in 6 we cannot pick adjacent here we cannot pick adjancent and first or last (if we pick first then no last and vice versa )

#include <iostream>
#include <vector>
using namespace std;

long long int // FIXME take long long
solve(vector<int> &arr)
{
    int n = arr.size();
    long long int prev = arr[0]; // FIXME take things in long long
    long long int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        long long int pick = arr[i];
        if (i > 1)
            pick += prev2;
        int long long nonPick = 0 + prev;

        long long int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev = cur_i;
    }
    return prev;
}

long long int robStreet(int n, vector<int> &arr)
{
    vector<int> arr1;
    vector<int> arr2;

    if (n == 1)
        return arr[0];

    for (int i = 0; i < n; i++)
    {

        if (i != 0)
            arr1.push_back(arr[i]);
        if (i != n - 1)
            arr2.push_back(arr[i]);
    }

    // or use this
    // vector<int> arr1(nums.begin() + 1, nums.end()); // Exclude first
    // vector<int> arr2(nums.begin(), nums.end() - 1); // Exclude last

    long long int ans1 = solve(arr1);
    long long int ans2 = solve(arr2);

    return max(ans1, ans2);
}