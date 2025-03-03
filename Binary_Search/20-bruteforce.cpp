// NOTE Problem Statement: You are the owner of a Shipment company. You use conveyor belts to ship packages from one port to another. The packages must be shipped within 'd' days.
// The weights of the packages are given in an array 'of weights'. The packages are loaded on the conveyor belts every day in the same order as they appear in the array. The loaded weights must not exceed the maximum weight capacity of the ship.
// Find out the least-weight capacity so that you can ship all the packages within 'd' days.
//ANCHOR 

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> //REVIEW -  for accumulate function
using namespace std;

int findDays(vector<int> &weights, int cap)
{
    int days = 1; // First day.
    int load = 0;
    int n = weights.size(); // size of array.
    for (int i = 0; i < n; i++)
    {
        if (load + weights[i] > cap)
        {
            days += 1;         // move to next day
            load = weights[i]; // load the weight.
        }
        else
            load += weights[i];
    }
    return days;
}

int leastWeightCapacity(vector<int> &weights, int d)
{
    int maxi = *max_element(weights.begin(), weights.end());
    int sum = accumulate(weights.begin(), weights.end(), 0);

    for (int i = maxi; i <= sum; i++)
    {
        if (findDays(weights, i) <= d)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
    int d = 5;
    int ans = leastWeightCapacity(weights, d);
    cout << "The minimum capacity should be: " << ans << "\n";
    return 0;
}
