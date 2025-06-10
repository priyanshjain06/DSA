#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        // If the input is empty, return an empty result
        if (intervals.empty()) //REVIEW
            return {};

        // Step 1: Sort the intervals based on the start time //FIXME -
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;

        // Step 2: Iterate through intervals and merge overlapping ones
        result.push_back(intervals[0]); // Add the first interval to the result

        for (int i = 1; i < intervals.size(); i++)
        {
            // Get the last merged interval
            vector<int> &last = result.back(); // FIXME

            // If there's an overlap, merge intervals
            if (last[1] >= intervals[i][0]) //FIXME
            {
                last[1] = max(last[1], intervals[i][1]);
            }
            else
            {
                // No overlap, so add the current interval as a new entry
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    vector<vector<int>> result = sol.merge(intervals);

    cout << "Merged Intervals:\n";
    for (auto &interval : result)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
