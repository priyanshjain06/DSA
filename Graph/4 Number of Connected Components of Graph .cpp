//{ Driver Code Starts
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    // Helper function to perform DFS and find all nodes in a connected component
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &component)
    {
        visited[node] = true;
        component.push_back(node); //REVIEW - 

        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                dfs(neighbor, adj, visited, component);
            }
        }
    }

    vector<vector<int>> connectedcomponents(int v, vector<vector<int>> &edges)
    {
        // Construct the adjacency list
        vector<vector<int>> adj(v); //REVIEW 
        for (auto &edge : edges) //REVIEW - &edge we use & for pair 
        {
            int u = edge[0], v = edge[1]; //REVIEW - 
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // To keep track of visited nodes
        vector<bool> visited(v, false);
        vector<vector<int>> components; //REVIEW - 

        // Iterate over all nodes to find components
        for (int i = 0; i < v; i++) //REVIEW - 
        {
            if (!visited[i])
            {
                vector<int> component; //REVIEW - 
                dfs(i, adj, visited, component);
                sort(component.begin(), component.end()); // Sort the component , asked in question 
                components.push_back(component); 
            }
        }

        sort(components.begin(), components.end()); // Sort the list of components
        return components;
    }
};
