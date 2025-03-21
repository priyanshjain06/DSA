#include <iostream>
#include <vector>
using namespace std;

// REVIEW this is brute force , no need for optimal approach
class Solution
{
public:
    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices)
    {
        vector<int> result;
        for (int i = 0; i < indices.size(); i++)
        {
            int index = indices[i];
            int countGreaterElements = 0;
            for (int j = index + 1; j < n; j++)
            {
                if (arr[j] > arr[index])
                {
                    countGreaterElements += 1;
                }
            }
            result.push_back(countGreaterElements);
        }
        return result;
    }
};
