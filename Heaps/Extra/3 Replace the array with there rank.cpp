#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> replaceWithRank(vector<int> &arr, int N)
    {
        // Create a copy of the array and sort it to determine ranks
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end()); //REVIEW - 

        // Create a map to store the rank of each element
        unordered_map<int, int> rankMap; //REVIEW - 

        // Rank starts from 1, and we assign ranks to elements
        int rank = 1; //REVIEW - 
        for (int i = 0; i < N; i++)
        {
            if (rankMap.find(sortedArr[i]) == rankMap.end())
            {
                rankMap[sortedArr[i]] = rank;
            }
            // If the element is the same as the previous one, it gets the same rank
            if (i < N - 1 && sortedArr[i] != sortedArr[i + 1])
            {
                rank++;
            }
        }

        // Replace each element in the original array with its rank
        for (int i = 0; i < N; i++)
        {
            arr[i] = rankMap[arr[i]];
        }

        return arr;
    }
};

// Driver Code
int main()
{
    int t = 1;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> vec(n);
        for (int i = 0; i < n; i++)
            cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec, n);
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}
