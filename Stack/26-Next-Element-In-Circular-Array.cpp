// NOTE Problem Statement: Given a circular integer array A, return the next greater element for every element in A. The next greater element for an element x is the first element greater than x that we come across while traversing the array in a clockwise manner. If it doesn't exist, return -1 for this element.

// STUB given array is circular

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
        for (int i = 2 * n - 1; i >= 0; i--) // REVIEW -  2*n-1
        {
            while (!st.empty() && st.top() <= nums[i % n]) // REVIEW -
            {
                st.pop();
            }

            if (i < n) // REVIEW -
            {
                if (st.empty())
                    nge[i] = -1;
                else
                    nge[i] = st.top();
            }
            st.push(nums[i % n]); // REVIEW -
        }
        return nge;
    }
};
int main()
{
    Solution obj;
    vector<int> v{5, 7, 1, 2, 6, 0};
    vector<int> res = obj.nextGreaterElements(v);
    cout << "The next greater elements are" << endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}