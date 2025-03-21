#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> calculateSpan(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> span(n); // To store the result
        stack<int> st;       // Monotonic decreasing stack (stores indices)

        for (int i = 0; i < n; i++)
        {
            // Pop elements from stack while current price is greater
            while (!st.empty() && arr[st.top()] <= arr[i])
            {
                st.pop();
            }

            // If stack is empty, means no greater price on the left
            span[i] = (st.empty()) ? (i + 1) : (i - st.top());

            // Push the current index into the stack
            st.push(i);
        }
        return span;
    }
};