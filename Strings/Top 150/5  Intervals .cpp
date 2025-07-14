#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int n = nums.size();
        int i = 0;

        while (i < n) {
            int start = i;
            while (i + 1 < n && nums[i + 1] == nums[i] + 1) {
                i++;
            }

            if (start == i) {
                // single number
                result.push_back(to_string(nums[start]));
            } else {
                // range
                result.push_back(to_string(nums[start]) + "->" + to_string(nums[i]));
            }

            i++; // move to next unprocessed number
        }

        return result;
    }
};
