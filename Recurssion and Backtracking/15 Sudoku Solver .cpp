// REVIEW Time compexity : O(9(n ^ 2)) and Space Complexity : O(1)

// REVIEW Rules :
//  1) The Sudoku board contains only one  digit (1-9)  in row
//  2) The Sudoku board contains only one  digit (1-9)  in column
//  3) The Sudoku board contains only one  digit (1-9)  in 3x3 matrix

#include <iostream>
#include <vector>
using namespace std;
bool isValid(vector<vector<char>> &board, int row, int col, char c)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == c)
            return false;
        
        if (board[row][i] == c)
            return false;

        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            return false;
    }
    return true;
}

bool solveSudoku(vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++) //REVIEW board is 2d
        {
            if (board[i][j] == '.') // if the cell is empty
            {
                for (char c = '1'; c <= '9'; c++) //REVIEW charachter loop
                {
                    if (isValid(board, i, j, c))
                    {
                        board[i][j] = c;

                        if (solveSudoku(board)==true)
                            return true;
                        else
                            board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
int main()
{
    vector<vector<char>> board{
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}};

    solveSudoku(board);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
    return 0;
}