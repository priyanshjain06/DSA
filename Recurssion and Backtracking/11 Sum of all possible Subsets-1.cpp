// REVIEW Time Complexity: O(2^n)+O(2^n log(2^n)) and  Space Complexity: O(2^n)

// REVIEW  Rules-
// 1) return the sum of subsets in sorted order
// 2)  all the rules of generating subsets will be followed

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    void subsetSumsHelper(int ind, vector<int> &arr, int n, vector<int> &ans, int sum)
    {
        if (ind == n)
        {
            ans.push_back(sum);
            return;
        }
        subsetSumsHelper(ind + 1, arr, n, ans, sum + arr[ind]);
        subsetSumsHelper(ind + 1, arr, n, ans, sum); // REVIEW sum is not updated
    }
    vector<int> subsetSums(vector<int> arr, int n)
    {
        vector<int> ans; // REVIEW -
        subsetSumsHelper(0, arr, n, ans, 0);
        sort(ans.begin(), ans.end()); // REVIEW -
        return ans;
    }
};
