#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canPlaceCows(const vector<int> &stalls, int dist, int cows)
{
    int count = 1;
    int last_pos = stalls[0];

    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - last_pos >= dist)
        {
            count++;
            last_pos = stalls[i];
            if (count >= cows)
                return true;
        }
    }
    return false;
}

int aggressiveCowsBruteForce(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int max_dist = stalls.back() - stalls.front();
    int result = 0;

    // Try every possible distance from 1 to max_dist
    for (int dist = 1; dist <= max_dist; dist++)
    {
        if (canPlaceCows(stalls, dist, k))
        {
            result = dist; // Update if this distance works
        }
        else
        {
            break; // Since we're checking in order, we can break when first failure occurs
        }
    }
    return result;
}

int main()
{
    vector<int> stalls = {0, 3, 4, 7, 9, 10};
    int k = 4;
    int ans = aggressiveCowsBruteForce(stalls, k);
    cout << "The maximum possible minimum distance (brute force) is: " << ans << "\n";
    return 0;
}