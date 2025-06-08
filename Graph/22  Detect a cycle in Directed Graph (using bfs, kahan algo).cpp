#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<vector<int>> &adj)
    {
        vector<int> indegree(V, 0), topoOrder;
        queue<int> q;

        // Compute in-degree of each node
        for (int i = 0; i < V; i++)
        {
            for (int neighbor : adj[i])
            {
                indegree[neighbor]++;
            }
        }

        // Push nodes with 0 in-degree
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
  
        
        int count = 0; // To track visited nodes

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topoOrder.push_back(node);
            count++;//REVIEW -  

            // Reduce in-degree of neighbors
            for (int neighbor : adj[node])
            {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        // If count != V, it means there's a cycle (no valid topological order)
        if (count != V)
        { // REVIEW -
            cout << "Cycle detected! No valid topological order.\n";
            return {}; // Return empty vector
        }

        return topoOrder;
    }
};