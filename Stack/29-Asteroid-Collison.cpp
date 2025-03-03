// NOTE Problem Recap:
//  You are given an array of asteroids, where:

// Positive values (i >= 0) represent asteroids moving right.
// Negative values (i < 0) represent asteroids moving left.
// The task is to simulate collisions between these asteroids:

// When a right-moving and left-moving asteroid meet, the smaller one explodes.
// If they are the same size, both explode.
// Two asteroids moving in the same direction (both positive or both negative) never collide.

//LINK -  you can also solve this by using a linklist 

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &a)
    {
        stack<int> st;
        vector<int> ans;
        for (auto i : a)
        {
            if (i >= 0)
            {
                st.push(i);
            }
            else
            {
                //if abs(i)<st.top() then it will never enter the stack
                while (!st.empty() && st.top() > 0 && abs(i) > st.top())
                {
                    st.pop();
                }
                if (!st.empty() && abs(i) == st.top())
                {
                    st.pop();
                }
                else
                {
                    if (st.empty() || st.top() < 0)
                    {
                        st.push(i);
                    }
                }
            }
        }
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};