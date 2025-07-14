#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;

        for (int i = 0; i < nums.size(); i++) {
            if (i > k)
                window.erase(nums[i - k - 1]);  // Maintain window of size k

            if (window.count(nums[i]))
                return true;

            window.insert(nums[i]);
        }

        return false;
    }
};
