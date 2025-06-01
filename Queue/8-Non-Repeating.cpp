// Given a stream of characters, the task is to process each character in the input string and, at each point, return the first non-repeating character from the stream. If no such character exists, append the character '#' to the result.

#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        unordered_map<char, int> count;
        string ans = "";
        queue<char> q; // REVIEW why not set since set doesnt maintain duplicate elemens + doesnt maintain the order !

        for (int i = 0; i < A.length(); i++)
        {
            char ch = A[i];
            q.push(ch);
            count[ch]++;

            while (!q.empty())
            {
                if (count[q.front()] > 1)
                {
                    q.pop();
                }
                else
                {
                    ans.push_back(q.front());
                    break; // REVIEW
                }
            }
            if (q.empty())
            {
                ans.push_back('#');
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends