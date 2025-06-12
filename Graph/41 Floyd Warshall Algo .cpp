#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();
        int INF = 1e9;  // A safe large value

        // Step 1: Replace -1 with INF (for unreachable), and set 0 for diagonals
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] == -1)
                    dist[i][j] = INF; // or use 1e9
                if (i == j)
                    dist[i][j] = 0;
            }
        }

        // Step 2: Floyd-Warshall algorithm core
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // Step 3: Replace INF back with -1 for unreachable paths
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] >= INF)
                    dist[i][j] = -1;
            }
        }
    }
};
