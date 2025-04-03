// NOTE  example : 1234 for k = 2 then output will be  2134

// NOTE You are given a queue of integers and an integer k. Your task is to reverse the first k elements of the queue, while leaving the remaining elements in the same order. The goal is to modify the queue and return the resulting queue.

#include <iostream>
#include <queue>
#include <stack>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0)
        {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty())
        {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
} // } Driver Code Ends

// User function Template for C++

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k)
{
    // algo: //REVIEW -
    // first k element stack me daaldo  and queue se hatado
    //  k element stack se nikalke wapas queue me daalde
    //  fir queue k (n-k) starting k elements, wapas queue me daalde

    stack<int> s;

    for (int i = 0; i < k; i++)
    {
        int val = q.front();
        q.pop();
        s.push(val);
    }

    while (!s.empty())
    {
        int val = s.top();
        s.pop();
        q.push(val);
    }

    int t = q.size() - k; // n-k

    while (t--) 
    {
        int val = q.front();
        q.pop();
        q.push(val);
    }

    return q;
}