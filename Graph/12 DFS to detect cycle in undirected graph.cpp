#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
private:
    bool dfs(int node, int parent, int vis[], vector<int> adj[])
    {
        vis[node] = 1;
        // visit adjacent nodes
        for (auto adjacentNode : adj[node])
        {
            // unvisited adjacent node
            if (!vis[adjacentNode])
            {
                if (dfs(adjacentNode, node, vis, adj) == true)
                    return true; // true means cycle is detected !
            }
            // visited node but not a parent node
            else if (adjacentNode != parent)
                return true;
        }
        return false;
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        int vis[V] = {0};
        // for graph with connected components
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, -1, vis, adj) == true) 
                {
                    // REVIEW we need to pass parent also !
                    //  REVIEW  no detect function is called and  - i,-1
                    return true;
                }
            }
        }
        return false;
    }
};
