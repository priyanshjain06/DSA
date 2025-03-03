// REVIEW time complexity : O(2^n) *  total number of subsets
#include <iostream>
#include <vector>
using namespace std;

void printSubsets(const vector<int> &set)
{
    int n = set.size();
    int totalSubsets = 1 << n; // 2^n subsets

    for (int mask = 0; mask < totalSubsets; ++mask)
    {
        cout << "{ ";
        for (int i = 0; i < n; ++i) //REVIEW - 
        {
            if (mask & (1 << i))
            {
                cout << set[i] << " ";
            }
        }
        cout << "}" << endl;
    }
}

int main()
{
    vector<int> set = {1, 2, 3};
    cout << "All subsets of the set are:" << endl;
    printSubsets(set);
    return 0;
}
