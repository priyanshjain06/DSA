// Problem Statement: Given an array of integers heights representing the histogram's bar height where the width of each bar is 1  return the area of the largest rectangle in histogram.

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
private:
    vector<int> nextSmallerElement(vector<int> arr, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--)
        {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            // ans is stack ka top
            ans[i] = s.top();
            s.push(i); // REVIEW - because  we are storing the index for calculating b = next[i] - prev[i] - 1; which are difference of indexes
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int> arr, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for (int i = 0; i < n; i++) // REVIEW -
        {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr)
            // REVIEW - arr[s.top()]
            {
                s.pop();
            }
            // ans is stack ka top
            ans[i] = s.top();
            s.push(i); // REVIEW -
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size(); 

        vector<int> next(n); // REVIEW -
        next = nextSmallerElement(heights, n);

        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);

        int area = 0;   
        for (int i = 0; i < n; i++)
        {
            int l = heights[i];

            if (next[i] == -1) // End of Histogram //REVIEW -
            {
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            int newArea = l * b;
            area = max(area, newArea);
        }
        return area;
    }
};