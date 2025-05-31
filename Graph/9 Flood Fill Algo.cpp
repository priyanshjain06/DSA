// NOTE why dfs ? not bfs ? since we are traversing the nodes on the basos of the inital color indorder to chnages it to new color that's why !

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    void dfs(int row, int col, vector<vector<int>> &image, int newColor, int iniColor) // NOTE you can also use bfs here
    {
        int n = image.size(), m = image[0].size();
        image[row][col] = newColor; // REVIEW Change color

        // Movement directions: Up, Right, Down, Left
        vector<int> delRow = {-1, 0, 1, 0}, delCol = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) // REVIEW - 4
        {
            int nrow = row + delRow[i], ncol = col + delCol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                image[nrow][ncol] == iniColor)
            {
                dfs(nrow, ncol, image, newColor, iniColor); //REVIEW 5
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int iniColor = image[sr][sc]; // REVIEW -
        if (iniColor != color)        // REVIEW -
        {                             // Prevent infinite loop if the color is the same
            dfs(sr, sc, image, color, iniColor);
        }
        return image;
    }
};
