#include <iostream>
using namespace std;

class Solution
{
public:
    Node *insertAtEnd(Node *head, int x)
    {
        Node *newNode = new Node(x);

        if (head == nullptr)
        { // If the list is empty, new node becomes head
            return newNode;
        }

        Node *temp = head;
        while (temp->next != nullptr)
        { // Traverse to the last node
            temp = temp->next;
        }

        temp->next = newNode; // Append the new node at the end
        return head;
    }
};
