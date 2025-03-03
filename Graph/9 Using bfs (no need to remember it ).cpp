#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    void bfs(int sr, int sc, vector<vector<int>> &image, int oldColor, int newColor)
    {
        int n = image.size(), m = image[0].size();
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = newColor; // Change the starting pixel color

        vector<int> delRow = {-1, 1, 0, 0}, delCol = {0, 0, -1, 1};

        while (!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nrow = r + delRow[i], ncol = c + delCol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    image[nrow][ncol] == oldColor)
                {
                    image[nrow][ncol] = newColor;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int oldColor = image[sr][sc];
        if (oldColor != color)
        { // Avoid infinite loop if oldColor == newColor
            bfs(sr, sc, image, oldColor, color);
        }
        return image;
    }
};
