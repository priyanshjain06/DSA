#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        int n = board.size();
        vector<int> arr(n * n + 1);
        // Flatten the 2D board into a 1D array
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int idx = (n - 1 - i) * n +
                          (((n - i) % 2 == 0) ? (n - j) : (j + 1));
                arr[idx] = board[i][j];
            }
        }

        vector<bool> seen(n * n + 1, false);
        queue<int> q;
        q.push(1);
        seen[1] = true;

        int moves = 0;
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                int curr = q.front();
                q.pop();
                if (curr == n * n)
                    return moves;

                for (int next = curr + 1; next <= min(curr + 6, n * n); ++next)
                {
                    int dest = (arr[next] > 0 ? arr[next] : next);
                    if (!seen[dest])
                    {
                        seen[dest] = true;
                        q.push(dest);
                    }
                }
            }
            ++moves;
        }
        return -1;
    }
};
