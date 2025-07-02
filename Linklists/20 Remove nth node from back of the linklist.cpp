#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data1, Node *next1 = nullptr) // REVIEW -
    {
        data = data1;
        next = next1;
    }
};

Node *deleteNthFromEnd(Node *head, int N)
{
    Node *fast = head, *slow = head;

    // Move fast pointer N steps ahead
    for (int i = 0; i < N; i++)
    {
        fast = fast->next;
    }

    // If fast is NULL, remove the head node
    if (!fast)
        return head->next;

    // Move both pointers until fast reaches the last node
    while (fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }

    // Delete the Nth node from the end
    Node *toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;

    return head;
}

int main()
{
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node *head = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5)))));

    int N = 3; // Remove 3rd node from end

    head = deleteNthFromEnd(head, N);

    return 0;
}
