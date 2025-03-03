// REVIEW given
//  1) return answer in any order
//  2) array input will have unique elements
//  3) return unique subsets

// REVIEW time complexity : O(n! * n) and  Space Complexity : O(n)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
private:
    void recurPermute(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, int freq[])
    {
        if (ds.size() == nums.size()) //REVIEW 
        {
            ans.push_back(ds);
            return;
        }
        for (int i = 0; i < nums.size(); i++) // REVIEW not from index from 0
        {
            if (!freq[i]) // freq[i] == 0 means element is unused
            {
                ds.push_back(nums[i]);
                freq[i] = 1;
                recurPermute(ds, nums, ans, freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        int size = nums.size();
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[size];
        for (int i = 0; i < nums.size(); i++) //REVIEW - 
            freq[i] = 0;
        recurPermute(ds, nums, ans, freq);
        return ans;
    }
};
