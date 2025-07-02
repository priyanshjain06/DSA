// NOTE Problem Statement: You are the owner of a Shipment company. You use conveyor belts to ship packages from one port to another. The packages must be shipped within 'd' days.
// The weights of the packages are given in an array 'of weights'. The packages are loaded on the conveyor belts every day in the same order as they appear in the array. The loaded weights must not exceed the maximum weight capacity of the ship.
// Find out the least-weight capacity so that you can ship all the packages within 'd' days.
// ANCHOR  O(N * log(sum(weights[]) - max(weights[]) + 1))
// REVIEW -  here range will be from max element of weight and sum of all  weight array

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
        {
            // load the weight on the same day.
            load += weights[i];
        }
    }
    return days;
}

int leastWeightCapacity(vector<int> &weights, int d)
{
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0); // REVIEW -  for accumulate function remeber the syntax
    
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int numberOfDays = findDays(weights, mid);
        if (numberOfDays <= d)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}
