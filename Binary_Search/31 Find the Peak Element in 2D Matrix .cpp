// NOTE Problem Statement: Given a 2D matrix of integers, find the peak element in the matrix. A peak element is an element that is greater than or equal to its neighbors.

// REVIEW - Time Complexity: O(n * log(m))

// ANCHOR -  remeber the -1 edge case in matrix if the number has no neighbors then it will be -1 (assume it)

#include <vector>
#include <iostream>
using namespace std;

int findMaxInColumn(const vector<vector<int>> &mat, int midcol, int rows)
{
    int maxRow = 0;
    for (int i = 1; i < rows; i++)
    {
        if (mat[i][midcol] > mat[maxRow][midcol])
        {
            maxRow = i; // REVIEW  Return the index
        }
    }
    return maxRow;
}

pair<int, int> findPeakGrid(const vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    int low = 0, high = m - 1;

    while (low <= high)
    {
        int midCol = (low + high) / 2;
        int maxRow = findMaxInColumn(mat, midCol, n); // REVIEW - it ensures that we dont need to check for upper and lower element for each midcol since we have  the max element for that col !

        // Check if the current element is a peak
        bool leftIsSmaller = (midCol == 0 || mat[maxRow][midCol] > mat[maxRow][midCol - 1]);
        bool rightIsSmaller = (midCol == m - 1 || mat[maxRow][midCol] > mat[maxRow][midCol + 1]);

        if (leftIsSmaller && rightIsSmaller)
        {
            return {maxRow, midCol}; // Found a peak
        }
        else if (midCol > 0 && mat[maxRow][midCol - 1] > mat[maxRow][midCol]) // REVIEW -  midcol-1 > micol
        {
            high = midCol - 1; // Move to the left half because left is bigger than current mid cell in matrix  //REVIEW
        }
        else
        {
            low = midCol + 1; // Move to the right half
        }
    }
    return {-1, -1};
}
int main()
{
    vector<vector<int>> matrix = {
        {10, 8, 10, 10},
        {14, 13, 12, 11},
        {15, 9, 11, 21},
        {16, 17, 19, 20}};

    pair<int, int> peak = findPeakGrid(matrix);
    cout << "Peak found at: (" << peak.first << ", " << peak.second << ")\n";
    return 0;
}