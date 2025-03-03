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
    Node *forward = NULL; // REVIEW -
    Node *prev = NULL;

    int count = 0; // REVIEW -

    // Reverse first 'k' nodes
    while (curr != NULL && count < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++; // REVIEW -
    }

    // Step 2: Recur for remaining nodes
    if (forward != NULL) // or curr!=NULL
    {
        head->next = kReverse(forward, k); // REVIEW -
    }

    // Step 3: Return 'prev' which is the new head of the reversed portion
    return prev; // REVIEW -
}
// Function to print the linked list
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
int main()
{
    // Creating a linked list
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    cout << "Original List: ";
    printList(head);

    int k = 2; // Set the size of k for k-reverse
    Node *newHead = kReverse(head, k);

    cout << "Reversed List in Groups of " << k << ": ";
    printList(newHead);

    return 0;
}