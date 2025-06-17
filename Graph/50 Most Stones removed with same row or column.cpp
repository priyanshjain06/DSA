#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class DisjointSet
{
    vector<int> parent, size;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]); // path compression
    }

    void unionBySize(int u, int v)
    {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv)
            return;
        if (size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution
{
public:
    int removeStones(vector<vector<int>> &stones)
    {
        int maxRow = 0, maxCol = 0;
        for (auto &it : stones)
        {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int, int> stoneNodes; // REVIEW we can use set also more optimal but less optimal for more than 10^4 nodes and more suitable for dynamic graphs !

        for (auto &it : stones)
        {
            int rowNode = it[0];
            int colNode = it[1] + maxRow + 1;
            ds.unionBySize(rowNode, colNode);
            stoneNodes[rowNode] = 1;
            stoneNodes[colNode] = 1;
        }

        int components = 0;
        for (auto &it : stoneNodes) // REVIEW hashmap is traversed !
        {
            if (ds.findUPar(it.first) == it.first)
                components++;
        }

        return stones.size() - components;
    }
};
