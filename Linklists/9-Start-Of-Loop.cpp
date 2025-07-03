// NOTE - Problem Statement: Given the head of a linked list that may contain a cycle, return the starting point of that cycle. If there is no cycle in the linked list return null.

// ANCHOR  Time complexity : O(n) and space complexity : O(1)

#include <iostream>
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

Node *firstNode(Node *head)
{
 
    Node *slow = head;
    Node *fast = head;

    // Phase 1: Detect the loop
    while (fast != NULL && fast->next != NULL)
    {

        slow = slow->next;

        fast = fast->next->next;

        // If slow and fast meet,
        // a loop is detected
        if (slow == fast)
        {

            // Reset the slow pointer
            // to the head of the list
            slow = head; //REVIEW 

            // Phase 2: Find the first node of the loop
            while (slow != fast)
            {

                // Move slow and fast one step
                // at a time
                slow = slow->next;
                fast = fast->next;

                // When slow and fast meet again,
                // it's the first node of the loop
            }

            // Return the first node of the loop
            return slow; //REVIEW - 
        }
    }

    // If no loop is found, return NULL
    return NULL; //REVIEW - 
}

int main()
{
    // Create a sample linked list with a loop
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    node1->next = node2;
    Node *node3 = new Node(3);
    node2->next = node3;
    Node *node4 = new Node(4);
    node3->next = node4;
    Node *node5 = new Node(5);
    node4->next = node5;

    // Make a loop from node5 to node2
    node5->next = node2;

    // Set the head of the linked list
    Node *head = node1;

    // Detect the loop in the linked list
    Node *loopStartNode = firstNode(head);

    if (loopStartNode)
    {
        cout << "Loop detected. Starting node of the loop is: " << loopStartNode->data << endl;
    }
    else
    {
        cout << "No loop detected in the linked list." << endl;
    }

    return 0;
}