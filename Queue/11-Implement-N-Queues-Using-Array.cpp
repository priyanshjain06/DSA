#include <iostream>
using namespace std;
class kQueue
{
public:
    int n;
    int s;
    int *front;
    int *rear;
    int *arr;
    int freeSpot;
    int *next;

public:
    kQueue(int n, int k)
    {
        this->n = n;
        this->s = s;
        front = new int[s];
        rear = new int[k];
        // initialize all elements of front and rear as -1
        for (int i = 0; i < k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }

        // instiallise all elements of next as i+1
        next = new int[n];

        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }

        // REVIEW -  last index -1
        next[n - 1] = -1;

        arr = new int[n];
        freeSpot = 0;
    }
    
    void enqueue(int data, int qn)
    {

        // overflow
        if (freeSpot == -1)
        {
            cout << "No Empty space is present" << endl;
            return;
        }

        // find first free index
        int index = freeSpot;

        // update freespot
        freeSpot = next[index];

        // check whether first element
        if (front[qn - 1] == -1)
        {
            front[qn - 1] = index;
        }
        else
        {
            // link new element to the prev element
            next[rear[qn - 1]] = index;
            // REVIEW -  Why we use rear[qn-1]? =>Refer screenshot
        }

        // update next
        next[index] = -1;

        // update rear
        rear[qn - 1] = index;

        // push element
        arr[index] = data;
    }

    int dequeue(int qn)
    {
        // underflow
        if (front[qn - 1] == -1)
        {
            cout << "Queue UnderFlow " << endl;
            return -1;
        }

        // find index to pop
        int index = front[qn - 1];

        // front ko aage badhao
        front[qn - 1] = next[index];

        // freeSlots ko manage karo
        next[index] = freeSpot;
        freeSpot = index;
        return arr[index];
    }
};