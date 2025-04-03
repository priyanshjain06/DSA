#include <iostream>
using namespace std;

class Deque
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    // Initialize the Deque
    Deque(int n)
    {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Pushes 'X' to the front of the deque
    bool pushFront(int x)
    {
        if (isFull())
            return false;

        if (isEmpty()) // First element insertion
        {
            front = rear = 0;
        }
        else
        {
            front = (front - 1 + size) % size; // Move front backwards circularly
        }
        arr[front] = x;
        return true;
    }

    // Pushes 'X' to the back of the deque
    bool pushRear(int x)
    {
        if (isFull())
            return false;

        if (isEmpty()) // First element insertion
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % size; // Move rear forward circularly
        }
        arr[rear] = x;
        return true;
    }

    // Pops an element from the front
    int popFront()
    {
        if (isEmpty())
            return -1;

        int ans = arr[front];
        arr[front] = -1;

        if (front == rear) // If only one element was present
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % size; // Move front forward circularly
        }
        return ans;
    }

    // Pops an element from the back
    int popRear()
    {
        if (isEmpty())
            return -1;

        int ans = arr[rear];
        arr[rear] = -1;

        if (front == rear) // If only one element was present
        {
            front = rear = -1;
        }
        else
        {
            rear = (rear - 1 + size) % size; // Move rear backward circularly
        }
        return ans;
    }

    // Returns the first element
    int getFront()
    {
        if (isEmpty())
            return -1;
        return arr[front];
    }

    // Returns the last element
    int getRear()
    {
        if (isEmpty())
            return -1;
        return arr[rear];
    }

    // Checks if the deque is empty
    bool isEmpty()
    {
        return front == -1;
    }

    // Checks if the deque is full
    bool isFull()
    {
        return ((rear + 1) % size == front);
    }
};

// Driver Code
int main()
{
    Deque dq(5);

    dq.pushRear(10);
    dq.pushRear(20);
    dq.pushFront(5);
    dq.pushFront(1);
    dq.pushRear(30);               // Should succeed
    cout << dq.popFront() << endl; // 1
    cout << dq.popRear() << endl;  // 30
    dq.pushFront(50);
    cout << dq.popRear() << endl; // 20
}
