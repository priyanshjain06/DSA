#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> s;
        vector<int> next(n, n);  //REVIEW  // Stores next smaller element index
        vector<int> prev(n, -1); // Stores previous smaller element index

        // **Find Next Smaller Element (Right)**
        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                s.pop();
            }
            if (!s.empty())
            {
                next[i] = s.top();
            }
            s.push(i); 
        }

        // Clear stack for the next computation
        while (!s.empty()) //REVIEW - 
            s.pop();

        // **Find Previous Smaller Element (Left)**
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                s.pop();
            }
            if (!s.empty())
            {
                prev[i] = s.top();
            }
            s.push(i);
        }

        // **Calculate Maximum Area**
        int maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            int height = heights[i];
            int width = next[i] - prev[i] - 1;
            maxArea = max(maxArea, height * width);
        }

        return maxArea;
    }
};
