// NOTE You are given a matrix M of size n x n where:

// M[i][j] = 1 means person i knows person j.
// M[i][j] = 0 means person i does not know person j.
// You need to find if there is a celebrity in the party, and return the celebrity’s index. If there is no celebrity, return -1.

// ANCHOR -  Time Complexity: O(n) and Space Complexity: O(n)

// LINK we will use stack

// REVIEW -  For algo see screenshot . It has  2 edge cases: Avoid checking for diagonals of the matrix
// and
//  CONDITION for Celebrity ====> for row  all elements should be 0 and for column all elements should be 1

// Initial template for C++

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
private:
    bool knows(vector<vector<int>> &M, int a, int b, int n)
    {
        if (M[a][b] == 1)
            return true;
        else
            return false;
    }

public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> s;
        // step1: push all element in stack
        for (int i = 0; i < n; i++)
        {
            s.push(i);
        }

        // step2: get 2 elements untill size>1

        while (s.size() > 1)
        {

            int a = s.top();
            s.pop();

            int b = s.top();
            s.pop();

            if (knows(M, a, b, n))
            {
                s.push(b); // REVIEW if a knows b then push b back
            }
            else
            {
                s.push(a);
            }
        }
        int ans = s.top();
        // step3: single element in stack is potential celeb
        // so verify it

        int zeroCount = 0;

        for (int i = 0; i < n; i++)
        {
            if (M[ans][i] == 0)
                zeroCount++;
        }

        // if not all  row elements are 0
        if (zeroCount != n)
            return -1;

        // column check
        int oneCount = 0;

        for (int i = 0; i < n; i++)
        {
            if (M[i][ans] == 1)
                oneCount++;
        }

        if (oneCount != n - 1) // REVIEW to avoid daigonal
            return -1;

        return ans;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M, n) << endl;
    }
}
// } Driver Code Ends