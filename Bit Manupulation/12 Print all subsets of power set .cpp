// REVIEW time complexity : O(2^n) *  total number of subsets
#include <iostream>
#include <vector>
using namespace std;

void printSubsets(const vector<int> &set)
{
    int n = set.size();
    int totalSubsets = 1 << n; // REVIEW  2^n subsets

    for (int mask = 0; mask < totalSubsets; ++mask) // REVIEW
    {
        cout << "{ ";
        for (int i = 0; i < n; ++i) // REVIEW -
        {
            if (mask & (1 << i)) // REVIEW check if the ith bit is set
            {
                cout << set[i] << " ";
            }
        }
        cout << "}" << endl;
    }
}
