#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Custom comparator function to sort intervals by end time
    static bool compare(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];  // Sort by end time in ascending order
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0; //REVIEW - 

        // Step 1: Sort intervals using the custom comparator
        sort(intervals.begin(), intervals.end(), compare);

        int count = 0;
        int last_end = intervals[0][1];  // Store end time of the last non-overlapping interval

        // Step 2: Traverse through intervals
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < last_end) {   //REVIEW 
                // Overlapping, remove this interval
                count++;
            } else {
                // Non-overlapping, update last_end
                last_end = intervals[i][1]; //REVIEW 
            }
        }

        return count;  // Minimum number of intervals to remove
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1,2}, {2,3}, {3,4}, {1,3}};
    cout << "Minimum number of intervals to remove: " << sol.eraseOverlapIntervals(intervals) << endl;
    return 0;
}
