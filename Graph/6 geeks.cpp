#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &result)
    {
        visited[node] = true;
        result.push_back(node);

        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                dfs(neighbor, adj, visited, result);
            }
        }
    }
    vector<int> dfsOfGraph(vector<vector<int>> &adj)
    {
        int V = adj.size(); // Number of vertices
        vector<int> result;
        vector<bool> visited(V, false);

        dfs(0, adj, visited, result);
        return result;
    }
};