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

// Function to reverse the linked list
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

// Function to add 1 to the linked list
Node *addOne(Node *head)
{
    // Step 1: Reverse the linked list
    head = reverse(head); // REVIEW -
    Node *temp = head;
    int carry = 1;

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

        // If carry remains and we are at the last node, create a new node
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

// Function to print the linked list
void printList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // Creating a linked list: 9 -> 9 -> 9
    Node *head = new Node(9);
    head->next = new Node(9);
    head->next->next = new Node(9);

    cout << "Original list: ";
    printList(head);

    head = addOne(head);

    cout << "List after adding 1: ";
    printList(head);

    return 0;
}
