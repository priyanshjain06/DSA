#include <iostream>
#include <queue>
using namespace std;
class Stack
{
    queue<int> q;

public:
    void Push(int x)
    {
        // Step 1: Get the current size of the queue
        int s = q.size();

        // Step 2: Push the new element 'x' to the back of the queue
        q.push(x);

        // Step 3: Move all the elements that were previously in the queue to the back
        for (int i = 0; i < s; i++)
        {
            // Push the front element to the back of the queue
            q.push(q.front());
            // Remove the front element from the queue
            q.pop();
        }
    }
    int Pop()
    {
        int n = q.front();
        q.pop();
        return n;
    }
    int Top()
    {
        return q.front();
    }
    int Size()
    {
        return q.size();
    }
};

int main()
{
    Stack s;
    s.Push(3);
    s.Push(2);
    s.Push(4);
    s.Push(1);
    cout << "Top of the stack: " << s.Top() << endl;
    cout << "Size of the stack before removing element: " << s.Size() << endl;
    cout << "The deleted element is: " << s.Pop() << endl;
    cout << "Top of the stack after removing element: " << s.Top() << endl;
    cout << "Size of the stack after removing element: " << s.Size();
}