// NOTE You are given a queue Q of N integers of even length, rearrange the elements by interleaving the first half of the queue with the second half of the queue.

// STUB -  Restrection : Don't use extra queue except the input queue!

// LINK 
// 0) CHeck if the input is even or odd
//  1) push the first half of the queue into a stack
//  2) push elements from stack to queue
//  3) pop the first half of the queue and push them back into the queue
//  4) push the first half of the queue again back into the stack
//  5) Now insert the elements from the stack back into the queue in correct order

#include <iostream>
#include <queue>
#include <stack>
using namespace std;
void interLeaveQueue(queue<int> &q)
{
    // To check the even number of elements
    if (q.size() % 2 != 0)
        cout << "Input even number of integers." << endl;

    stack<int> s;
    int halfSize = q.size() / 2; //REVIEW - 

    // Push first half elements into the stack
    // queue:16 17 18 19 20, stack: 15(T) 14 13 12 11

    for (int i = 0; i < halfSize; i++)
    {
        s.push(q.front());
        q.pop();
    }

    // enqueue back the stack elements
    // queue: 16 17 18 19 20 15 14 13 12 11
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    // dequeue the first half elements of queue
    // and enqueue them back
    // queue: 15 14 13 12 11 16 17 18 19 20
    for (int i = 0; i < halfSize; i++)
    {
        q.push(q.front());
        q.pop();
    }

    // Again push the first half elements into the stack
    // queue: 16 17 18 19 20, stack: 11(T) 12 13 14 15
    for (int i = 0; i < halfSize; i++)
    {
        s.push(q.front());
        q.pop();
    }

    // interleave the elements of queue and stack
    // queue: 11 16 12 17 13 18 14 19 15 20
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}

// Driver program to test above function
int main()
{
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);
    interLeaveQueue(q);
    int length = q.size();
    for (int i = 0; i < length; i++)
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
