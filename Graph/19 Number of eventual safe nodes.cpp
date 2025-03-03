#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[], int check[])
    {
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;

        // Traverse the adjacent nodes
        for (int neighbor : adj[node])
        {
            if (!vis[neighbor])
            {
                if (dfsCheck(neighbor, adj, vis, pathVis, check))
                {
                    check[node] = 0;
                    return true;
                }
            }
            else if (pathVis[neighbor])
            {
                check[node] = 0;//REVIEW - 
                return true;
            }
        }

        check[node] = 1; //NOTE  we have traversed all posibilities eg: 5->2,3   we have explored both 5->2 and 5->3  and non of these path leads to cycle leds to terminated path
        pathVis[node] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        int vis[V] = {0};
        int pathVis[V] = {0};
        int check[V] = {0};

        for (int i = 0; i < V; i++) //REVIEW - 
        {
            if (!vis[i])
            {
                dfsCheck(i, adj, vis, pathVis, check);
            }
        }

        vector<int> safeNodes; //REVIEW - 
        for (int i = 0; i < V; i++)
        {
            if (check[i] == 1)  //REVIEW - 
            {
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }
};

int main()
{
    Solution solution;
    int V = 4;
    vector<int> adj[V];
    adj[0] = {1};
    adj[1] = {2};
    adj[2] = {0, 3};
    adj[3] = {};

    vector<int> safeNodes = solution.eventualSafeNodes(V, adj);
    for (int node : safeNodes)
    {
        cout << node << " ";
    }
    return 0;
}