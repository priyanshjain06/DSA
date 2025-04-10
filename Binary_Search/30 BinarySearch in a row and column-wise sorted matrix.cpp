// NOTE Problem Statement: You have been given a 2-D array 'mat' of size 'N x M' where 'N' and 'M' denote the number of rows and columns, respectively. The elements of each row and each column are sorted in non-decreasing order.
//  But, the first element of a row is not necessarily greater than the last element of the previous row (if it exists).
//  You are given an integer ‘target’, and your task is to find if it exists in the given 'mat' or not.

// REVIEW - Time Complexity: O(log(m * n)) and Space Complexity : O(1)

// ANCHOR -  remember we can only start from the cordinate where  one direction is decreasing and other direction is increasing

#include <iostream>
#include <vector>
using namespace std;

bool searchElement(vector<vector<int>> &matrix, int target)
{
    if (matrix.empty() || matrix[0].empty())
        return false; // REVIEW

    int n = matrix.size();
    int m = matrix[0].size(); // REVIEW -
    int row = 0, col = m - 1; // REVIEW - column start point

    // traverse the matrix from (0, m-1):
    while (row < n && col >= 0) // REVIEW -
    {
        if (matrix[row][col] == target)
            return true;
        else if (matrix[row][col] < target) // REVIEW -
            row++;
        else
            col--;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    searchElement(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
}
