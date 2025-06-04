// REVIEW - Time Complexity : O(N^M) ,m= number of colors and Space Complexity : O(N)
#include <iostream>
#include <vector>   
#include <string>
using namespace std;
bool isSafe(int node, int color[], bool graph[101][101], int n, int m)
{
    for (int k = 0; k < n; k++)
    {
        if (k != node && graph[k][node] == 1 && color[k] == m)
        {
            return false;
        }
    }
    return true;
}

bool solve(int node, int color[], int m, int N, bool graph[101][101])
{
    if (node == N)
    {
        return true;
    }

    for (int i = 1; i <= m; i++) // ANCHOR m is color here
    {
        if (isSafe(node, color, graph, N, i)) // REVIEW i becomes count of color
        {
            color[node] = i;
            if (solve(node + 1, color, m, N, graph) == true )
                return true;
            color[node] = 0; // REVIEW Backtrack
        }
    }
    return false; //REVIEW
}

// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
bool graphColoring(bool graph[101][101], int m, int N)
{
    int color[101] = {0}; //NOTE  use color[N]
    if (solve(0, color, m, N, graph) == true)
        return true; //REVIEW - 
    return false; //REVIEW
} 

int main()
{
    int N = 4;
    int m = 3;

    bool graph[101][101];
    memset(graph, false, sizeof graph);

    // Edges are (0, 1), (1, 2), (2, 3), (3, 0), (0, 2)
    graph[0][1] = 1;
    graph[1][0] = 1;
    graph[1][2] = 1;
    graph[2][1] = 1;
    graph[2][3] = 1;
    graph[3][2] = 1;
    graph[3][0] = 1;
    graph[0][3] = 1;
    graph[0][2] = 1;
    graph[2][0] = 1;

    cout << graphColoring(graph, m, N);
}