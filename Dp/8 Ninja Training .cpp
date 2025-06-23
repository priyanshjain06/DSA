// REVIEW recurssive solution : Time : O(3^n) and space : O(n) + O(n)
#include <iostream>
#include <vector>
using namespace std;

int f(int day, int last, vector<vector<int>> &points)
{
    if (day == 0) // REVIEW this is the base case
    {
        int maxPoints = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                maxPoints = max(maxPoints, points[0][i]);
            }
        }
        return maxPoints;
    }

    int maxPoints = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            int total = points[day][i] + f(day - 1, i, points);
            maxPoints = max(maxPoints, total);
        }
    }

    return maxPoints;
}

// REVIEW -  memorization
// TIME  O(N*4*3) and Space O(N) + O(N*4)

using namespace std;

int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{

    if (dp[day][last] != -1)
        return dp[day][last];

    // SECTION Base case
    if (day == 0)
    {
        int maxi = 0;

        for (int i = 0; i <= 2; i++)
        {
                maxi = max(maxi, points[0][i]);
        }
        return dp[day][last] = maxi; // SECTION -
    }

    int maxi = 0;
    for (int i = 0; i <= 2; i++)
    {
        if (i != last)
        {

            int activity = points[day][i] + f(day - 1, i, points, dp);
            maxi = max(maxi, activity);
        }
    }

    return dp[day][last] = maxi; // SECTION -
}

// REVIEW  Tabulation
//  Time Complexity :  O(N*4*3) and Space Complexity :O(N*4)

using namespace std;

int ninjaTraining(int n, vector<vector<int>> &points)
{

    vector<vector<int>> dp(n, vector<int>(4, 0));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2])); // SECTION -

    for (int day = 1; day < n; day++) // SECTION -
    {
        for (int last = 0; last < 4; last++) // SECTION -
        {
            dp[day][last] = 0;
            for (int task = 0; task <= 2; task++)
            {
                if (task != last)
                {
                    int activity = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], activity);
                }
            }
        }
    }

    return dp[n - 1][3];
}

// REVIEW - Space Optimization
//  Time Complexity :  O(N*4*3) and Space Complexity :O(4)

using namespace std;

int ninjaTraining(int n, vector<vector<int>> &points)
{

    vector<int> prev(4, 0); // SECTION -

    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++)
    {

        vector<int> temp(4, 0);
        for (int last = 0; last < 4; last++)
        {
            temp[last] = 0; //! SECTION
            for (int task = 0; task <= 2; task++)
            {
                if (task != last)
                {

                    temp[last] = max(temp[last], points[day][task] + prev[task]);
                }
            }
        }
        prev = temp; // SECTION
    }

    return prev[3]; // SECTION -
}