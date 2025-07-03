// ANCHOR :- Time Complexity : O(n) and  Space Complexity : O(1)
// LINK the concept we are using we will avoid using extra two variables .

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;
    Node(int data1, Node *next1, Node *back1) // REVIEW
    {
        data = data1;
        next = next1;
        back = back1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};


Node *convertArr2DLL(vector<int> arr)
{
    Node *head = new Node(arr[0]); // REVIEW -

    Node *prev = head; // REVIEW

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev);
        // Update the 'next' pointer of the
        // previous node to point to
        // the new node
        prev->next = temp;
        // Move 'prev' to the newly created
        // node for the next iteration
        prev = temp;
    }
    // Return the head of the doubly linked list
    return head;
}

// Function to print the elements
// of the doubly linked list
void print(Node *head)
{
    while (head != nullptr)
    {
        // Print the data in the tail node
        cout << head->data << " ";
        // Move to the next node
        head = head->next;
    }
}

// Function to reverse a doubly linked list
// In-place link exchange method
Node *reverseDLL(Node *head)
{

    // Check if the list is empty
    // or has only one node
    if (head == NULL || head->next == NULL)
    {
        // No change is needed;
        // return the current head
        return head;
    }

    // Initialize a pointer to
    // the previous node
    Node *prev = NULL;

    // Initialize a pointer to
    // the current node
    Node *current = head;

    // Traverse the linked list
    while (current != NULL)
    {
        // Store a reference to
        // the previous node
        prev = current->back;

        // Swap the previous and
        // next pointers
        current->back = current->next;

        // This step reverses the links
        current->next = prev; 

        // Move to the next node
        // in the original list
        current = current->back;
    }

    // The final node in the original list
    // becomes the new head after reversal
    return prev->back; // REVIEW
}