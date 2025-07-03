// NOTE Check if the given Linked List is Palindrome

// ANCHOR : Time Complexity : O(n) and Space Complexity : O(1)

// LINK -  A palidrome is a word or sentence that's spelled the same way both forward and backward, ignoring punctuation, case, and spacing.  Example mom or dad.

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

Node *reverseLinkedList(Node *head) // REVIEW
{
    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL)
    {
        Node *forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

bool isPalindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }

    Node *slow = head;
    Node *fast = head;

    // Traverse the linked list to find the middle
    while (fast->next != NULL && fast->next->next != NULL)
    // REVIEW - fist is for odd case and second is for even case
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *newHead = reverseLinkedList(slow->next);
    // REVIEW -  slow -> next is start of other half

    Node *first = head;

    Node *second = newHead;

    while (second != NULL) // first ! = null
    {

        if (first->data != second->data) // if not equal
        {
            reverseLinkedList(newHead); // reverse to retain original arr
            return false;
        }

        first = first->next;

        second = second->next;
    }

    reverseLinkedList(newHead);

    return true;
}

// Function to print the linked list
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
    // values 1, 5, 2, 5, and 1 (15251, a palindrome)
    Node *head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(1);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Check if the linked list is a palindrome
    if (isPalindrome(head))
    {
        cout << "The linked list is a palindrome." << endl;
    }
    else
    {
        cout << "The linked list is not a palindrome." << endl;
    }
    return 0;
}
