// NOTE - Problem Statement: Given a linked list of 0s, 1s and 2s, sort the list

// ANCHOR -  Time Complexity is : O(n) and space Complexity is O(1)

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

Node *SortList(Node *head)
{
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zeroCount++;
        }
        else if (temp->data == 1)
        {
            oneCount++;
        }
        else
        {
            twoCount++;
        }
        temp = temp->next;
    }

    temp = head;

    while (temp != NULL)
    {
        if (zeroCount > 0)
        {
            temp->data = 0;
            zeroCount--;
        }
        else if (oneCount > 0)
        {
            temp->data = 1;
            oneCount--;
        }
        else
        {
            temp->data = 2;
            twoCount--;
        }
        temp = temp->next;
    }
    return head;
}