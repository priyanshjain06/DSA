// ANCHOR Time Complexity is : O(2n) and space Complexity is O(n)
#include <iostream>
#include <stack> //REVIEW -
using namespace std;

class Node
{
public:
    int data;

    Node *next;

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *reverseLinkedList(Node *head) // REVIEW -  see function return type
{

    Node *temp = head;

    stack<int> st;

    // Step 1: Push the values of the
    // linked list onto the stack
    while (temp != nullptr)
    {
        // Push the current node's
        // data onto the stack
        st.push(temp->data);

        // Move to the next node
        // in the linked list
        temp = temp->next;
    }

    // Reset the temporary pointer to
    // the head of the linked list
    temp = head; // REVIEW -

    // Step 2: Pop values from the stack
    // and update the linked list
    while (temp != nullptr)
    {
        // Set the current node's data to
        // the value at the top of the stack
        temp->data = st.top();

        st.pop();

        // Move to the next node
        // in the linked list
        temp = temp->next;
    }
    return head; // REVIEW -
}

void printLinkedList(Node *head)
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
    // Create a linked list with
    // values 1, 3, 2, and 4
    Node *head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);

    cout << "Original Linked List: ";
    printLinkedList(head);

    head = reverseLinkedList(head);

    cout << "Reversed Linked List: ";
    printLinkedList(head);

    return 0;
}
