// REVIEW :
// 1) Empty condition: qfront == -1 && rear == -1
// 2) Queue becomes empty after dequeue when qfront > rear
// 3) Overflow condition: rear == size - 1 (queue is full)

#include <iostream>
using namespace std;
class Queue
{
    int *arr;
    int qfront;
    int rear;
    int size;

public:
    Queue()
    {
        size = 100001;
        arr = new int[size]; // REVIEW
        qfront = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        return (qfront == -1 && rear == -1 // || qfront > rear
                );
    }

    void enqueue(int data)
    {
        if (rear == size - 1)
        {
            cout << "Queue is Full" << endl;
            return;
        }
        if (isEmpty())
        {
            qfront = 0; // First element insertion
        }
        rear++;
        arr[rear] = data;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            return -1; // Queue underflow
        }

        int deletedElement = arr[qfront];
        qfront++;

        if (qfront > rear) // REVIEW
        {                  // Reset queue when empty
            qfront = rear = -1;
        }
        return deletedElement;
    }

    int front()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[qfront];
    }
};