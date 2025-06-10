// REVIEW if the  number is more than 10^5 than we will need to find its mod !

// User function Template for C++

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        // Edge case: if start is already equal to end
        if (start == end)
            return 0;

        // Queue for BFS: {current_value, steps_taken}
        queue<pair<int, int>> q;
        q.push({start, 0});

        // Distance array to track minimum multiplications needed
        vector<int> dist(100000, 1e9);
        dist[start] = 0;

        int mod = 100000; // REVIEW 10^5

        while (!q.empty())
        {
            auto [node, steps] = q.front(); // REVIEW or use auto it
            q.pop();

            for (int num : arr)
            {
                int next = (num * node) % mod;

                if (steps + 1 < dist[next]) //REVIEW 
                {
                    dist[next] = steps + 1;

                    if (next == end)
                        return steps + 1;

                    q.push({next, steps + 1});
                }
            }
        }

        // If end value is unreachable
        return -1;
    }
};
