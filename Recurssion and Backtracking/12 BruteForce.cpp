// NOTE Why Sorting Matters, Even With set
//  A set only considers two entries as duplicates if they are exactly identical. In the context of subsets:

// A set will treat {2, 1} and {1, 2} as different subsets because the order of elements is different.
// To make these subsets identical and allow the set to correctly filter duplicates, the subsets are sorted before insertion.

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
void printAns(vector<vector<int>> &ans)
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
public:
    void fun(vector<int> &nums, int index, vector<int> ds, set<vector<int>> &res)
    {
        if (index == nums.size())
        {
            sort(ds.begin(), ds.end()); //REVIEW
            res.insert(ds);
            return;
        }
        ds.push_back(nums[index]);
        fun(nums, index + 1, ds, res);
        ds.pop_back();
        fun(nums, index + 1, ds, res);
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        set<vector<int>> res;//REVIEW
        vector<int> ds;
        fun(nums, 0, ds, res);
        for (auto it = res.begin(); it != res.end(); it++)
        {
            ans.push_back(*it);
        }
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