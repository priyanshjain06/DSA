// NOTE Check if the given Linked List is Palindrome

// ANCHOR : Time Complexity : O(n) and Space Complexity : O(n)

// LINK -  A palidrome is a word or sentence that's spelled the same way both forward and backward, ignoring punctuation, case, and spacing.  Example mom or dad.

#include <iostream>
#include <stack>
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

bool isPalindrome(Node *head)
{
    stack<int> st;

    Node *temp = head;

    while (temp != NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;

    while (temp != NULL)
    {
        if (temp->data != st.top()) //REVIEW - 
        {
            return false;
        }

        st.pop();

        temp = temp->next;
    }

    return true;
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
    // values 1, 5, 2, 5, and 1 (15251, a palindrome)
    Node *head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(1);

    cout << "Original Linked List: ";
    printLinkedList(head);

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
