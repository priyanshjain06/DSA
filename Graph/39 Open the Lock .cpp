#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        // If "0000" is a deadend, we can't start
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000"))
            return -1;

        // If target is "0000", no turns needed
        if (target == "0000")
            return 0;

        // Queue for BFS: {current_combination, turns}
        queue<pair<string, int>> q;
        q.push({"0000", 0});

        // Track visited combinations to avoid cycles
        unordered_set<string> visited;
        visited.insert("0000");

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            string lock = curr.first;
            int turns = curr.second;

            // Try rotating each of the 4 digits up or down
            for (int i = 0; i < 4; i++)
            {
                char original = lock[i];
                // Rotate up
                lock[i] = (original == '9' ? '0' : original + 1);
                // REVIEW -
                if (lock == target)
                    return turns + 1;
                if (!dead.count(lock) && !visited.count(lock))
                {
                    visited.insert(lock);
                    q.push({lock, turns + 1});
                }
                // Rotate down
                lock[i] = (original == '0' ? '9' : original - 1);
                if (lock == target)
                    return turns + 1;
                if (!dead.count(lock) && !visited.count(lock))
                {
                    visited.insert(lock);
                    q.push({lock, turns + 1});
                }
                // Restore original digit
                lock[i] = original; // REVIEW -
            }
        }

        // If target is unreachable
        return -1;
    }
};