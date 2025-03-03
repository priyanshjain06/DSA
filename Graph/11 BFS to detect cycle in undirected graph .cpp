#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
private:
    bool detect(int src, vector<vector<int>> &adj, vector<int> &vis)
    {
        queue<pair<int, int>> q; // REVIEW -
        q.push({src, -1});       // REVIEW -
        vis[src] = 1;            // REVIEW -

        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto neighbor : adj[node])
            {
                if (!vis[neighbor])
                {
                    vis[neighbor] = 1;
                    q.push({neighbor, node}); //REVIEW node is parent here 
                }
                else if (neighbor != parent) // REVIEW -
                {
                    return true; // Cycle detected
                }
            }
        }
        return false; // REVIEW -
    }
public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>> &adj) // REVIEW -  for connected component
    {
        int V = adj.size();
        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i] && detect(i, adj, vis)) // REVIEW -
                return true;
        }
        return false; // REVIEW -
    }
};
