// REVIEW given
//  1) return answer in any order
//  2) array input will have unique elements
//  3) return unique subsets

// REVIEW Time Complexity: O(n! * n) and  Space Complexity: O(1)

// NOTE concept of backtracking is used here and no data structure is used except input and output

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
private:
    void recurPermute(int index, vector<int> &nums, vector<vector<int>> &ans)
    {
        if (index == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++) //REVIEW 
        {
            swap(nums[index], nums[i]);
            recurPermute(index + 1, nums, ans);
            swap(nums[index], nums[i]); // backtrack
        }
    }
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        recurPermute(0, nums, ans);
        return ans;
    }
};
