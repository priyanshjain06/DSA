#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution
{
public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>> &edges)
    {
        vector<vector<int>> adj(V); // Adjacency list

        // Construct adjacency list
        for (auto &edge : edges)
        {
            int u = edge.first, v = edge.second;
            adj[u].push_back(v);
            adj[v].push_back(u); // Because it's an undirected graph
        }

        // Sorting each adjacency list for ordered output
        for (int i = 0; i < V; i++)
        {
            sort(adj[i].begin(), adj[i].end());
        }

        return adj;
    }
};