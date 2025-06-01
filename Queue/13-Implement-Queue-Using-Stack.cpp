#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
    stack<int> input, output;

    void transfer()
    {
        while (!input.empty())
        {
            output.push(input.top());
            input.pop();
        }
    }

public:
    void push(int x)
    {
        cout << "Pushed: " << x << endl;
        input.push(x);
    }

    int pop()
    {
        if (output.empty())
            transfer();
        int val = output.top();
        output.pop();
        return val;
    }

    int peek()
    {
        if (output.empty())
            transfer();
        return output.top();
    }

    bool empty()
    {
        return input.empty() && output.empty();
    }

    int size()
    {
        return input.size() + output.size();
    }
};
