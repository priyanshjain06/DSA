// ANCHOR :- TIME Complexity : O(n) and  Space Complexity : O(1)

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

Node *uniqueSortedList(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *curr = head;

    while (curr != NULL)
    {

        if ((curr->next != NULL) && curr->data == curr->next->data)
        {
            Node *forward = curr->next->next; //REVIEW - 
            Node *nodeToDelete = curr->next; //REVIEW - 
            delete (nodeToDelete);
            curr->next = forward;
        }
        else
        {
            curr = curr->next;
        }
    }

    return head;
}