#include <iostream>
#include <vector>
using namespace std;
class Solution
{
private:
    // dfs traversal function
    void dfs(int node, vector<int> adjLs[], int vis[])
    {
        // mark the more as visited
        vis[node] = 1;
        // REVIEW - no need to push node in vector
        for (auto it : adjLs[node])
        {
            if (!vis[it])
            {
                dfs(it, adjLs, vis);
            }
        }
    }

public:
    int numProvinces(vector<vector<int>> adj, int V)
    {
        vector<int> adjLs[V];

        //REVIEW  to change adjacency matrix to list
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                // self nodes are not considered
                if (adj[i][j] == 1 && i != j) // REVIEW - i!=j no self loop A-> A not allowed
                {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        
        int vis[V] = {0};
        int cnt = 0; 
        for (int i = 0; i < V; i++) // REVIEW  loop for v not n
        {
            // if the node is not visited
            if (!vis[i])
            {
                // counter to count the number of provinces
                dfs(i, adjLs, vis); // REVIEW -
                cnt++;              // REVIEW
            }
        }
        return cnt;
    }
};

int main()
{

    vector<vector<int>> adj{
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}};

    Solution ob;
    cout << ob.numProvinces(adj, 3) << endl;

    return 0;
}