#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int totalNQueens(int n)
    {
        vector<int> leftRow(n, 0), upperDiag(2 * n - 1, 0), lowerDiag(2 * n - 1, 0);
        int count = 0;
        solve(0, n, leftRow, upperDiag, lowerDiag, count); // REVIEW 6 things removed
        return count;
    }

private:
    void solve(int col, int n, vector<int> &leftRow, vector<int> &upperDiag, vector<int> &lowerDiag, int &count)
    {
        if (col == n)
        {
            count++; // REVIEW
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (leftRow[row] == 0 && lowerDiag[row + col] == 0 && upperDiag[n - 1 + col - row] == 0)
            {
                leftRow[row] = 1;
                lowerDiag[row + col] = 1;
                upperDiag[n - 1 + col - row] = 1;

                solve(col + 1, n, leftRow, upperDiag, lowerDiag, count);

                leftRow[row] = 0;
                lowerDiag[row + col] = 0;
                upperDiag[n - 1 + col - row] = 0; // backtrack
            }
        }
    }
};
