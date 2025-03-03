// NOTE  Spiral Traversal of Matrix
// Problem Statement: Given a Matrix, print the given matrix in spiral order.

// LINK -  time complexity : O(n*m) and space complexity : O(1)

// ANCHOR there is no brute and better solution for this problem

#include <iostream>
#include <vector>

using namespace std;

vector<int> printSpiral(vector<vector<int>> mat)
{

    // Define ans array to store the result.
    vector<int> ans;

    int n = mat.size();    // no. of nows
                        // REVIEW 
    int m = mat[0].size(); // no. of columns 

    // Initialize the pointers reqd for traversal.
    int top = 0, left = 0, bottom = n - 1, right = m - 1; //REVIEW - 

    // Loop until all elements are not traversed.
    while (top <= bottom && left <= right) //REVIEW - 
    {
        // For moving left to right
        for (int i = left; i <= right; i++)
            ans.push_back(mat[top][i]);

        top++;

        // For moving top to bottom.
        for (int i = top; i <= bottom; i++)//REVIEW - 
            ans.push_back(mat[i][right]);

        right--;

        // For moving right to left.
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                ans.push_back(mat[bottom][i]);

            bottom--;
        }

        // For moving bottom to top.
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                ans.push_back(mat[i][left]);

            left++;
        }
    }
    return ans;
}

int main()
{

    // Matrix initialization.
    vector<vector<int>> mat{{1, 2, 3, 4},
                            {5, 6, 7, 8},
                            {9, 10, 11, 12},
                            {13, 14, 15, 16}};

    vector<int> ans = printSpiral(mat);

    for (int i = 0; i < ans.size(); i++)
    {

        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}