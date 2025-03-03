// REVIEW :- Time Complexity : O(2^n) * k where k=  total number of subsets
//  and Space Complexity : O(k)*n

// REVIEW - Rules
//  1) unique combinations (no duplicate combinations) , input has duplciates
// 2) elements cannot be repeated
// 3) return combinations in sorted order

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds) // REVIEW
{
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }
    for (int i = ind; i < arr.size(); i++) // REVIEW start from index
    {
        if (i > ind && arr[i] == arr[i - 1])
            continue;
        if (arr[i] > target) //sorted array
            break;

        ds.push_back(arr[i]);
        findCombination(i + 1, target - arr[i], arr, ans, ds);
        ds.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end()); // REVIEW
    vector<vector<int>> ans; //REVIEW 
    vector<int> ds;
    findCombination(0, target, candidates, ans, ds);
    return ans;
}
