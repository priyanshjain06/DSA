#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj)
    {
        int V = adj.size(); // Number of vertices //REVIEW - 
        vector<int> bfs;
        vector<bool> visited(V, false);
        queue<int> q;

        visited[0] = true;
        q.push(0);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for (int neighbor : adj[node])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        return bfs;
    }
};
