#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.empty())
            return 0;

        // Sort by ending coordinate // REVIEW
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[1] < b[1]; });

        int arrows = 1; // REVIEW
        int end = points[0][1];

        for (int i = 1; i < points.size(); ++i)
        {
            // If this balloon starts after the last arrow's burst area
            if (points[i][0] > end)
            {
                arrows++;
                end = points[i][1]; // Shoot new arrow
            }
            // else: this balloon is already burst by current arrow
        }

        return arrows;
    }
};
