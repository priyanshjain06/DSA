// NOTE Problem Statement: Given the head of a linked list, rotate the list to the right by k places.

// REVIEW - remember we will right rotate the list by k times . It is given in the question

// ANCHOR - Time Complexity: O(length of list) + O(length of list - (length of list%k))
//  Space Complexity: O(1)

#include <iostream>
#include <map>
using namespace std;

class node
{
public:
    int num;
    node *next;
    node(int a)
    {
        num = a;
        next = NULL;
    }
};

// utility function to insert node at the end of the list :

void insertNode(node *&head, int val)
{
    node *newNode = new node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    
    node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return;
}

// utility function to rotate list by k times
node *rotateRight(node *head, int k)
{
    if (head == NULL || head->next == NULL || k == 0) // REVIEW -
        return head;

    node *temp = head;
    int length = 1; // REVIEW - 1 se start hoga

    // calculate the length of the list
    while (temp->next != NULL)
    {
        ++length;
        temp = temp->next;
    }

    // link last node to first node
    temp->next = head;
    k = k % length;
    int end = length - k; // to get end of the list
    while (end--)
        temp = temp->next;
    head = temp->next;
    temp->next = NULL; // REVIEW -

    return head;
}

// utility function to print list
void printList(node *head)
{
    while (head->next != NULL)
    {
        cout << head->num << "->";
        head = head->next;
    }
    cout << head->num << endl;
    return;
}

int main()
{
    node *head = NULL;
    // inserting Node
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 5);

    cout << "Original list: ";
    printList(head);

    int k = 2;
    node *newHead = rotateRight(head, k); // calling function for rotating right of the nodes by k times

    cout << "After " << k << " iterations: ";
    printList(newHead); // list after rotating nodes
    return 0;
}