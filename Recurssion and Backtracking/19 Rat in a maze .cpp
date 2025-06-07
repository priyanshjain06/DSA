// REVIEW  Time Complexity : O(4^(n*m)) and Space Complexity : O(n*m)
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    void solve(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move,
               vector<vector<int>> &vis, int di[], int dj[]) // REVIEW i ,j move is string
    {
        if (i == n - 1 && j == n - 1) // coz of next
        {
            ans.push_back(move);
            return;
        }
        string dir = "DLRU";
        for (int ind = 0; ind < 4; ind++) // REVIEW till 4
        {
            int nexti = i + di[ind];
            int nextj = j + dj[ind];
            if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && a[nexti][nextj] == 1)
            {
                vis[i][j] = 1;
                solve(nexti, nextj, a, n, ans, move + dir[ind], vis, di, dj); // REVIEW 9 things
                // REVIEW - move +dir[ind] . remember the i j call here
                vis[i][j] = 0;
            }
        }
    }
    
public:
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0)); // REVIEW

        int di[] = {
            +1,
            0,
            0,
            -1};

        int dj[] = {
            0,
            -1,
            1,
            0};

        // REVIEW here m is 2d array represeting the maze and n is dimension 3*3 and 4*4 like this
        if (m[0][0] == 1)
            solve(0, 0, m, n, ans, "", vis, di, dj); // 9 Review
        return ans;
    }
};
