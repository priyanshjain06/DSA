// NOTE Rotate Image by 90 degree:
//  Problem Statement: Given a matrix, your task is to rotate the matrix 90 degrees clockwise.

//ANCHOR -  O(N*N) + O(N*N). and space complexity : O(1)

//LINK see scrrenshot


#include <iostream>
#include <vector>

using namespace std;
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    // transposing the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++) //NOTE 0 to i
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    // reversing each row of the matrix
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end()); //FIXME 
    }
}

