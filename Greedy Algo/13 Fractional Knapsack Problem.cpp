#include <iostream>
#include <algorithm>
using namespace std;

struct Item // NOTE -  you will have to declare this in gfg platform
{
    int value;
    int weight;
};

class Solution
{
public:
    bool static comp(Item a, Item b)
    {
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        return r1 > r2;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {

        sort(arr, arr + n, comp);

        int curWeight = 0;
        double finalvalue = 0.0;

        for (int i = 0; i < n; i++)
        {

            if (curWeight + arr[i].weight <= W)
            {
                curWeight += arr[i].weight;
                finalvalue += arr[i].value;
            }
            else
            {
                int remain = W - curWeight;
                finalvalue += (arr[i].value / (double)arr[i].weight) * (double)remain;
                break; // REVIEW
            }
        }
        return finalvalue;
    }
};
