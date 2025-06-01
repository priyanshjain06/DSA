// REVIEW : 1) Conditions:  if(qfront == rear)  underflow and empty conditions. 2) Overflow:  if(rear == size)  overflow condition.

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
        arr = new int[size];
        qfront = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        return (qfront == -1 && rear == -1  // || qfront > rear
                || qfront == rear);
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
        if (qfront > rear) //REVIEW 
        { // Reset queue when empty
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