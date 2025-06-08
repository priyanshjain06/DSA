#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>> &adjacencyList, int source)
    {
        int vertices = adjacencyList.size();
        vector<int> distance(vertices, INT_MAX); // Stores shortest distance to each node
        queue<int> processingQueue;

        // Initialize BFS from source node
        distance[source] = 0;
        processingQueue.push(source);

        while (!processingQueue.empty())
        {
            int currentNode = processingQueue.front();
            processingQueue.pop();

            for (int neighbor : adjacencyList[currentNode])
            {
                if (distance[neighbor] == INT_MAX)
                { // If not visited
                    distance[neighbor] = distance[currentNode] + 1;
                    processingQueue.push(neighbor);
                }
            }
        }

        // Replace unreachable nodes with -1 (as per standard convention)
        for (int i = 0; i < vertices; i++)
        {
            if (distance[i] == INT_MAX)
            {
                distance[i] = -1;
            }
        }
        return distance;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(adj, src);

        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << "\n";
        cout << "~\n";
    }
}

// } Driver Code Ends