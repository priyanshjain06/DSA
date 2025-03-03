// NOTE Problem Statement: Implement Min Stack | O(2N) and O(N) Space Complexity. Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// REVIEW min = 2*val-min and prevmin = 2*min-val

#include <iostream>
#include <stack>
using namespace std;
class MinStack
{
    stack<long long> st;
    long long mini;

public:
    MinStack() // REVIEW -
    {
        while (!st.empty())
            st.pop();
        mini = INT_MAX; // REVIEW -
    }

    void push(int value)
    {

        if (st.empty())
        {
            mini = value;
            st.push(value);
        }
        else
        {
            if (value < mini)
            {
                st.push(2 * value * 1LL - mini); // REVIEW -
                mini = value;
            }
            else
            {
                st.push(value);
            }
        }
    }

    void pop()
    {
        if (st.empty())
            return;
        long long el = st.top();
        st.pop();

        if (el < mini)
        {
            mini = 2 * mini - el;
        }
    }

    int top()
    {
        if (st.empty())
            return -1;

        long long el = st.top();
        if (el < mini)
            return mini;
        return el;
    }

    int getMin()
    {
        return mini;
    }
};