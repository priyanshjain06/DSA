#include <iostream>
using namespace std;

class Solution
{
public:
    Node *insertAtEnd(Node *head, int x)
    {
        Node *newNode = new Node(x);

        if (head == nullptr)
            return newNode;
    }

    Node *temp = head;
    while (temp->next != nullptr) // REVIEW no last node traversed
    {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
};
