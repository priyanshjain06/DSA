// ANCHOR -  Time complexity is o(n ^2) andd space complexity is O(1)
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
        this->next = nullptr;
    }
};

void removeDuplicates(Node *head)
{
    Node *current = head; //REVIEW - 

    // Outer loop to pick each node one by one
    while (current != nullptr && current->next != nullptr)
    {
        Node *prev = current; //REVIEW - 
        Node *temp = current->next; //REVIEW - 

        // Inner loop to check all subsequent nodes for duplicates
        while (temp != nullptr)
        {
            if (current->data == temp->data) 
            {
                // Duplicate found, remove the node
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
            else
            {
                // No duplicate, move to the next node
                prev = temp;
                temp = temp->next;
            }
        }
        current = current->next; //REVIEW - 
    }
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    // Creating a sample unsorted linked list: 10 -> 12 -> 11 -> 11 -> 12 -> 10 -> NULL
    Node *head = new Node(10);
    head->next = new Node(12);
    head->next->next = new Node(11);
    head->next->next->next = new Node(11);
    head->next->next->next->next = new Node(12);
    head->next->next->next->next->next = new Node(10);

    cout << "Original List: ";
    printList(head);

    // Remove duplicates from the unsorted linked list
    removeDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}
