// NOTE You are given a matrix M of size n x n where:

// M[i][j] = 1 means person i knows person j.
// M[i][j] = 0 means person i does not know person j.
// You need to find if there is a celebrity in the party, and return the celebrity’s index. If there is no celebrity, return -1.

// ANCHOR Time Complexity: O(N), Space Complexity: O(1)

// LINK -  use two pointer approach here =>

// REVIEW -  Now remember we use i!= candidate to avoid daigonal elements

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int celebrity(vector<vector<int>> &M, int n)
    {
        int candidate = 0;

        // Step 1: Find the celebrity candidate
        for (int i = 1; i < n; i++) // REVIEW from 1
        {
            if (M[candidate][i] == 1) //FIXME
            {
                // candidate knows i, so candidate cannot be a celebrity
                candidate = i;
            }
            // so i is our potenial celebrity
        }

        // Step 2: Verify the candidate (check i  which is potenial celebrity)
        for (int i = 0; i < n; i++) // REVIEW -  from 0
        {
            // Check if the candidate knows anyone, or if anyone doesn't know the candidate

            if (i != candidate && (M[candidate][i] == 1 || M[i][candidate] == 0))
            {
                return -1;
                // Not a celebrity
            }
        }

        // If passed all checks, the candidate is a celebrity
        return candidate; //REVIEW - 
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> M = {{0, 1, 0},
                             {0, 0, 0},
                             {0, 1, 0}};
    int n = 3;
    int result = obj.celebrity(M, n);
    if (result == -1)
        cout << "No celebrity in the party." << endl;
    else
        cout << "Celebrity is person " << result << endl;

    return 0;
}
