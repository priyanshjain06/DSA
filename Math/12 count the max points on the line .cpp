#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        if (n <= 2)
            return n;

        int maxPointsOnLine = 0;

        for (int i = 0; i < n; ++i)
        {
            unordered_map<string, int> slopeCount;
            int duplicates = 1; // count point i itself

            for (int j = i + 1; j < n; ++j)
            {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0)
                {
                    // same point
                    duplicates++;
                    continue;
                }

                // REVIEW (6, 3) and (2, 1) represent the same slope, but in different magnitude !
                // REVIEW We reduce the slope to its lowest terms using GCD so that:
                // REVIEW All equivalent slopes map to the same key.

                int gcdVal = gcd(dx, dy);
                dx /= gcdVal;
                dy /= gcdVal;

                // Normalize slope direction to avoid confusion between (1, -1)
                // and (-1, 1)
                if (dx < 0)
                {
                    dx = -dx;
                    dy = -dy;
                }

                string slopeKey = to_string(dy) + "/" + to_string(dx);
                slopeCount[slopeKey]++;
            }

            int localMax = 0;
            for (auto &[slope, count] : slopeCount)
            {
                localMax = max(localMax, count);
            }

            maxPointsOnLine = max(maxPointsOnLine, localMax + duplicates);
        }

        return maxPointsOnLine;
    }

private:
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
};
