#include <vector>
#include <iostream>
using namespace std ;

class MyCircularQueue
{
private:
    vector<int> queue;
    int front, rear, size, capacity;

public:
    MyCircularQueue(int k)
    {
        queue.resize(k);
        front = 0; //NOTE
        rear = -1;
        size = 0;
        capacity = k;
    }

    bool enQueue(int value)
    {
        if (isFull())
            return false;
        rear = (rear + 1) % capacity; //NOTE
        queue[rear] = value;
        size++;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;
        front = (front + 1) % capacity; //NOTE
        size--;
        return true;
    }

    int Front()
    {
        return isEmpty() ? -1 : queue[front];
    }

    int Rear()
    {
        return isEmpty() ? -1 : queue[rear];
    }

    bool isEmpty()
    {
        return size == 0; //NOTE
    }

    bool isFull()
    {
        return size == capacity; //NOTE
    }
};