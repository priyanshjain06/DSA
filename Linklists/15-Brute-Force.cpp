// NOTE Problem Statement: Given a linked list, sort its nodes based on the data value in them. Return the head of the sorted linked list.

// ANCHOR -  Time Complexity is : O(nlogn) and space Complexity is O(n)

#include <iostream>
#include <vector>
#include <algorithm>
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
Node *sortLL(Node *head)
{
    vector<int> arr;
    Node *temp = head;

    while (temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    sort(arr.begin(), arr.end());

    temp = head;
    int i = 0;

    while (temp != NULL)
    {
        temp->data = arr[i];
        temp = temp->next;
        i++;
    }

    return head;
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
    // Linked List: 3 2 5 4 1
    Node *head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(5);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(1);

    cout << "Original Linked List: ";
    printLinkedList(head);

    head = sortLL(head);

    cout << "Sorted Linked List: ";
    printLinkedList(head);

    return 0;
}
