// NOTE - Problem Statement: Given a linked list of 0s, 1s and 2s, sort the list without using any data structure

// ANCHOR -  Time Complexity is : O(n) and space Complexity is O(1)

// LINK -  Edge cases to remember it may be possible that 1s linklist remains empty so handle this case while merging the linklist

#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(Node *&tail, Node *curr) //REVIEW - & becuase tail is pointer 
{
    tail->next = curr;
    tail = curr;
}

Node *sortList(Node *head)
{
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;
    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;
    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;
    
    Node *curr = head;

    // create separate list 0s, 1s and 2s
    while (curr != NULL)
    {

        int value = curr->data;

        if (value == 0)
        {
            insertAtTail(zeroTail, curr);
        }
        else if (value == 1)
        {
            insertAtTail(oneTail, curr);
        }
        else if (value == 2)
        {
            insertAtTail(twoTail, curr);
        }
        curr = curr->next;
    }

    // merge 3 sublist
    // 1s list not empty
    if (oneHead->next != NULL)
    {
        zeroTail->next = oneHead->next;
    }
    else
    {
        // 1s list -> empty
        zeroTail->next = twoHead->next;
    }

    oneTail->next = twoHead->next; // REVIEW -
    twoTail->next = NULL;          // REVIEW -

    // setup head
    head = zeroHead->next;

    // delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return head;
}
