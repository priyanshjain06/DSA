#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

void doubleNthFromEnd(Node *head, int N)
{
    Node *fast = head;
    Node *slow = head;

    // Move fast N steps ahead
    for (int i = 0; i < N; i++)
    {
        if (fast == nullptr)
            return; // N is larger than length
        fast = fast->next;
    }

    // Move both pointers until fast reaches the end
    while (fast != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }

    // slow now points to the Nth node from the end
    slow->data *= 2;
}

// Utility function to print the list
void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Build the list: 1 -> 3 -> 7 -> 9 -> 5 -> 2
    Node *head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(7);
    head->next->next->next = new Node(9);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(2);

    int N = 3;
    doubleNthFromEnd(head, N);

    cout << "Updated Linked List: ";
    printList(head);

    return 0;
}
