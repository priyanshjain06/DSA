// ANCHOR  Time Complexity is : O(n) and space Complexity is O(1)
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    // Default value for next pointer
    Node(int data1, Node *next1 = nullptr)
    {
        data = data1;
        next = next1;
    }
};

Node *kReverse(Node *head, int k)
{
    // Step 1: reverse the first 'k' nodes
    if (head == NULL || head->next == NULL) // REVIEW -
        return NULL;

    Node *curr = head;
    Node *forward = NULL; // REVIEW
    Node *prev = NULL;

    int count = 0; // REVIEW -

    while (curr != NULL && count < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++; // REVIEW -
    }

    if (forward != NULL) // or curr!=NULL
    {
        head->next = kReverse(forward, k); // REVIEW -
    }

    return prev; // REVIEW -
}

void printList(Node *head) // REVIEW -
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
