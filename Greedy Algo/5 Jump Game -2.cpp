#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1) //REVIEW 
            return 0; // No jump needed if there's only one element

        int jump = 0;     // Number of jumps made
        int l = 0;        // Left boundary of the current jump range
        int r = 0;        // Right boundary of the current jump range
        int farthest = 0; // Farthest point reachable from the current range

        // While we haven't reached the last index
        while (r < n - 1)
        {
            // Traverse the current jump range
            for (int i = l; i <= r; ++i) //REVIEW - 
            {
                farthest = max(farthest, i + nums[i]); // Update the farthest reachable point
            }

            jump++;       // We need to make a jump
            l = r + 1;    // Move the left boundary forward
            r = farthest; // Update the right boundary to the farthest point we can reach
        }

        return jump; // Return the number of jumps made
    }
};

int main()
{
    Solution sol;

    // Test case 1
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "Minimum jumps for nums1: " << sol.jump(nums1) << endl;

    // Test case 2
    vector<int> nums2 = {2, 3, 0, 1, 4};
    cout << "Minimum jumps for nums2: " << sol.jump(nums2) << endl;

    return 0;
}
