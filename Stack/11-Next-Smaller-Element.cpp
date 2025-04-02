// optimal approach :
#include <vector>
#include <iostream>
#include <stack>
using namespace std;
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1); //REVIEW -
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)  //REVIEW - 
    {
        int curr = arr[i];
        while (s.top() != -1 && s.top() >= curr)
        {
            s.pop();
        }   
        // ans is stack ka top
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}