#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int totalGas = 0, totalCost = 0;
        int currGas = 0;
        int startStation = 0;

        for (int i = 0; i < gas.size(); i++)
        {
            totalGas += gas[i];
            totalCost += cost[i];
            currGas += gas[i] - cost[i];

            if (currGas < 0)
            {
                startStation = i + 1;
                currGas = 0;
            }
        }

        return totalGas < totalCost ? -1 : startStation;
    }
};
