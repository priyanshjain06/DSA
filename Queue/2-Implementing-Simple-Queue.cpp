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
        if (qfront == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int data)
    {
        if (rear == size)
            cout << "Queue is Full" << endl;
        else
        {
            rear++;
            arr[rear] = data;
        }
    }
    int dequeue()
    {
        if (qfront == rear)
        {
            return -1;
        }
        else
        {
            int deletedElement = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if (qfront == rear)
            {
                qfront = 0;
                rear = 0;
            }
            return deletedElement;
        }
    }

    int front()
    {
        if (qfront == rear)
        {
            return -1;
        }
        else
        {
            return arr[qfront];
        }
    }
};