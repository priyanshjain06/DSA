#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int> &stack, int x)
{
    // base case
    if (stack.empty())
    {
        stack.push(x);
        return;
    }

    int num = stack.top();
    stack.pop();

    // recursive call
    solve(stack, x);

    stack.push(num);
}

stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    solve(myStack, x);
    // x is the number that we have to insert at bottom of the stack
    return myStack;
}
