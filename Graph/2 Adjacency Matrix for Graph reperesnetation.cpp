using namespace std;
#include <iostream>
int main()
{
    int n, m;
    cin >> n >> m;
    // adjacency matrix for undirected graph
    // time complexity: O(n)
    int adj[n + 1][n + 1]; // REVIEW - 1 based indexing
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1 // this statement will be removed in case of directed graph
    }
    return 0;
}