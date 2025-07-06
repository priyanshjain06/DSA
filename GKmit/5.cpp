#include <iostream>
#include <vector>
#include <cmath> //REVIEW  for abs()
using namespace std;

int diagonalDifference(const vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int primary = 0, secondary = 0;

    for (int i = 0; i < n; ++i)
    {
        primary += matrix[i][i];
        secondary += matrix[i][n - 1 - i]; //REVIEW - 
    }

    return abs(primary - secondary);
}

int main()
{
    // Example input
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    int result = diagonalDifference(matrix);
    cout << "Absolute Diagonal Difference = " << result << endl;

    return 0;
}
