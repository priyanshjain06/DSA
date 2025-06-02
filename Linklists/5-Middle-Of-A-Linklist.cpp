// NOTE Problem Statement: Given the head of a linked list of integers, determine the middle node of the linked list. However, if the linked list has an even number of nodes, return the second middle node.

// ANCHOR - time complexity O(N) and space complexity O(1)

#include <iostream>
#include <map>

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

Node *findMiddle(Node *head)
{

    Node *slow = head;

    Node *fast = head;

    // Traverse the linked list using the
    // Tortoise and Hare algorithm. //REVIEW

    // NOTE fast is not NULL → so fast->next is safe to access.
    // fast->next is not NULL → so fast->next->next is safe to access in the next move.
    
    while (fast != NULL && fast->next != NULL)
    {
        // Move slow one step.
        slow = slow->next;
        // Move fast two steps.
        fast = fast->next->next;
    }

    return slow; // REVIEW -
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node *middleNode = findMiddle(head);

    cout << "The middle node value is: " << middleNode->data << endl;

    return 0;
}