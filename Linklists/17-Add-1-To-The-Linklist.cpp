#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data1, Node *next1 = nullptr)
    {
        data = data1;
        next = next1;
    }
};

Node *reverse(Node *head)
{
    Node *prev = nullptr;
    Node *current = head;
    Node *next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev; // New head of the reversed list
}

Node *addOne(Node *head)
{
    // Step 1: Reverse the linked list
    head = reverse(head); // REVIEW -
    Node *temp = head;
    int carry = 1; // REVIEW -  keep it one !

    // Step 2: Traverse and add 1
    while (temp != nullptr)
    {
        temp->data += carry;

        if (temp->data < 10)
        {
            carry = 0;
            break; // No further carry propagation needed
        }
        else
        {
            temp->data = 0; // REVIEW -
            carry = 1;
        }

        if (carry == 1 && temp->next == nullptr)
        {
            temp->next = new Node(1);
            // REVIEW temp->next which is head->next
            carry = 0;
        }

        temp = temp->next;
    }

    // Step 3: Reverse the list back to original order
    head = reverse(head);
    return head;
}