// STUB -  Difference between stack and queue implementation using linklist:

// Stack =>It is Static, Needs to provide space Before implementation.
// Overflow occurs when queue size reaches its maximum capacity

// Queue =>Nodes are allocated dynamically, so the queue can grow and shrink as much as needed.
//  Overflow is not possible until and unless the heap memory got exhausted.

#include <iostream>
using namespace std;

class QueueNode
{
public:
    int val;
    QueueNode *next;
    QueueNode(int data)
    {
        val = data;
        next = nullptr;
    }
};
QueueNode *Front = nullptr, *Rare = nullptr; // REVIEW -
class Queue
{
public:
    int size = 0;
    bool Empty();
    void Enqueue(int value);
    void Dequeue();
    int Peek();
};
bool Queue ::Empty()
{
    return Front == nullptr;
}
int Queue ::Peek()
{
    if (Empty())
    {
        cout << "Queue is Empty" << endl;
        return -1;
    }
    else
        return Front->val;
}
void Queue ::Enqueue(int value)
{
    QueueNode *Temp;
    Temp = new QueueNode(value);
    if (Temp == nullptr) // When heap exhausted //REVIEW - empty
        cout << "Queue is Full" << endl;
    else
    {
        if (Front == nullptr)
        {
            Front = Temp;
            Rare = Temp;
        }
        else
        {
            Rare->next = Temp;
            Rare = Temp;
        }
        cout << value << " Inserted into Queue " << endl;
        size++; // REVIEW
    }
}
void Queue ::Dequeue()
{
    if (Front == nullptr)
        cout << "Queue is Empty" << endl;
    else
    {
        cout << Front->val << " Removed From Queue" << endl;
        QueueNode *Temp = Front;
        Front = Front->next;
        delete Temp;
        size--; //REVIEW - 
    }
}
