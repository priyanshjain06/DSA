#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool dfs(int node, int color, vector<int> &colors, const vector<vector<int>> &graph) // REVIEW -
    {
        colors[node] = color; //REVIEW this color is 0 check the fucntion call , Color the current node

        for (int neighbor : graph[node])
        {
            if (colors[neighbor] == -1)
            {                                                         // If the neighbor is not colored 
                if (dfs(neighbor, 1 - color, colors, graph) == false) // REVIEW 1-color , Recursively color with opposite color
                    return false;
            }
            else if (colors[neighbor] == colors[node])
            { // If adjacent nodes have the same color
                return false;
            }
        }
        return true;
    }

    bool isBipartite(const vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> colors(n, -1); // REVIEW - // -1 means uncolored

        for (int i = 0; i < n; i++)
        {
            if (colors[i] == -1)
            {                                          // If not yet colored
                if (dfs(i, 0, colors, graph) == false) // Start DFS coloring
                    return false;
            }
        }
        return true;
    }
};
