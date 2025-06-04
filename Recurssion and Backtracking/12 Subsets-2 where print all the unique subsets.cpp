// REVIEW -  Time Complexity: O(k * 2^n).  and Space Complexity: Space Complexity: O(2^n * k)

// REVIEW - Rules
//  1) unique combinations (no duplicate combinations)
// 2) return the  substrings in any order
// 3) array can have duplicated elements (given)

// NOTE it just a change of the question 10

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void printAns(vector<vector<int>> &ans) // REVIEW  just like matrix print
{
    cout << "The unique subsets are " << endl;
    cout << "[ ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << "]";
    }
    cout << " ]";
}
class Solution
{
private:
    void findSubsets(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans)
    {
        ans.push_back(ds); // NOTE directly push here

        for (int i = ind; i < nums.size(); i++)
        {
            if (i > ind && nums[i] == nums[i - 1])
                continue;
            ds.push_back(nums[i]);
            findSubsets(i + 1, nums, ds, ans); // NOTE remove the sum here
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end()); // REVIEW
        findSubsets(0, nums, ds, ans);
        return ans;
    }
};
int main()
{
    Solution obj;
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> ans = obj.subsetsWithDup(nums);
    printAns(ans);
    return 0;
}