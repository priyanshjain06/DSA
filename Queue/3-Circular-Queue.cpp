#include <iostream>
using namespace std;
class CircularQueue
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    // Initialize your data structure :-

    CircularQueue(int n)
    {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    bool enqueue(int value)
    {
        // to check whther queue is full
        if ((front == 0 && rear == size - 1) && rear == (front - 1) % (size - 1))
        {
            return false;
        }
        else if (front == -1) // first element to push
        {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0; // to maintain cyclic nature
        }
        else
        { // normal flow
            rear++;
        }
        // push inside the queue
        arr[rear] = value;

        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue()
    {
        if (front == -1)
        { // to check queue is empty
            // cout << "Queue is Empty " << endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if (front == rear)     // REVIEW -
        {                      // single element is present
            front = rear = -1; // REVIEW -
        }
        else if (front == size - 1)
        {
            front = 0; // to maintain cyclic nature
        }
        else
        { // normal flow
            front++;
        }
        return ans;
    }
};