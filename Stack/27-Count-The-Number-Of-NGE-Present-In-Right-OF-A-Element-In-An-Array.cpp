#include <iostream>
#include <vector>
using namespace std;

// REVIEW this is brute force , no need for optimal approach
//NOTE read the question

class Solution
{
public:
    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices)
    {
        vector<int> result;
        for (int i = 0; i < indices.size(); i++)
        {
            int threshold = indices[i];
            int countGreaterElements = 0;
            for (int j = threshold + 1; j < n; j++)
            {
                if (arr[j] > arr[threshold])
                {
                    countGreaterElements += 1;
                }
            }
            result.push_back(countGreaterElements);
        }
        return result;
    }
};
