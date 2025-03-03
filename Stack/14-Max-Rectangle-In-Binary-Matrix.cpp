// NOTE  Given a binary matrix filled with 0s and 1s, your task is to find the area of the largest rectangle containing only 1s.

// ANCHOR -  Time complexity : O(n * m ) where n,m are rows and columns and space complexity : O(m)

// LINK -  we will use conecpt of 12th question

// REVIEW -  follow these steps:
//  1) Computate area for first row
//  2) Compute area for remaining rows by adding previous row's value

// REVIEW -  edge case to remember : we can declare a global variable to store the area.
//  and
//   we will check the base row should not be 0 while adding the previous row's value

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define MAX 1000
class Solution
{
private:
    vector<int> nextSmallerElement(int *arr, int n)
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
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(int *arr, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for (int i = 0; i < n; i++)
        {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            // ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    int largestRectangleArea(int *heights, int n)
    {
        // int n= heights.size();

        vector<int> next(n);
        next = nextSmallerElement(heights, n);

        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);

        int area = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int l = heights[i];

            if (next[i] == -1)
            {
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            int newArea = l * b;
            area = max(area, newArea);
        }
        return area;
    }

public:
    int maxArea(int M[MAX][MAX], int n, int m)
    {

        // step 1: compute area for first row
        int area = largestRectangleArea(M[0], m);

        for (int i = 1; i < n; i++) // REVIEW -  from 1
        {
            for (int j = 0; j < m; j++)
            {

                // row udpate: by adding previous row's value
                if (M[i][j] != 0)
                    M[i][j] = M[i][j] + M[i - 1][j];
                else
                    M[i][j] = 0;
            }

            // entire row is updated now
            area = max(area, largestRectangleArea(M[i], m));
        }
        return area;
    }
};

int main()
{
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
// } Driver Code Ends