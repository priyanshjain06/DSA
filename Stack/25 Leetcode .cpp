#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> nextGreater; // REVIEW - declare a uncordered map here
        stack<int> st;

        for (int i = nums2.size() - 1; i >= 0; --i)
        {
            int curr = nums2[i];

            while (!st.empty() && st.top() <= curr)
            {
                st.pop();
            }

            nextGreater[curr] = st.empty() ? -1 : st.top();

            st.push(curr);
        }

        // REVIEW -  Prepare result using map for nums1 elements
        vector<int> result;
        for (int num : nums1)
        {
            result.push_back(nextGreater[num]); //REVIEW call the function
        }

        return result;
    }
};
