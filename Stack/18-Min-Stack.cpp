// NOTE Problem Statement: Implement Min Stack | O(2N) and O(1) Space Complexity. Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

#include <iostream>
#include <stack>
using namespace std;

class Solution
{
private:
    stack<pair<int, int>> s; // Stores (value, minimum so far) //REVIEW -  make the stack pair

public:
    Solution() {}

    // Add an element to the top of Stack
    void push(int x)
    {
        int minVal = s.empty() ? x : min(x, s.top().second);
        // REVIEW s.top().second not minVal
        s.push({x, minVal});
    }

    // Remove the top element from the Stack
    void pop()
    {
        if (!s.empty())
        {
            s.pop();
        }
    }

    // Returns top element of the Stack
    int peek()
    {
        return s.empty() ? -1 : s.top().first;
    }

    // Finds minimum element of Stack
    int getMin()
    {
        return s.empty() ? -1 : s.top().second;
    }
};