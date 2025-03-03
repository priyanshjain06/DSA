// NOTE -  array of intervals, merge all the overlapping intervals and return an array of non-overlapping intervals.

// ANCHOR -Time Complexity: O(N*logN) + O(N) and Space Complexity is O(n)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr)
{
    int n = arr.size();

    sort(arr.begin(), arr.end()); //REVIEW - 

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        // if the current interval does not
        // lie in the last interval:
        // eg (1,6) and (8,13) 8>6
        if (ans.empty() || arr[i][0] > ans.back()[1])
        {
            ans.push_back(arr[i]);
        }
        // if the current interval
        // lies in the last interval:
        // eg (1,3) and (2,4) so 4>3
        else
        {
            ans.back()[1] = max(ans.back()[1], arr[i][1]); //REVIEW - 
        }
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
