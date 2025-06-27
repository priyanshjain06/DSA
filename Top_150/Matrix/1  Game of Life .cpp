#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> dirs = {
            {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int live = 0;
                for (auto &dir : dirs)
                {
                    int ni = i + dir[0], nj = j + dir[1];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n)
                        live += board[ni][nj] & 1; // only check LSB (original state)
                }

                // Now encode next state in the 2nd bit (MSB)
                if ((board[i][j] & 1) && (live == 2 || live == 3))
                {
                    board[i][j] |= 2; // cell lives
                }
                else if (!(board[i][j] & 1) && live == 3)
                {
                    board[i][j] |= 2; // cell becomes alive
                }
            }
        }

        // Update board by shifting to the next state
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                board[i][j] >>= 1; // right shift to make next state the current
    }
};
