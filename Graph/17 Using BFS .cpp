#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool bfs(int start, vector<int> &colors, const vector<vector<int>> &graph) // REVIEW - start
    {
        queue<int> q;
        q.push(start);
        colors[start] = 0; // Start coloring the node with 0
w
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (int neighbor : graph[node])
            {
                if (colors[neighbor] == -1)
                {                                        // If the neighbor is not colored
                    colors[neighbor] = 1 - colors[node]; // REVIEW - color with opposite color
                }
                else if (colors[neighbor] == colors[node])
                { // If adjacent nodes have the same color
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(const vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> colors(n, -1); // -1 means uncolored

        for (int i = 0; i < n; i++)
        {
            if (colors[i] == -1)
            { // If the node is not colored
                if (bfs(i, colors, graph) == false)
                    return false;
            }
        }
        return true; 
    }
};
