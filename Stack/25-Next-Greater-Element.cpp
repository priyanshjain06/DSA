// ANCHOR -  Time Complexity: O(N) and Space Complexity: O(N)
// LINK this method is called next greater element or monotonic stack

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> nge(n, -1); // REVIEW -
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {

            while (!st.empty() && st.top() <= nums[i]) // REVIEW
            {
                st.pop();
            }

            if (st.empty()) // REVIEW
            {
                nge[i] = -1;
            }

            if (!st.empty())
            {
                nge[i] = st.top();
            }

            st.push(nums[i]);
        }
        return nge;
    }
};
