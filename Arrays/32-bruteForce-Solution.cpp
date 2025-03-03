// NOTE - Problem Statement: Given an array of intervals, merge all the overlapping intervals and return an array of non-overlapping intervals.

// ANCHOR Time Complexity: O(N*logN) + O(2*N) and Space Complexity: O(N)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr)
{
    int n = arr.size();

    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        // select an interval:
        // eg (1,3) where 1 is start and 3 is end
        int start = arr[i][0];
        int end = arr[i][1];

        // Skip all the merged intervals:
        // eg (1,6) and (2,4) then (1,6) where (1,6) is in ans
        if (!ans.empty() && end <= ans.back()[1])
        {
            continue;
        }

        // check the rest of the intervals:
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j][0] <= end)
            {
                end = max(end, arr[j][1]);
            }
            else
            {
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = mergeOverlappingIntervals(arr);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans)
    {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}
