// NOTE here middle in the floor value not ceil value
#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int> &inputStack, int count, int size)
{
    // base case:-
    if (count == size / 2)
    {
        inputStack.pop();
        return;
    }

    int num = inputStack.top();
    inputStack.pop();

    // RECURSIVE CALL
    solve(inputStack, count + 1, size); // REVIEW - count+1

    inputStack.push(num);
}

void deleteMiddle(stack<int> &inputStack, int N)
{

    int count = 0;
    solve(inputStack, count, N);
}
