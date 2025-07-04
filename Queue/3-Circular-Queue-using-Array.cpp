#include <iostream>
using namespace std;

class CircularQueue
{
    int *arr; // REVIEW
    int front;
    int rear;
    int size;

public:
    // Initialize the Circular Queue
    CircularQueue(int n)
    {
        size = n;
        arr = new int[size]; // REVIEW
        front = rear = -1;
    }

    bool enqueue(int value)
    {
        // Check if the queue is full
        if ((rear + 1) % size == front)
        {
            return false; // Queue is full
        }
        else if (front == -1) // First element case
        {
            front = rear = 0;
        }
        else
        {
            // Maintain circular nature
            rear = (rear + 1) % size;
        }
        arr[rear] = value;
        return true;
    }

    int dequeue()
    {
        // Check if the queue is empty
        if (front == -1)
        {
            return -1; // Queue is empty F
        }
        int ans = arr[front];
        arr[front] = -1; // REVIEW

        if (front = rear) // REVIEW  Last element is removed, reset queue
        {
            front = rear = -1;
        }
        else
        {
            // Maintain circular nature
            front = (front + 1) % size;
        }
        return ans;
    }
};

// Driver Code
int main()
{
    CircularQueue cq(5);

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cout << cq.dequeue() << endl; // 10
    cq.enqueue(40);
    cq.enqueue(50);
    cq.enqueue(60);               // Should fail because queue is full
    cout << cq.dequeue() << endl; // 20
    cq.enqueue(70);
    cout << cq.dequeue() << endl; // 30
}
