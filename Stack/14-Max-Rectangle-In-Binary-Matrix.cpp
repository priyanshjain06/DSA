#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
private:
    vector<int> getNextSmaller(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> next(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if (!st.empty()) //REVIEW - 
                next[i] = st.top();
            st.push(i); //REVIEW use the index of the element
        }
        return next; // REVIEW -
    }

    vector<int> getPrevSmaller(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> prev(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if (!st.empty())
                prev[i] = st.top();
            st.push(i);
        }
        return prev; // REVIEW -
    }

    int getMaxRectangle(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> next = getNextSmaller(heights);
        vector<int> prev = getPrevSmaller(heights);

        int maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            int width = next[i] - prev[i] - 1;
            maxArea = max(maxArea, heights[i] * width);
        }
        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.empty())
            return 0;
        // REVIEW -
        int rows = matrix.size(), cols = matrix[0].size(); // FIXME

        vector<int> heights(cols, 0);
        int maxArea = 0;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            }
            maxArea = max(maxArea, getMaxRectangle(heights)); //REVIEW call the max rectangle
        }

        return maxArea;
    }
};
